import gc								#garbage collector to evade memory leaks
import time   							#importing time to know time
from machine import I2C, Pin, PWM		#importing communication
from micropython_bmi270 import bmi270	#importing provided IMU Driver library
import machine							#importing machine

""" Initializing I2C """
i2c = I2C(scl='P0_2', sda='P0_3') 


""" Initialising IMU """
def IMU_Config () :
    print ("IMU Configuring........")
    global bmi; bmi = bmi270.BMI270(i2c)
    bmi.acceleration_range = bmi270.ACCEL_RANGE_2G
    print ("IMU Configured Succesfully")

""" Configuring PWM Pins for driver board """
def PWM_Config ():
    print("Configuring PWM...")
    PIN_DIR_1     = 'P9_0'  # Connected to OUT1 on driver
    PIN_DIR_2     = 'P9_1'  # Connected to OUT2 on driver

    """ Setup the Direction Pins as standard Digital Outputs """
    PWM_DUTY = 0
    PWM_FREQ = 1000
    global dir_pin1;
    dir_pin1 = PWM(Pin(PIN_DIR_1), duty_u16=PWM_DUTY, freq=PWM_FREQ)
    global dir_pin2;
    dir_pin2 = PWM(Pin(PIN_DIR_2), duty_u16=PWM_DUTY, freq=PWM_FREQ)
    print ("PWM Configured Succesfully")


""" Defining Basic Control Functions """
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
    """ Coast Braking """
    dir_pin1.duty_u16(0)
    dir_pin2.duty_u16(0)
    print("Motor Stopped")

def Motor_Hard_Break():
    """ Hard Braking. stops instantly. """
    dir_pin1.duty_u16(65535)
    dir_pin2.duty_u16(65535)
    print("Motor Hard Braking")

import deepcraft_model  #Importing model
import array            #Importing arrays

def Intialize_Model ():
    print("Initializing Model....")
    global IMAI_DATA_OUT_SYMBOLS; IMAI_DATA_OUT_SYMBOLS = ['unlabelled', 'imbalance', 'working', 'impact']
    global model; model = deepcraft_model.DEEPCRAFT()
    model.init()
    global input_dim; input_dim = model.get_model_input_dim()
    global output_dim; output_dim = model.get_model_output_dim()
    print (f"input_dim = {input_dim}; output_dim = {output_dim}")
    print("Model Initialized Succesfuly")
    
    """Placing  all Config function in one spot"""
def Init_and_Config () :
    print ("Configuring the Device...")
    IMU_Config();
    PWM_Config ()
    Intialize_Model();
    print("Device Configured Succesfully")
    
#1. prediction rate is 10 hz. windows is  [20, 6]
#we need to give 20 sets of 6 values every 0.1 seconds
# so 200 hz sampling is needed

SAMPLING_FREQ = 200 
INTERVAL_US = 1000000 // SAMPLING_FREQ  # 100000 us (1s)


""" Allocating arrays for input and output of the model"""
input_buffer = array.array('f', [0.0] * input_dim)
output_buffer = array.array('f', [0.0] * output_dim)

next_sample_time = 0
"""Functioj to fill Input window of model and retrieve status"""
def Get_Status():

    global next_sample_time
    
    """loop to give 20 bathes of 6 values"""
    for i in range(0, 20):
        """ writing down  when next sample should start"""
        next_sample_time = time.ticks_add(time.ticks_us(), INTERVAL_US)
        a = bmi.acceleration
        g = bmi.gyro
        
        input_buffer[0] = a[0]
        input_buffer[1] = a[1]
        input_buffer[2] = a[2]
        input_buffer[3] = g[0]
        input_buffer[4] = g[1]
        input_buffer[5] = g[2]
        

        model.enqueue(input_buffer) 
        
        """ Wating what is left for next sample to begin"""
        time.sleep_us(time.ticks_diff(next_sample_time, time.ticks_us()))

    """ 6. Force clean the memory to prevent memory leaks
        garbage collector is not really fast (cleans up every 100 ms?)
        so fast allocation of small things could cause memory leak"""
    gc.collect()
    output_status = model.dequeue(output_buffer)
    
    
    # Fast manual check for most 
    m = 0 											#Unlabled
    if output_buffer[1] > output_buffer[m]: m = 1	#Imbalance
    if output_buffer[2] > output_buffer[m]: m = 2	#Working
    if output_buffer[3] > output_buffer[m]: m = 3	#Impact

    return m


    
def main():
    print("Starting Main Program...")
    Motor_Set_Speed(100) # Spinning motor with 100%
    time.sleep(4)        # waiting for the motor to reach steady state
    count = 0
    """starting loop"""
    for i in range (0, 10000) :
        #time.sleep_ms(1000)
        #print("Free RAM:", gc.mem_free())
        status = Get_Status()
        count += 1
            
        if status == 3 : #impact
            Motor_Hard_Break()
            print("Motor HIT something")
            print("EMERGENCY STOP")
            break
        """reducing amount of frequent printing with simple counter
           (to prevent buffer overflow)""" 
        elif count > 13 : 
            count = 0
            if status == 0 : #unlabled
                print("Motor is NOT spinnig")
            elif status == 1 : #imbalanced
                #Motor_Stop()
                print("Motor is UNBALANCED")
                #print("Stopping the Motor")
            elif status == 2 :
                print("Motor is working normally")
                
    print ("Main Program Ended. Press USER to Restart Main Program or Press RESET to Reset")   

"""Configruing interrupt that call Main Program"""
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
    print("Free RAM:", gc.mem_free())
    while 3 > 2 :
        """busy waiting for main program start"""
        pass