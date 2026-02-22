# Motor Condition Classification Project Report  
**Platform:** DeepCraft Studio  
**Sensor:** Microphone  
**Sampling Rate:** 16 kHz  

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

- Sensor type: Microphone 
- Sampling frequency: **16 kHz**  
- Data type: Raw PDM-PCM
- Gain: 10 dB
- Mode: Mono
- No filtering applied during data acquisition  

The data was collected in raw format to preserve full signal fidelity for offline processing and feature engineering.

---

## 3. Data Augmentation  

### 3.1 Motivation  

I did not have enough data for an accurate model and espcially impacts were underrepresented, because of:

- Short in duration  
- Rare compared to other operating states  
- Difficult labeling process

This caused class imbalance and insufficient representation during training that even label weighting could not fix.

---

### 3.2 Data Augmentation Strategy  

 - Using the built-in data augmentation feature in Deepcraft studio for adding both background noise and changing the volume
 
This approach:

- Increased class representation  
- Ensured adaptability in environments with a higher noise-floor   

---

## 4. Signal Preprocessing Pipeline  

The following preprocessing steps were applied to raw PDM-PCM data:

---

### 4.1 Sliding window (data points) 

Window shape = [512]
Stride = 120
Buffer Multiplier = 1 
Frequency = 133.33 Hz
Rate = 273.07 KB/s

Slices the audio signal into bigger temporal chunks

---

### 4.2 Hann smoothing  

Symmetric = True
Window shape = [512]
Frequency = 133.33 Hz
Rate = 273.07 KB/s

Smoothes out any inconsistency in the data

---

### 4.3 Real Discrete Fourier Transform 

Axis = 0 
Window shape = [257,2]
Frequency = 133.33 Hz
Rate = 274.13 KB/s

Conversion into the frequency domain

---

### 4.4 Frobenius norm  

Axis = 0 
Window shape = [257]
Frequency = 133.33 Hz
Rate = 137.07 KB/s

Extracts magnitude

---

#### 4.5 Mel Filterbank 

Number of filters = 40
Sample rate = 16 kHZ
Low frequency cutoff = 150 Hz
High frequency cutoff = 8 kHz
HTK formula = True
Librosa formula = False
Window shape = [40]
Frequency = 133.33 Hz
Rate = 21.33 KB/s

Groups into 40 non-linear bands	

---

#### 4.6 Clip 

Minimum = 0.000316227766
Maximum = 3.40282347E+38
Window shape = [40]
Frequency = 133.33 Hz
Rate = 21.33 KB/s

Clips the extremes

---

#### 4.7 Logarithm

Logartihm base = 0 
Window shape = [257]
Frequency = 133.33 Hz
Rate = 137.07 KB/s

Converts to a logarthimic scale

---

#### 4.8 Sliding Window (data points)

Window shape = [80,40]
Stride = 120
Buffer Multiplier = 1 
Frequency = 44.44 Hz
Rate = 568.89 KB/s

Does temporal stacking

---


The preprocessor can be found in (as it was used int his model):

`main-dir/project/deepcraft_workspace/AUDIO_MODEL/final_model`

---


**Challenge:**  
The main challenge was to set all the values correctly to be both detail and not so big that it would slow down / hang the training process.

---

## 5. Model Training (DeepCraft Studio)  

### 5.1 Project Type  

Classification Project  

---

### 5.2 Model settings  

Model family = Convolution 1D
Model flavour = SmallKern
Classifier = Global Average Pool
Model size = small
Optimization = accuracy
Downscale = False
Pooling = True
Learn Rate = Medium
Regularization = Medium

---

## 6. Deployment Considerations  

### 6.1 Embedded Constraints  

- Target device running MicroPython  
- Limited computational resources  
- Very limited stroage siz (hence small model 

---


## 8. MicroPython Deployment

### 8.1 Problem

I was unable to convert my model to micrpython with the model converter. I ecountered the following error:

```LinkError: build/model.o: undefined symbol: cos
make: *** [build/deepcraft_model.native.mpy] Error 1
[ERROR] Makefile failed with exit code 2
```

THis error was present when converting
- my latest model
- my previously created models
- template models found in deepcraft studio

### 8.2 Solution

I will demonstrate the functionality of my model with a live imsession in deepcraft studio

the files for it are located here:

`main-dir/project/deepcraft_workspace/AUDIO_MODEL/LIVE_DEMO/`

## 9. Conclusion  

The project partly implemented a real-time embedded motor condition classification system capable of detecting:

- Normal operation  
- Unbalanced behavior  
- Impact events  
- Motor stop state  

Key success factors:

- Targeted data augmentation  
- Detailed Preprocessor optimization 
 
Unfortunately, due to factors not in my control I was not able to successfully convert my model into .mpy and thus deploy it on board, but I will demonstrate that my model is in fact fully functional.