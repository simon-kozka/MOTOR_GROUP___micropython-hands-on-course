print("Device Booted Succesfully.")
print("Press the Button to start a Program")

import gc
import time
from machine import I2C, Pin, PWM
from micropython_bmi270 import bmi270
import machine

#Initializing I2C
i2c = I2C(scl='P0_2', sda='P0_3') 

#Initialising IMU
bmi = bmi270.BMI270(i2c)
#print(gc.mem_free() - a)

#Mic Config code taken from Material Detection Exmaple
def Mic_Config () :

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
def Set_Speed (speed) :
    if (speed < 0) :
        duty = int((-speed // 100) * 65535)
        dir_pin1.duty_u16(duty)
        dir_pin2.duty_u16(0)
        print("Motor Spin Clockwise")
        return;
    if (speed > 0) :
        duty = int((speed // 100) * 65535)
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

# Complex Routines
def Motor_Self_Clean () :
    for i in range (0, 3) :
        Set_Speed(50);
        time.sleep_ms(2000);
        Motor_Stop()
        time.sleep_ms(2000);
        Set_Speed(-50);
        time.sleep_ms(2000);
        Motor_Stop();
        time.sleep_ms(2000);


import deepcraft_model
import array

def Intialize_Model ():
    global IMAI_DATA_OUT_SYMBOLS; IMAI_DATA_OUT_SYMBOLS = ['unlabelled', 'working', 'impact', 'imbalance']
    global model; model = deepcraft_model.DEEPCRAFT()
    model.init()
    global input_dim; input_dim = model.get_model_input_dim()
    global output_dim; output_dim = model.get_model_output_dim()

def Get_Status () :
    return 4


def main():
    Intialize_Model ()
    PWM_Config ()
    machine.freq(machine.AUDIO_PDM_24_576_000_HZ)
    for i in range (0, 10) :
        time.sleep_ms(1000)
        status = Get_Status()
        if status == 0 : #unlabled
            print("Motor is NOT spinnig")
        if status == 1 :
            print("Motor is working normally")
        if status == 2 : #impact
            print("Motor HIT something")
        if status == 3 : #imbalanced
            print("Motor is UNBALANCED")
            print("Stopping the Motor")
        if status == 4 : #blocked
            print("Motor is BLOCKED")
            print("Starting Cleaning Routine")
            Motor_Self_Clean()
            if(Get_Status() == 4) :
                print("Cleaning FAILED\nStopping the Motor")
        if status == 5 :
                print("ERROR : UNKNOWN STATUS LABEL")
            
    output_buffer = array.array('f', [0.0] * len(IMAI_DATA_OUT_SYMBOLS))
    print(output_buffer)


if __name__ == "__main__":
    main()
    Stop_Motor()



