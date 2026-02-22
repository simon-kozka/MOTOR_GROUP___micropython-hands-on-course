# Motor Condition Classification Project Report  
**Platform:** DeepCraft Studio  
**Sensor:** IMU (Accelerometer only)  
**Sampling Rate:** 400 Hz  

---

## 1. Objective  

The goal of this project was to develop a classification model capable of detecting and distinguishing between the following motor states:

- Motor Stop (unlabeled / idle baseline)  
- Motor Working  
- Motor Unbalanced  
- Motor Impact  

The system was designed for deployment on embedded hardware, requiring efficient preprocessing and firmware-level signal filtering.

---

## 2. Data Acquisition  

### 2.1 Sensor Configuration  

- Sensor type: IMU (Accelerometer only)  
- Sampling frequency: **400 Hz**  
- Data type: Raw acceleration (X, Y, Z axes)  
- No filtering applied during acquisition  

The data was collected in raw format to preserve full signal fidelity for offline processing and feature engineering.

---

## 3. Data Augmentation  

### 3.1 Motivation  

Motor impacts were:

- Short in duration  
- Rare compared to other operating states  

This caused class imbalance and insufficient representation during training.

---

### 3.2 Impact Augmentation Strategy  

1. Extracted impact segments from recorded data  
2. Created an impact pool (~200 samples)  
3. Randomly selected impact samples  
4. Superimposed impacts onto "motor working" samples  
5. Applied varying amplitude scaling factors  

This approach:

- Increased class representation  
- Simulated realistic impact events  
- Preserved natural motor background vibration  

The script for augmentation can be found in:

`main-dir/project/python_skripts/generate_augmented_data2.py`

---

## 4. Signal Processing Pipeline  

The following processing steps were applied to raw acceleration data:

---

### 4.1 Magnitude Computation  

Acceleration magnitude was computed to reduce dimensionality from 3 axes to 1 signal:

a_mag(n) = sqrt( ax(n)^2 + ay(n)^2 + az(n)^2 )

Where:  
- ax(n), ay(n), az(n) are acceleration samples along X, Y, Z axes  

This removes orientation dependency and simplifies feature extraction.

---

### 4.2 High-Pass Filtering (10 Hz)  

Cutoff frequency:

f_c = 10 Hz  

Purpose:

- Remove gravity component (~0 Hz)  
- Remove low-frequency drift  
- Preserve vibration-related components  

---

### 4.3 Sliding Window  

Window size:

N = 20 samples  

At 400 Hz sampling rate:

Window duration = 20 / 400 = 0.05 seconds  

This short window captures transient events like impacts effectively.

---

### 4.4 Feature Extraction  

Two features were computed per window:

---

#### 4.4.1 Root Mean Square (RMS)  

RMS measures signal energy in the time domain:

RMS = sqrt( (1/N) * Σ(x_i^2) )

Where:  
- x_i = filtered magnitude samples  
- N = window size (20 samples)  

RMS is sensitive to vibration amplitude and impact intensity.

---

#### 4.4.2 FFT Energy  

Let:

X(k) = FFT( x(n) )

Total spectral energy:

E_FFT = Σ |X(k)|^2  

Where:  
- K = number of frequency bins  
- |X(k)| = magnitude of FFT bin  

FFT energy captures changes in vibration frequency content (e.g., imbalance signatures).

---

The filtering script can be found in:

`main-dir/project/python_skripts/filterIMUData_light2.py`

Other scripts used in this project are located in the same directory. See the `README.md` file for more information about each script.

---

### Feature Calculation Code (Python Reference)

```python
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
```

**Challenge:**  
The main challenge was ensuring that the filters were bit-by-bit identical to the filters deployed on the MCU in C.

---

## 5. Model Training (DeepCraft Studio)  

### 5.1 Project Type  

Classification Project  

---

### 5.2 Preprocessing (Inside DeepCraft)  

- Sliding window: **0.25 seconds**  
- Prediction frequency: **5 Hz**  
- Balanced dataset  
- Medium-sized model architecture  

Note: Only windowing was used as a preprocessor inside DeepCraft, since filtering and feature computation were performed externally.

---

## 6. Deployment Considerations  

### 6.1 Embedded Constraints  

- Target device running MicroPython  
- Limited computational resources  
- Python-only implementation insufficient for real-time processing  

---

### 6.2 Firmware-Level Optimization  

To meet performance requirements:

- Signal filters implemented in C  
- High-pass filter and feature computations optimized  
- Exposed to MicroPython via wrapper interface  
- Real-time processing achieved  

Architecture:

IMU  
→ C Filters  
→ Feature Computation  
→ MicroPython  
→ Model Inference  

---

## 7. System Architecture Overview  

### Offline (Training)

Raw IMU (400 Hz)  
↓  
Magnitude  
↓  
High-pass Filter (10 Hz)  
↓  
Sliding Window (20 samples)  
↓  
RMS + FFT Energy  
↓  
DeepCraft Model Training  

---

### Online (Deployment)

IMU  
↓  
C-Implemented Filters  
↓  
MicroPython Wrapper  
↓  
DeepCraft Model Inference  
↓  
Motor State Classification  

---

## 8. MicroPython Deployment Folder  

The MicroPython deployment folder can be found in:

`main-dir/project/micropython_application/Mihai_presentation`

This folder contains all resources used for deploying the IMU motor detection model on a MicroPython-enabled device.

### Contents

- **MicroPython script** – Script used to run the model on the device  
- **Deployed model (`.mpy`)** – Generated MicroPython model file  
- **Firmware** – Recompiled firmware integrating RMS and FFT Energy filters for IMU data  

(Firmware was flashed using ModusToolbox Programmer 5.7.)

> **Note:** MicroPython’s computing power is very limited, so the firmware was modified to handle filter computations efficiently.

---

### Firmware Integration  

Building from source is required for this step. The following link shows the necessary preparations:

https://github.com/Infineon/micropython/tree/ports-psoc6-main/examples/usercimaimodule/imagimob

To integrate the filters, the following `.c` and `.h` files were added to the main project under:

`ports/psoc6`

- `feature_extraction.c`  
- `highpass_filter.c`  
- `mp_feature_extraction.c`  

Additionally, the Makefile was updated to include these sources:

```makefile
MOD_SRC_C += \
    ... \
    feature_extraction.c \
    highpass_filter.c \
    mp_feature_extraction.c
```

---

### C Code Snippet Used for Feature Extraction

```c
#include "feature_extraction.h"
#include <math.h>

void computeFeatures(float* window, size_t window_size, float* rms, float* energy) {
    float sq_sum = 0.0f;

    for (size_t i = 0; i < window_size; i++) {
        sq_sum += window[i] * window[i];
    }

    *rms = sqrtf(sq_sum / (float)window_size);
    *energy = (float)window_size * sq_sum / 2.0f;
}
```

---

## 9. Conclusion  

The project successfully implemented a real-time embedded motor condition classification system capable of detecting:

- Normal operation  
- Unbalanced behavior  
- Impact events  
- Motor stop state  

Key success factors:

- Targeted impact augmentation  
- Efficient feature engineering  
- Embedded C optimization  

The system is computationally efficient and suitable for deployment on constrained embedded platforms.