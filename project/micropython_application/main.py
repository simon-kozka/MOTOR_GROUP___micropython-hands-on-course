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
    PIN_PWM_SPEED = 'P9_0'  # Connected to PWMA on driver
    PIN_DIR_1     = 'P9_1'  # Connected to AIN1 on driver
    PIN_DIR_2     = 'P9_2'  # Connected to AIN2 on driver

    # Setup the Direction Pins as standard Digital Outputs
    global dir_pin1; dir_pin1 = Pin(PIN_DIR_1, Pin.OUT)
    global dir_pin2; dir_pin2 = Pin(PIN_DIR_2, Pin.OUT)

    # Setup the Speed Pin as PWM
    PWM_DUTY = 0
    global speed_pwm; speed_pwm = PWM(Pin(PIN_PWM_SPEED), duty_u16=PWM_DUTY, freq=1000)
    speed_pwm.freq(1000) # 1 kHz is good for TT motors

# Defining Basic Control Functions
def stop_motor():
    """Stops the motor gradually."""
    dir_pin1.value(0)
    dir_pin2.value(0)
    speed_pwm.duty_u16(0)
    print("Motor Stopped")

def Hard_Break_Motor():
    """Hard Braking. stops instantly."""
    dir_pin1.value(1)
    dir_pin2.value(1)
    speed_pwm.duty_u16(0)
    print("Motor Hard Braking")

def move_motor(speed, direction):
    """
    :param speed: 0 to 65535
    :param direction: 'forward' or 'backward'
    """
    # reasuring the boandary
    if speed > 65535: speed = 65535
    if speed < 0: speed = 0

    # Set the speed
    speed_pwm.duty_u16(speed)

    # Set the direction
    if direction == 'forward':
        dir_pin1.value(1) # HIGH
        dir_pin2.value(0) # LOW
        print(f"Forward at speed {speed}")
        
    elif direction == 'backward':
        dir_pin1.value(0) # LOW
        dir_pin2.value(1) # HIGH
        print(f"Backward at speed {speed}")
# Complex Routines
def Clean_Motor () :
    for i in range (0, 3) :
        move_motor(20000, 'forward')
        time.sleep(1)    
        move_motor(20000, 'backward')
        time.sleep(1)


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
            Clean_Motor()
            if(Get_Status() == 4) :
                print("Cleaning FAILED\nStopping the Motor")
        if status == 5 :
                print("ERROR : UNKNOWN STATUS LABEL")
            
    output_buffer = array.array('f', [0.0] * len(IMAI_DATA_OUT_SYMBOLS))
    print(output_buffer)


if __name__ == "__main__":
    main()



