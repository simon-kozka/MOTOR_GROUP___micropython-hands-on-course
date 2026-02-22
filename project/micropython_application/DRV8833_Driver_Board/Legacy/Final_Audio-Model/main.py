import gc
import time
from machine import I2C, Pin, PWM
import machine
from machine import PDM_PCM, freq, AUDIO_PDM_24_576_000_HZ

#print(gc.mem_free() - a)

#Mic Config code taken from Material Detection Exmaple
def Mic_Config () :
    freq(AUDIO_PDM_24_576_000_HZ)
    SAMPLE_RATE_HZ = 16000  # Desired sample rate in Hz
    AUDIO_BUFFER_SIZE = 512  # Size of the audio buffer
    global AUDIO_BITS_PER_SAMPLE; AUDIO_BITS_PER_SAMPLE = 16  # Dynamic range in bits
    MICROPHONE_GAIN = 10  # Microphone gain setting(best prediction observed at 12)
    global DIGITAL_BOOST_FACTOR; DIGITAL_BOOST_FACTOR = 50.0  # Digital boost factor for input signal
    
    
    
    # PDM_PCM configuration
    clk_pin = "P10_4"
    data_pin = "P10_5"
    global rx_buf;  rx_buf = array.array('h', [0] * AUDIO_BUFFER_SIZE)

    print("PDM initializing....")
    global pdm_pcm; pdm_pcm = PDM_PCM(
        0,
        sck=clk_pin,
        data=data_pin,
        sample_rate=SAMPLE_RATE_HZ,
        decimation_rate=64,
        bits=PDM_PCM.BITS_16,
        format=PDM_PCM.MONO_LEFT,
        left_gain=MICROPHONE_GAIN,
        right_gain=MICROPHONE_GAIN,
    )
    pdm_pcm.init()
    print("PDM initialized successfully")

# Function to normalize sample into range [-1, 1]
def sample_normalize(sample):
    return sample / float(1 << (AUDIO_BITS_PER_SAMPLE - 1))



import deepcraft_model
import array

def Intialize_Model ():
    print("Initializing Model....")
    global IMAI_DATA_OUT_SYMBOLS; IMAI_DATA_OUT_SYMBOLS = ['unlabelled', 'imbalance', 'working', 'impact']
    global model; model = deepcraft_model.DEEPCRAFT()
    model.init()
    global input_dim; input_dim = model.get_model_input_dim()
    global output_dim; output_dim = model.get_model_output_dim()
    print (f"input_dim = {input_dim}; output_dim = {output_dim}")
    global output_buffer; output_buffer = array.array('f', [0.0] * len(IMAI_DATA_OUT_SYMBOLS))
    print("Model Initialized Succesfuly")
    

#1. prediction rate is 10 hz. with [20, 6] window, 200 hz sampling is needed
#


input_buffer = array.array('f', [0.0] * 6)
next_sample_time = 0
def Get_Status():
    # 2. Local "Cache" of the sensor methods (Faster lookup)
    global next_sample_time
    for i in range(20):
        # 3. This creates a tuple (Temporary garbage, but small)
        next_sample_time = time.ticks_add(time.ticks_us(), INTERVAL_US)
        a = bmi.acceleration
        g = bmi.gyro
        
        # 4. Fill the pre-allocated buffer (Zero new RAM used here!)
        input_buffer[0] = a[0]
        input_buffer[1] = a[1]
        input_buffer[2] = a[2]
        input_buffer[3] = g[0]
        input_buffer[4] = g[1]
        input_buffer[5] = g[2]
        
        # 5. Enqueue the SAME buffer
        model.enqueue(input_buffer) 
        
        time.sleep_us(time.ticks_diff(next_sample_time, time.ticks_us()))

    # 6. Force clean the sensor tuples after the loop
    gc.collect()
    output_status = model.dequeue(output_buffer)
    
    #print("labels : ", output_buffer)
    # Ultra-fast manual check for 4 elements
    m = 0
    if output_buffer[1] > output_buffer[m]: m = 1
    if output_buffer[2] > output_buffer[m]: m = 2
    if output_buffer[3] > output_buffer[m]: m = 3
    # m is now the index of the maximum float
    return m

def Init_and_Config () :
    print ("Configuring the Device...")
    machine.freq(machine.AUDIO_PDM_24_576_000_HZ)
    Intialize_Model();
    Mic_Config()
    print("Device Configured Succesfully")
count = 0  
def main():
    print("Starting Main Program...")
    global count
    for i in range (0, 1000):
        
        num = pdm_pcm.readinto(rx_buf)

        sample_max = 0.0
        audio_count = num // 2

        for i in range(audio_count):
        
            # Get sample from rx_buf
            raw_sample = rx_buf[i]

            # Normalize the sample to range [-1, 1]
            #normalized_sample = sample_normalize(raw_sample)

            # Apply digital boost factor
            #boosted_sample = normalized_sample 

            # Pass the boosted sample to the model
            result = model.enqueue([raw_sample])

            #sample_abs = abs(boosted_sample)
            #if sample_abs > sample_max:
                #sample_max = sample_abs

            # Check if there is any model output to process
            output_status = model.dequeue(output_buffer)
            if output_status == 0:
                count += 1
                if True:
                    #count = 0
                    m = 0
                
                    if output_buffer[1] > output_buffer[m]: m = 1
                    if output_buffer[2] > output_buffer[m]: m = 2
                    if output_buffer[3] > output_buffer[m]: m = 3

                
                    print(m, count, output_buffer)
        
        gc.collect()


if __name__ == "__main__":
    print("Device Booted Succesfully.")
    Init_and_Config()
    print("Press USER to start the Main Program")
    print("Free RAM:", gc.mem_free())
    main()
