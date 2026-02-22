import time
import array
from machine import I2C, Pin
from micropython_bmi270 import bmi270
import feature_extraction
import deepcraft_model1


# -----------------------------
# IMU Initialization
# -----------------------------
i2c = I2C(scl='P0_2', sda='P0_3', freq=400000)
bmi = bmi270.BMI270(i2c)
time.sleep(1)

print("BMI270 IMU Initialized successfully!")


# -----------------------------
# Model Initialization
# -----------------------------
label_text = ['unlabelled', 'imbalance', 'working', 'impact']

model = deepcraft_model1.DEEPCRAFT()
model.init()

data_out = array.array('f', [0.0] * 4)
model_input = array.array('f', [0.0] * 2)   # PRE-ALLOCATED


# -----------------------------
# Feature Extraction / Filter
# -----------------------------
sampling_rate = 400
window_size = 20
highpass_cutoff = 10

hpf = feature_extraction.init_high_pass_filter(
    highpass_cutoff,
    sampling_rate
)

window = []


# -----------------------------
# Main Loop
# -----------------------------
while True:
    try:
        ax, ay, az = bmi.acceleration
        magnitude = (ax*ax + ay*ay + az*az) ** 0.5
        filtered_mag = feature_extraction.filter_high_pass(hpf, magnitude)

        window.append(filtered_mag)
        if len(window) > window_size:
            window.pop(0)

        if len(window) == window_size:

            rms, energy = feature_extraction.compute_features(window)

            # reuse buffer (no new allocation)
            model_input[0] = rms
            model_input[1] = energy

            model.enqueue(model_input)
            model.dequeue(data_out)

            # Manual max (NO lambda)
            m = 0
            if data_out[1] > data_out[m]: m = 1
            if data_out[2] > data_out[m]: m = 2
            if data_out[3] > data_out[m]: m = 3

            # -------- PRINT IN PLACE --------
            print("\rStatus: " + label_text[m] + "        ", end="")

        time.sleep(1 / sampling_rate)

    except KeyboardInterrupt:
        print("\nStopping data read.")
        break

    except Exception as e:
        print("\nError:", e)
        time.sleep(0.1)
