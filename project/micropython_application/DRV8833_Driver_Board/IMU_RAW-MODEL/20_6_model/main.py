#skript to test if IMU model works

print("Device Booted Succesfully.")

import gc
import time
from machine import I2C, Pin, PWM
import machine
from machine import PDM_PCM, freq, AUDIO_PDM_24_576_000_HZ

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
        accx, accy, accz = [0, i/100, 0]
        gyrox, gyroy, gyroz = [1, 2, 3/(i + 1)]
        #print("loading batch...")
        model.enqueue(array.array('f', [accx, accy, accz, gyrox, gyroy, gyroz]));
        #print(f"batch loaded {i}")
        output_status = model.dequeue(output_buffer)
        print(output_status)
        if(output_status == 0) :
            print(output_buffer)
            
    

    return 4


def main():
    Intialize_Model();
    time.sleep(2)
    Get_Status();
            



if __name__ == "__main__":
    main()
    print("program stopped")




