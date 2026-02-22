import os
import numpy as np
import pandas as pd
import math
import struct

# -----------------------------
# Parameters (force float32)
# -----------------------------
sampling_rate = np.float32(400.0)
window_size_s = np.float32(0.05)
window_size = int(window_size_s * sampling_rate)  # 20 samples
highpass_cutoff = np.float32(10.0)
warmup_samples = 40
half_window = window_size // 2


# -----------------------------
# High-Pass Filter (C bit-match)
# -----------------------------
class HighPassFilter:
    def __init__(self, cutoff, fs):
        cutoff = np.float32(cutoff)
        fs = np.float32(fs)

        rc = np.float32(1.0) / (
            np.float32(2.0) * np.float32(math.pi) * cutoff
        )
        dt = np.float32(1.0) / fs

        self.alpha = np.float32(rc / (rc + dt))
        self.prev = np.float32(0.0)
        self.prev_filt = np.float32(0.0)

    def filter(self, x):
        x = np.float32(x)

        y = np.float32(
            self.alpha * np.float32(
                self.prev_filt + np.float32(x - self.prev)
            )
        )

        self.prev = x
        self.prev_filt = y

        return y


# -----------------------------
# Feature calculation (C bit-match)
# -----------------------------
def compute_features(window):
    sq_sum = np.float32(0.0)

    # manual accumulation (same as C loop)
    for v in window:
        v = np.float32(v)
        sq_sum = np.float32(sq_sum + np.float32(v * v))

    n = np.float32(len(window))

    rms = np.float32(
        np.sqrt(np.float32(sq_sum / n), dtype=np.float32)
    )

    total_energy = np.float32(
        (n * sq_sum) / np.float32(2.0)
    )

    return rms, total_energy


# -----------------------------
# Process a single file
# -----------------------------
def process_file(file_path):
    df = pd.read_csv(file_path, skiprows=1, names=['time', 'x', 'y', 'z'])

    # Convert to float32 immediately
    x_vals = df['x'].astype(np.float32).values
    y_vals = df['y'].astype(np.float32).values
    z_vals = df['z'].astype(np.float32).values
    time_vals = df['time'].values  # keep original time precision

    # Magnitude (force float32 math)
    magnitude = []
    for i in range(len(x_vals)):
        x = np.float32(x_vals[i])
        y = np.float32(y_vals[i])
        z = np.float32(z_vals[i])

        mag = np.float32(
            np.sqrt(
                np.float32(
                    x * x + y * y + z * z
                ),
                dtype=np.float32
            )
        )

        magnitude.append(mag)

    # Initialize filter
    hpf = HighPassFilter(highpass_cutoff, sampling_rate)

    # Warmup
    for i in range(min(warmup_samples, len(magnitude))):
        hpf.filter(magnitude[i])

    # Filter entire signal
    filtered = []
    for val in magnitude:
        filtered.append(hpf.filter(val))

    times = []
    rms_list = []
    energy_list = []

    # -----------------------------
    # Centered sliding window
    # -----------------------------
    for i in range(half_window, len(filtered) - half_window):
        window = filtered[i - half_window : i + half_window]

        rms, total_energy = compute_features(window)

        times.append(time_vals[i])
        rms_list.append(rms)
        energy_list.append(total_energy)

    # Save features
    out_df = pd.DataFrame({
        'time': times,
        'rms': rms_list,
        'total_fft_energy': energy_list
    })

    with open(file_path, 'w') as f:
        f.write('time,rms,total_fft_energy\n')
        out_df.to_csv(f, index=False, header=False, float_format='%.8f')


# -----------------------------
# Process all folders
# -----------------------------
base_dir = '.'

for root, dirs, files in os.walk(base_dir):
    for file in files:
        if file.endswith('IMU-Data.data'):
            file_path = os.path.join(root, file)
            print(f'Processing {file_path}')
            try:
                process_file(file_path)
            except Exception as e:
                print(f'Skipping {file_path}, error: {e}')

print("All sessions processed ✅")