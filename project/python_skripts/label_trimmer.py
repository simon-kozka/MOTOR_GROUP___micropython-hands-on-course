import os
import numpy as np

def correct_labels(file_path):
    try:
        # 1. Read lines and filter out empty ones
        with open(file_path, 'r', encoding='utf-8') as f:
            lines = [line.strip() for line in f.readlines() if line.strip()]

        if len(lines) <= 1:
            return  # Empty file or header only

        header = lines[0]
        
        # 2. Parse data and handle "imbalace" rename immediately
        raw_rows = []
        for line in lines[1:]:
            parts = line.split(',')
            while len(parts) < 5: 
                parts.append("")
            
            # Standardization
            label_name = parts[2].strip().lower()
            if label_name == 'imbalace':
                parts[2] = 'impact'
            
            raw_rows.append(parts[:5])

        # 3. Load into Numpy and Sort by Time
        # Columns: 0:Time, 1:Length, 2:Label, 3:Confidence, 4:Comment
        data = np.array(raw_rows, dtype=object)
        times = data[:, 0].astype(float)
        lengths = data[:, 1].astype(float)
        labels = data[:, 2]
        conf = data[:, 3]
        comm = data[:, 4]

        # Sort indices by start time to ensure logical processing
        sort_idx = np.argsort(times)
        times, lengths, labels, conf, comm = times[sort_idx], lengths[sort_idx], labels[sort_idx], conf[sort_idx], comm[sort_idx]

        # 4. Correct Overlaps with priority logic
        # We use a standard range loop because modifications to one row can affect the next
        for i in range(len(times) - 1):
            # Skip labels already marked for deletion (length <= 0)
            if lengths[i] <= 0:
                continue

            current_start = times[i]
            current_end = current_start + lengths[i]
            next_start = times[i+1]
            
            # Capture the end of the next label before we potentially move its start
            next_end = next_start + lengths[i+1]

            if current_end > next_start:
                curr_label = str(labels[i]).lower()

                if curr_label == 'impact':
                    # RULE: Impact takes priority. Trim the START of the NEXT label.
                    # Move next start to the end of current impact
                    new_next_start = current_end
                    times[i+1] = new_next_start
                    # Recalculate next length based on its original end point
                    lengths[i+1] = next_end - new_next_start
                
                elif curr_label == 'working':
                    # RULE: Working is secondary. Trim the END of the CURRENT label.
                    # Current working label must end when the next one starts
                    lengths[i] = next_start - current_start

        # 5. Filter out labels with length <= 0 (Deletes them)
        valid_mask = lengths > 0
        times = times[valid_mask]
        lengths = lengths[valid_mask]
        labels = labels[valid_mask]
        conf = conf[valid_mask]
        comm = comm[valid_mask]

        # 6. Save corrected data
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(header + '\n')
            for i in range(len(times)):
                row = [
                    f"{times[i]:.7f}", 
                    f"{lengths[i]:.7f}", 
                    str(labels[i]), 
                    str(conf[i]), 
                    str(comm[i])
                ]
                f.write(",".join(row) + '\n')

        print(f"Successfully processed: {os.path.basename(file_path)}")

    except Exception as e:
        print(f"ERROR processing {file_path}: {e}")

def run_process(target_folder):
    print(f"Scanning directory: {target_folder}")
    if not os.path.exists(target_folder):
        print("Error: Target path not found.")
        return

    count = 0
    for root, _, files in os.walk(target_folder):
        for file in files:
            if file.endswith('.label'):
                correct_labels(os.path.join(root, file))
                count += 1
    print(f"\nFinished. Processed {count} files.")

if __name__ == '__main__':
    # RELATIVE PATH: 
    # From 'pythonkript' folder, go up '..'
    # Then down into 'deepcraft_workspace/Artem_Recording_Both/impact'
    RELATIVE_PATH = os.path.join('..', 'deepcraft_workspace', 'Artem_Recording_Both', 'impact')
    
    script_dir = os.path.dirname(os.path.abspath(__file__))
    data_dir = os.path.abspath(os.path.join(script_dir, RELATIVE_PATH))

    run_process(data_dir)