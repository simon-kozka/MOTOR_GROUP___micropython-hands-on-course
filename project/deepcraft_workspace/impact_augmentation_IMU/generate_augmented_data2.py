import pandas as pd
import numpy as np
import os
import random

# ===== CONFIG =====
working_file = "random_working_segment.csv"
impact_folder = "combined_impacts"
output_data_file  = "IMU-Data.data"
output_label_file = "Live-Labeling.label"

num_segments = 360              # number of segments to concatenate
num_impacts_per_segment = 3    # impacts per segment
scale_range = (0.95, 1.2)       # scaling for impacts
label_gap = 0.005              # minimum gap between labels
working_min_length = 0.5       # random working segment min length
working_max_length = 0.8       # random working segment max length
# ==================

# Load original working segment and remove duplicates
working_orig = pd.read_csv(working_file).drop_duplicates(subset=["time"]).reset_index(drop=True)
working_orig["time"] = working_orig["time"] - working_orig["time"].iloc[0]

# Load pool of impacts
impact_files = [
    os.path.join(impact_folder, f)
    for f in os.listdir(impact_folder)
    if f.endswith(".csv")
]

all_data = []
all_labels = []
current_time_offset = 0.0

# ===== Generate segments with impacts =====
for seg_idx in range(num_segments):

    # Pick random working segment length
    segment_length = random.uniform(working_min_length, working_max_length)

    working = working_orig[working_orig["time"] <= segment_length].copy()
    working_duration = working["time"].iloc[-1]

    augmented = working.copy()
    impact_labels = []

    # ===== Insert impacts (NON-OVERLAPPING GUARANTEED) =====
    inserted_impacts = []  # store (start, end) of full impact regions

    for _ in range(num_impacts_per_segment):

        impact_file = random.choice(impact_files)
        impact = pd.read_csv(impact_file).copy()
        impact["time"] = impact["time"] - impact["time"].iloc[0]

        # Remove DC offset and scale
        for axis in ["x", "y", "z"]:
            impact[axis] -= impact[axis].mean()
            impact[axis] *= random.uniform(*scale_range)

        impact_length = impact["time"].iloc[-1]

        max_attempts = 50
        placed = False

        for _attempt in range(max_attempts):

            if working_duration <= impact_length:
                break

            insert_time = random.uniform(0, working_duration - impact_length)
            new_start = insert_time
            new_end = insert_time + impact_length

            # Check overlap with existing impacts (including label_gap)
            overlap = False
            for (s, e) in inserted_impacts:
                if not (new_end + label_gap <= s or new_start - label_gap >= e):
                    overlap = True
                    break

            if not overlap:
                placed = True
                break

        if not placed:
            continue  # skip if cannot place without overlap

        impact_shifted = impact.copy()
        impact_shifted["time"] += new_start

        # Merge impact into working signal
        for axis in ["x", "y", "z"]:
            mask = (
                (augmented["time"] >= impact_shifted["time"].iloc[0]) &
                (augmented["time"] <= impact_shifted["time"].iloc[-1])
            )
            if mask.sum() > 0:
                interp_vals = np.interp(
                    augmented.loc[mask, "time"],
                    impact_shifted["time"],
                    impact_shifted[axis]
                )
                augmented.loc[mask, axis] += interp_vals

        # Shrink label safely
        shrink = min(0.05, impact_length / 2)

        label_start = new_start + shrink
        label_length = impact_length - 2 * shrink

        impact_labels.append([
            label_start,
            label_length,
            "impact",
            1,
            "synthetic"
        ])

        # Track FULL region for collision detection
        inserted_impacts.append((new_start, new_end))

    # ===== Split working labels around impacts =====
    working_labels = []
    impact_labels_sorted = sorted(impact_labels, key=lambda x: x[0])

    prev_end = 0.0
    for imp in impact_labels_sorted:
        start, length = imp[0], imp[1]
        if start - prev_end > 0:
            working_labels.append([
                prev_end,
                start - prev_end,
                "working",
                1,
                "synthetic"
            ])
        prev_end = start + length

    if working_duration - prev_end > 0:
        working_labels.append([
            prev_end,
            working_duration - prev_end,
            "working",
            1,
            "synthetic"
        ])

    # Shift labels by global time offset
    for lbl in working_labels + impact_labels_sorted:
        lbl[0] += current_time_offset

    # Shift data
    augmented["time"] += current_time_offset

    all_data.append(augmented)
    all_labels.extend(working_labels + impact_labels_sorted)

    current_time_offset += working_duration

# ===== Enforce gaps between WORKING labels only =====
all_labels_sorted = sorted(all_labels, key=lambda x: x[0])
adjusted_labels = []

for i, lbl in enumerate(all_labels_sorted):

    start, length, label_type, confidence, comment = lbl
    end = start + length

    if label_type == "working":

        if i > 0:
            prev_start, prev_length, _, _, _ = all_labels_sorted[i-1]
            prev_end = prev_start + prev_length
            if start < prev_end + label_gap:
                shift = prev_end + label_gap - start
                start += shift
                length -= shift

        if i < len(all_labels_sorted) - 1:
            next_start, _, _, _, _ = all_labels_sorted[i+1]
            max_end = next_start - label_gap
            if end > max_end:
                length -= (end - max_end)

        if length <= 0:
            continue

    adjusted_labels.append([start, length, label_type, confidence, comment])

all_labels = adjusted_labels

# ===== Minimal start/end gap =====
track_start = 0.0
track_end = all_labels[-1][0] + all_labels[-1][1]

# First label
first_label = all_labels[0]
if first_label[2] == "working" and first_label[0] < track_start + label_gap:
    shift = track_start + label_gap - first_label[0]
    first_label[0] += shift
    first_label[1] = max(0.0, first_label[1] - shift)
    if first_label[1] <= 0:
        all_labels.pop(0)

# Last label
last_label = all_labels[-1]
last_end = last_label[0] + last_label[1]
if last_label[2] == "working" and last_end > track_end - label_gap:
    last_label[1] = max(0.0, last_label[1] - (last_end - (track_end - label_gap)))
    if last_label[1] <= 0:
        all_labels.pop(-1)

# ===== Combine data and enforce strictly increasing timestamps =====
final_data = pd.concat(all_data, ignore_index=True)\
               .sort_values("time")\
               .reset_index(drop=True)

N = len(final_data)
t_min = final_data["time"].iloc[0]
t_max = final_data["time"].iloc[-1]
final_data["time"] = np.linspace(t_min, t_max, N)

# ===== Save outputs =====
final_data.to_csv(output_data_file, index=False, float_format="%.8f")
print(f"Saved augmented IMU data -> {output_data_file}")

label_df = pd.DataFrame(
    all_labels,
    columns=[
        "Time(Seconds)",
        "Length(Seconds)",
        "Label(string)",
        "Confidence(double)",
        "Comment(string)"
    ]
)

label_df.to_csv(output_label_file, index=False, float_format="%.9f")
print(f"Saved label file -> {output_label_file}")
