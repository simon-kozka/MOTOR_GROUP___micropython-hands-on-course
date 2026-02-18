import os
import numpy as np
import pandas as pd
from scipy.signal import butter, filtfilt, find_peaks
from numpy.fft import rfft, rfftfreq

# --- Parameters ---
sampling_rate = 400          # IMU sampling rate in Hz
window_size_s = 0.05         # 50 ms window
window_size = int(window_size_s * sampling_rate)
highpass_cutoff = 10         # Hz for high-pass filter

# --- High-pass filter ---
def highpass_filter(signal, cutoff, fs, order=4):
    b, a = butter(order, cutoff / (fs / 2), btype='high')
    return filtfilt(b, a, signal)

# --- Feature calculation ---
def compute_features(window, fs):
    rms = np.sqrt(np.mean(window**2))
    peak = np.max(np.abs(window))
    crest_factor = peak / rms if rms != 0 else 0
    fft_vals = np.abs(rfft(window))
    total_fft_energy = np.sum(fft_vals**2)
    return rms, crest_factor, total_fft_energy

# --- Process one file ---
def process_file(file_path):
    # Read CSV skipping first line
    df = pd.read_csv(file_path, skiprows=1, names=['time', 'x', 'y', 'z'])
    
    # Compute magnitude
    magnitude = np.sqrt(df['x']**2 + df['y']**2 + df['z']**2)
    
    # High-pass filter
    filtered = highpass_filter(magnitude, highpass_cutoff, sampling_rate)
    
    times = []
    rms_list = []
    crest_list = []
    fft_list = []

    half_win = window_size // 2
    # Sliding window
    for i in range(half_win, len(filtered) - half_win):
        window = filtered[i - half_win:i + half_win]
        rms, crest, total_fft = compute_features(window, sampling_rate)
        times.append(df['time'].iloc[i])
        rms_list.append(rms)
        crest_list.append(crest)
        fft_list.append(total_fft)
    
    # Overwrite the file with features and new header
    out_df = pd.DataFrame({
        'time': times,
        'rms': rms_list,
        'crest_factor': crest_list,
        'total_fft_energy': fft_list
    })
    
    with open(file_path, 'w') as f:
        # always write this new header once
        f.write('time,rms,crest_factor,total_fft_energy\n')
        out_df.to_csv(f, index=False, header=False, float_format='%.8f')


# --- Process all sessions ---
base_dir = '.'  # adjust to folder containing session folders
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
