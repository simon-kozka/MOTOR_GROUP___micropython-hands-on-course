# MicroPython Deployment Folder

This folder contains all resources used for deploying the IMU motor detection model on a MicroPython-enabled device.

## Contents

- **MicroPython script** – The script used to run the model on the device.  
- **Deployed model (`.mpy`)** – The generated MicroPython model file.  
- **Firmware** – Recompiled firmware integrating RMS and FFT Energy filters for IMU data. (Firmware was flashed with ModusToolbox Programmer 5.7)

> **Note:** MicroPython’s computing power is very limited, so the firmware was modified to handle filter computations efficiently.

## Firmware Integration

To integrate the filters, the following `.c` and `.h` files were added to the main project under `ports/psoc6`:

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
