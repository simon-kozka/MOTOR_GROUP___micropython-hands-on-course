import os
import pandas as pd
import numpy as np
import re

# ====== SETTINGS ======
folder_path = "combined_impacts"
amplitude_threshold = 3.5   # <-- adjust this value
# ======================


def calculate_amplitude(file_path):
    df = pd.read_csv(file_path)

    # Ensure required columns exist
    if not {'x', 'y', 'z'}.issubset(df.columns):
        print(f"Skipping {file_path} (missing columns)")
        return None

    # Compute magnitude
    magnitude = np.sqrt(df['x']**2 + df['y']**2 + df['z']**2)

    # Peak-to-peak amplitude
    amplitude = magnitude.max() - magnitude.min()

    return amplitude


# Step 1: Collect files
files = [f for f in os.listdir(folder_path) if f.startswith("impact_") and f.endswith(".csv")]

# Sort by number
files.sort(key=lambda x: int(re.findall(r'\d+', x)[0]))

kept_files = []

# Step 2: Filter low amplitude files
for file in files:
    full_path = os.path.join(folder_path, file)
    amplitude = calculate_amplitude(full_path)

    if amplitude is None:
        continue

    print(f"{file} → Amplitude: {amplitude:.3f}")

    if amplitude >= amplitude_threshold:
        kept_files.append(file)
    else:
        print(f"Removing {file} (low amplitude)")
        os.remove(full_path)

# Step 3: Rename remaining files sequentially
print("\nRearranging file numbers...")

kept_files.sort(key=lambda x: int(re.findall(r'\d+', x)[0]))

for new_index, old_file in enumerate(kept_files):
    old_path = os.path.join(folder_path, old_file)
    new_name = f"impact_{new_index}.csv"
    new_path = os.path.join(folder_path, new_name)

    if old_file != new_name:
        os.rename(old_path, new_path)

print("Done ✅")
