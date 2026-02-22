import time, array, sys, struct, gc
from machine import I2C, PDM_PCM, freq, AUDIO_PDM_24_576_000_HZ
from micropython_bmi270 import bmi270

# --- CONFIG ---
SAMPLE_RATE_HZ = 16000
AUDIO_BUFFER_SIZE = 512 
RECORD_TIME_MS = 20000

# --- HARDWARE ---
i2c = I2C(scl='P0_2', sda='P0_3') 
bmi = bmi270.BMI270(i2c)
audio_buffer = array.array('h', [0] * AUDIO_BUFFER_SIZE)
freq(AUDIO_PDM_24_576_000_HZ)
pdm_pcm = PDM_PCM(0, sck="P10_4", data="P10_5", sample_rate=SAMPLE_RATE_HZ, 
                  decimation_rate=64, bits=PDM_PCM.BITS_16, 
                  format=PDM_PCM.MONO_LEFT, left_gain=12)
pdm_pcm.init()

def start_streaming():
    gc.collect()
    
    # IMPORTANT: Wait for PC to send 'G' (Go)
    # This prevents the board from hanging on a full USB buffer
    while True:
        if sys.stdin.read(1) == 'G':
            break
    
    start_time = time.ticks_ms()
    deadline = time.ticks_add(start_time, RECORD_TIME_MS)
    sync_header = b'\xAA' 
    
    while time.ticks_diff(deadline, time.ticks_ms()) > 0:
        pdm_pcm.readinto(audio_buffer)
        accel = bmi.acceleration
        gyro = bmi.gyro
        
        imu_bytes = struct.pack('<ffffff', accel[0], accel[1], accel[2], gyro[0], gyro[1], gyro[2])
        
        # Write to buffer (Total 1049 bytes)
        sys.stdout.buffer.write(sync_header)
        sys.stdout.buffer.write(imu_bytes)
        sys.stdout.buffer.write(audio_buffer)

    # Small delay to ensure last packet clears before exit
    time.sleep(0.5)

start_streaming()