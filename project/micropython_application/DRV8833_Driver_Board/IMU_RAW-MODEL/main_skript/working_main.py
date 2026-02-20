import gc
import time
from machine import I2C, Pin, PWM
from micropython_bmi270 import bmi270
import machine
from machine import PDM_PCM, freq, AUDIO_PDM_24_576_000_HZ

#Initializing I2C
i2c = I2C(scl='P0_2', sda='P0_3') 




#Initialising IMU
def IMU_Config () :
    global bmi; bmi = bmi270.BMI270(i2c)
    bmi.acceleration_range = bmi270.ACCEL_RANGE_2G

#print(gc.mem_free() - a)

#Mic Config code taken from Material Detection Exmaple
def Mic_Config () :
    freq(AUDIO_PDM_24_576_000_HZ)
    SAMPLE_RATE_HZ = 16000  # Desired sample rate in Hz
    AUDIO_BUFFER_SIZE = 512  # Size of the audio buffer
    global AUDIO_BITS_PER_SAMPLE; AUDIO_BITS_PER_SAMPLE = 16  # Dynamic range in bits
    MICROPHONE_GAIN = 12  # Microphone gain setting(best prediction observed at 12)
    DIGITAL_BOOST_FACTOR = 50.0  # Digital boost factor for input signal
    IMAI_DATA_OUT_SYMBOLS = ["unlabelled", "air", "plastic", "plastic_out", "wood", "wood_out"]

    # PDM_PCM configuration
    clk_pin = "P10_4"
    data_pin = "P10_5"
    rx_buf = array.array('h', [0] * AUDIO_BUFFER_SIZE)
    
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





# --- Configuration ---
def PWM_Config ():
    PIN_DIR_1     = 'P9_0'  # Connected to OUT1 on driver
    PIN_DIR_2     = 'P9_1'  # Connected to OUT2 on driver

    # Setup the Direction Pins as standard Digital Outputs
    PWM_DUTY = 0
    PWM_FREQ = 1000
    global dir_pin1; dir_pin1 = PWM(Pin(PIN_DIR_1), duty_u16=PWM_DUTY, freq=PWM_FREQ)
    global dir_pin2; dir_pin2 = PWM(Pin(PIN_DIR_2), duty_u16=PWM_DUTY, freq=PWM_FREQ)


# Defining Basic Control Functions
def Motor_Set_Speed (speed) :
    if (speed <= 0 and speed >= -100) :
        duty = int((-speed * 65535) / 100)
        dir_pin1.duty_u16(duty)
        dir_pin2.duty_u16(0)
        print("Motor Spin Clockwise")
        return;
    if (speed >= 0 and speed <= 100) :
        duty = int((speed * 65535) / 100)
        dir_pin1.duty_u16(0)
        dir_pin2.duty_u16(duty)
        print("Motor Spin CounterClockwise")
        return;
    
    dir_pin1.duty_u16(0)
    dir_pin2.duty_u16(0)
    print("ERROR : Illegal speed given")
        
def Motor_Stop():
    dir_pin1.duty_u16(0)
    dir_pin2.duty_u16(0)
    print("Motor Stopped")

def Motor_Hard_Break():
    """Hard Braking. stops instantly."""
    dir_pin1.duty_u16(1)
    dir_pin2.duty_u16(1)
    print("Motor Hard Braking")

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
def Get_Status () :
    print("Getting current status...")
    SAMPLING_FREQ = 200 
    INTERVAL_US = 100000 // SAMPLING_FREQ  # 100000 us (0.1s)
    for i in range (0, 20) :
        next_sample_time = time.ticks_add(time.ticks_us(), INTERVAL_US)
        start_tick = time.ticks_us()
        accx, accy, accz = bmi.acceleration
        gyrox, gyroy, gyroz = bmi.gyro
        #print([accx, accy, accz, gyrox, gyroy, gyroz])
        model.enqueue(array.array('f', [accx, accy, accz, gyrox, gyroy, gyroz]));
        #print("data : ", [accx, accy, accz, gyrox, gyroy, gyroz])
        while time.ticks_diff(next_sample_time, time.ticks_us()) > 0:
            pass
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
    IMU_Config();
    PWM_Config ()
    machine.freq(machine.AUDIO_PDM_24_576_000_HZ)
    Intialize_Model();
    print("Device Configured Succesfully")
    
def main():
    print("Starting Main Program...")
    Motor_Set_Speed(100)
    time.sleep(5)
    
    for i in range (0, 10000) :
        #time.sleep_ms(1000)
        status = Get_Status()
        if status == 0 : #unlabled
            print("Motor is NOT spinnig")
        elif status == 1 : #imbalanced
            Motor_Stop()
            print("Motor is UNBALANCED")
            print("Stopping the Motor")
        elif status == 2 :
            print("Motor is working normally")
        elif status == 3 : #impact
            Motor_Hard_Break()
            print("Motor HIT something")
            print("EMERGENCY STOP")
            break
        else :
                print("ERROR : UNKNOWN STATUS LABEL")
    print ("Main Program Ended. Press USER to SystemExit Program again or Press RESET to Reset")   

user_button = Pin('P5_2', Pin.IN, Pin.PULL_UP)
is_running = 0
def USER_Button_handler(pin):
    main()

# Attach the interrupt: trigger when the button is pressed (falling edge)
user_button.irq(trigger=Pin.IRQ_FALLING, handler=USER_Button_handler)

if __name__ == "__main__":
    print("Device Booted Succesfully.")
    Init_and_Config()
    print("Press USER to start the Main Program")
    while 3 > 2 :
        pass
