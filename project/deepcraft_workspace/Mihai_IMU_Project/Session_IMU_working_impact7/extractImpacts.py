import pandas as pd
import numpy as np
import os

# ===== FILES =====
imu_file = "IMU-Data.data"
label_file = "Live-Labeling.label"
output_folder = "extracted_impacts"
impact_label_name = "impact"

# Padding in seconds (adds context)
padding_before = 0.05
padding_after = 0.05
# ==================

os.makedirs(output_folder, exist_ok=True)

# Load IMU data (skip comment line)
imu = pd.read_csv(imu_file, comment='#', header=None)
imu.columns = ["time", "x", "y", "z"]

# Estimate sample rate automatically
dt = np.mean(np.diff(imu["time"]))
sample_rate = 1.0 / dt
print(f"Estimated sample rate: {sample_rate:.2f} Hz")

# Load labels
labels = pd.read_csv(label_file)

impact_count = 0

for _, row in labels.iterrows():
    if row["Label(string)"] == impact_label_name:
        
        start_time = row["Time(Seconds)"] - padding_before
        end_time = row["Time(Seconds)"] + row["Length(Seconds)"] + padding_after
        
        # Clamp to valid range
        start_time = max(start_time, imu["time"].min())
        end_time = min(end_time, imu["time"].max())
        
        # Extract segment
        segment = imu[(imu["time"] >= start_time) & (imu["time"] <= end_time)]
        
        if len(segment) > 0:
            filename = os.path.join(output_folder, f"impact_{impact_count}.csv")
            segment.to_csv(filename, index=False)
            impact_count += 1

print(f"Extracted {impact_count} impact segments.")
