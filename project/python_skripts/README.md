# IMU Data Processing Scripts

This repository contains Python scripts for processing and preparing IMU (Inertial Measurement Unit) data, specifically focused on impact detection and session management. Below is a description of each script:

## Scripts

### `change_deepcraft_sessionFiles.py`
- **Purpose:** Edit `.imsession` files.  
- **Use case:** Simplify session files by keeping only one track and renaming tracks as needed.

### `filterIMUData_light2.py`
- **Purpose:** Apply filters to raw IMU data.  
- **Features:**  
  - RMS filtering  
  - FFT Energy filtering with sliding window

### `generate_augmented_data2.py`
- **Purpose:** Generate augmented IMU data.  
- **Use case:** Create IMU data files with multiple impacts from existing impact segments.

### `removeBadImpacts.py`
- **Purpose:** Remove low-amplitude impacts.  
- **Benefit:** Ensures that only distinguishable impacts are used for prediction models.

### `removeOverextendingLabel.py`
- **Purpose:** Trim labels that extend outside the actual data range.  
- **Function:** Checks the start and end of labels and adjusts them if necessary.

### `extractImpacts.py`
- **Purpose:** Extract impacts from IMU data.  
- **Use case:** Identify and segment impacts based on labeled regions within the data.