import os
import pandas as pd

# Root folder containing all session folders
root_folder = r'.'

for folder_name in os.listdir(root_folder):
    folder_path = os.path.join(root_folder, folder_name)
    if not os.path.isdir(folder_path):
        continue

    label_file = os.path.join(folder_path, 'Live-Labeling.label')
    imu_file = os.path.join(folder_path, 'IMU-Data.data')

    if not os.path.exists(label_file) or not os.path.exists(imu_file):
        print(f"Skipping {folder_name}, missing files")
        continue

    try:
        # Read IMU data
        df_imu = pd.read_csv(imu_file)
        if df_imu.empty:
            print(f"Skipping {folder_name}, IMU data empty")
            continue
        first_time = df_imu['time'].iloc[0]
        last_time = df_imu['time'].iloc[-1]

        # Read label file
        df_label = pd.read_csv(label_file)
        if df_label.empty:
            print(f"Skipping {folder_name}, label data empty")
            continue

        # --- Check first label ---
        first_label_start = df_label['Time(Seconds)'].iloc[0]
        first_label_length = df_label['Length(Seconds)'].iloc[0]

        if first_label_start < first_time:
            new_start = first_time
            new_length = max(first_label_length - (first_time - first_label_start), 0.0)
            df_label.loc[df_label.index[0], 'Time(Seconds)'] = new_start
            df_label.loc[df_label.index[0], 'Length(Seconds)'] = new_length
            print(f"Adjusted first label in {folder_name}")

        # --- Check last label ---
        last_label_start = df_label['Time(Seconds)'].iloc[-1]
        last_label_length = df_label['Length(Seconds)'].iloc[-1]
        last_label_end = last_label_start + last_label_length

        if last_label_end > last_time:
            # Shorten last label only if it goes past last IMU timestamp
            new_length = last_label_length - (last_label_end - last_time)
            df_label.loc[df_label.index[-1], 'Length(Seconds)'] = max(new_length, 0.0)
            print(f"Adjusted last label in {folder_name}")

        # Save changes
        df_label.to_csv(label_file, index=False)

    except Exception as e:
        print(f"Error processing {folder_name}: {e}")
