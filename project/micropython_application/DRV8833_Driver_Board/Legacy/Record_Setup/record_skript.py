import gc
import time
import array
import machine
from machine import I2C, Pin, PWM
from micropython_bmi270 import bmi270

# --- Configuration ---
SAMPLE_RATE_HZ = 16000
AUDIO_BUFFER_SIZE = 512 # Number of audio samples per "packet"
MICROPHONE_GAIN = 12
BAUD_RATE = 921600 # High speed to prevent bottlenecks

# --- Initializing I2C & IMU ---
i2c = I2C(scl='P0_2', sda='P0_3') 
bmi = bmi270.BMI270(i2c)

# --- Initializing PDM Mic ---
# PDM_PCM configuration for PSoC 6 AI Kit
clk_pin = "P10_4"
data_pin = "P10_5"
audio_buffer = array.array('h', [0] * AUDIO_BUFFER_SIZE)

pdm_pcm = machine.PDM_PCM(
    0,
    sck=clk_pin,
    data=data_pin,
    sample_rate=SAMPLE_RATE_HZ,
    decimation_rate=64,
    bits=machine.PDM_PCM.BITS_16,
    format=machine.PDM_PCM.MONO_LEFT,
    left_gain=MICROPHONE_GAIN,
    right_gain=MICROPHONE_GAIN,
)
pdm_pcm.init()

# --- PWM Motor Config (From your snippet) ---
def PWM_Config():
    PIN_DIR_1 = 'P9_0'
    PIN_DIR_2 = 'P9_1'
    global dir_pin1, dir_pin2
    dir_pin1 = PWM(Pin(PIN_DIR_1), duty_u16=0, freq=1000)
    dir_pin2 = PWM(Pin(PIN_DIR_2), duty_u16=0, freq=1000)

def Set_Speed(speed):
    if speed < 0:
        duty = int((-speed * 65535) / 100)
        dir_pin1.duty_u16(duty); dir_pin2.duty_u16(0)
    else:
        duty = int((speed * 65535) / 100)
        dir_pin1.duty_u16(0); dir_pin2.duty_u16(duty)

# --- Data Collection Loop ---
def start_streaming():
    print("START_DATA") # Signal to laptop to start saving
    
    # Pre-fetch sensor objects to save time in loop
    accel = bmi.accel
    gyro = bmi.gyro
    
    while True:
        try:
            # 1. Read Audio Buffer (This blocks until buffer is full)
            # 512 samples at 16kHz takes ~32ms
            pdm_pcm.readinto(audio_buffer)
            
            # 2. Read IMU (Captured immediately after audio block)
            ax, ay, az = accel
            gx, gy, gz = gyro
            
            # 3. Output data in CSV format
            # We print the IMU values once per audio buffer to maintain sync
            # DeepCraft will interpolate the IMU data to match the audio rate
            
            # Format: mic_sample, acc_x, acc_y, acc_z, gyro_x, gyro_y, gyro_z
            # To maximize speed, we join the audio samples into a string
            imu_str = f"{ax},{ay},{az},{gx},{gy},{gz}"
            
            for sample in audio_buffer:
                # Optimized print: MicValue,Ax,Ay,Az,Gx,Gy,Gz
                print(f"{sample},{imu_str}")
                
        except KeyboardInterrupt:
            print("STOP_DATA")
            break

# Initialize PWM
PWM_Config()

# Run streaming
# Note: Ensure your Serial Monitor on PC is set to 921600 baud
start_streaming()