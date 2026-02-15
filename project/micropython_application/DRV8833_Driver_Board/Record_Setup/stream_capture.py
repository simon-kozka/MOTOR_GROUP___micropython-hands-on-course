import serial, struct, wave, time

PORT = 'COM3' # <--- Verify this!
AUDIO_FILE = "voice.wav"
IMU_FILE = "imu.data"
PACKET_SIZE = 1049 # 1 sync + 24 imu + 1024 audio

def capture():
    # Increase internal buffer size to 1MB to prevent data loss
    ser = serial.Serial(PORT, 115200, timeout=1)
    ser.set_buffer_size(rx_size=1048576) 
    
    print("Connecting... sending START signal.")
    time.sleep(1)
    ser.write(b'G') # Send 'G' to trigger the board
    
    wav = wave.open(AUDIO_FILE, 'wb')
    wav.setnchannels(1)
    wav.setsampwidth(2)
    wav.setframerate(16000)
    
    with open(IMU_FILE, "w") as imu_f:
        imu_f.write("# Time(s),Ax,Ay,Az,Gx,Gy,Gz\n")
        
        start_time = time.time()
        packets = 0
        
        try:
            while packets < (20 / 0.032): # roughly 20 seconds
                # Find Sync Byte
                if ser.read(1) != b'\xAA':
                    continue
                
                # Read Packet payload
                raw = ser.read(PACKET_SIZE - 1)
                if len(raw) < 1048: break
                
                # Unpack
                imu = struct.unpack('<ffffff', raw[:24])
                audio = raw[24:]
                
                # Save
                ts = packets * 0.032
                imu_f.write(f"{ts:.4f},{','.join(map(str, imu))}\n")
                wav.writeframes(audio)
                
                packets += 1
                if packets % 31 == 0: # Print approx every 1 second
                    print(f"Recorded {packets * 0.032:.1f}s / 20s", end='\r')

        except KeyboardInterrupt:
            print("\nStopped.")
        finally:
            wav.close()
            ser.close()
            print(f"\nDone! Saved {AUDIO_FILE} and {IMU_FILE}")

if __name__ == "__main__":
    capture()