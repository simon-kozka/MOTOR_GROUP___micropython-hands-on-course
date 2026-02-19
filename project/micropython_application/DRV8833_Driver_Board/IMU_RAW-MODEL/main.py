#skript to test if IMU model works

print("Device Booted Succesfully.")

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
    #global output_buffer; output_buffer = array.array('f', [0.0] * len(IMAI_DATA_OUT_SYMBOLS))
    print("Model Initialized Succesfuly")
    


def Get_Status () :
    print("Getting current status...")
    output_buffer = array.array('f', [0.0] * len(IMAI_DATA_OUT_SYMBOLS))
    for i in range (0, 2000) :
        accx, accy, accz = bmi.acceleration
        gyrox, gyroy, gyroz = bmi.gyro
        print("loading batch...")
        model.enqueue([accx, accy, accz, gyrox, gyroy, gyroz]);
        print(f"batch loaded {i}")
        output_status = model.dequeue(output_buffer)
        print(output_status)
        if(output_status == 0) :
            print(output_buffer)
            
    

    return 4


def main():
    IMU_Config();
    machine.freq(machine.AUDIO_PDM_24_576_000_HZ)
    Intialize_Model();
    Get_Status();
            



if __name__ == "__main__":
    main()
    print("program stopped")




