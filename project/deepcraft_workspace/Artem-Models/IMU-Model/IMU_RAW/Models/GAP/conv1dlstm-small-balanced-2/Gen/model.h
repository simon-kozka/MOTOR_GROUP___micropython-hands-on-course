/*
* DEEPCRAFT Studio 5.9.4563.0+34bdb7f4372a1120ca38a0cb02e62db5b4b78270
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 02/19/2026 13:36:01 UTC. Any changes will be lost.
* 
* Model ID  d5f3e9a4-56e8-456d-884a-9cf69ea26b97
* 
* Memory    Size                      Efficiency
* Buffers   1536 bytes (RAM)          100 %
* State     608 bytes (RAM)           100 %
* Readonly  53584 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1dlstm-small-balanced-2
* 
* Class Index | Symbol Label
* 0           | (unlabeled)
* 1           | imbalance
* 2           | working
* 3           | impact
* 
* Layer                          Shape           Type       Function
* Sliding Window (data points)   [6,6]           float      dequeue
*    window_shape = [6,6]
*    stride = 6
*    buffer_multiplier = 1
* Contextual Window (Sliding Window) [6,6]           float      dequeue
*    contextual_length_sec = 0.03
*    prediction_freq = 200
* Input Layer                    [6,6]           float      dequeue
*    shape = [6,6]
* Convolution 1D                 [3,16]          float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,6,16]
* Batch Normalization            [3,16]          float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [3,16]          float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [3,32]          float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,32]
* Convolution 1D                 [3,32]          float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,32]
* Batch Normalization            [3,32]          float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [3,32]          float      dequeue
*    activation = relu
*    trainable = True
* Long Short-Term Memory         [3,32]          float      dequeue
*    units = 32
*    activation = tanh
*    recurrent_activation = sigmoid
*    use_bias = True
*    return_sequences = True
*    return_state = False
*    stateful = False
*    go_backwards = False
*    trainable = True
*    kernel = float[32,128]
*    recurrent_kernel = float[32,128]
*    bias = float[128]
* Global average pooling 1D      [32]            float      dequeue
*    trainable = True
* Dense                          [4]             float      dequeue
*    units = 4
*    use_bias = True
*    activation = linear
*    trainable = True
*    weight = float[32,4]
*    bias = float[4]
* Activation                     [4]             float      dequeue
*    activation = softmax
*    trainable = True
* 
* Exported functions:
* 
* int IMAI_dequeue(float *restrict data_out)
*    Description: Dequeue features. RET_SUCCESS (0) on success, RET_NODATA (-1) if no data is available, RET_NOMEM (-2) on internal memory error
*    Parameter data_out is Output of size float[4].
* 
* int IMAI_enqueue(const float *restrict data_in)
*    Description: Enqueue features. Returns SUCCESS (0) on success, else RET_NOMEM (-2) when low on memory.
*    Parameter data_in is Input of size float[6].
* 
* void IMAI_init(void)
*    Description: Initializes buffers to initial state. This function also works as a reset function.
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
*/

#ifndef _IMAI_MODEL_H_
#define _IMAI_MODEL_H_
#ifdef _MSC_VER
#pragma once
#endif

#include <stdint.h>

typedef struct {    
    char *name;
    double TP; // True Positive or Correct Positive Prediction
    double FN; // False Negative or Incorrect Negative Prediction
    double FP; // False Positive or Incorrect Positive Prediction
    double TN; // True Negative or Correct Negative Prediction
    double TPR; // True Positive Rate or Sensitivity, Recall
    double TNR; // True Negative Rate or Specificity, Selectivity
    double PPV; // Positive Predictive Value or Precision
    double NPV; // Negative Predictive Value
    double FNR; // False Negative Rate or Miss Rate
    double FPR; // False Positive Rate or Fall-Out
    double FDR; // False Discovery Rate
    double FOR; // False Omission Rate
    double F1S; // F1 Score
} IMAI_stats;

/*
* Tensorflow Test Set
* 
* (ACC) Accuracy 84.703 %
* (F1S) F1 Score 85.233 %
* 
* Name of class                                               unlabeled        imbalance           impact          working
* (TP) True Positive or Correct Positive Prediction               23631            24708            14285            25054
* (FN) False Negative or Incorrect Negative Prediction             5786              487             1013             8548
* (FP) False Positive or Incorrect Positive Prediction              699              579            10123             4433
* (TN) True Negative or Correct Negative Prediction               73396            77738            78091            65477
* (TPR) True Positive Rate or Sensitivity, Recall               80.33 %          98.07 %          93.38 %          74.56 %
* (TNR) True Negative Rate or Specificity, Selectivity          99.06 %          99.26 %          88.52 %          93.66 %
* (PPV) Positive Predictive Value or Precision                  97.13 %          97.71 %          58.53 %          84.97 %
* (NPV) Negative Predictive Value                               92.69 %          99.38 %          98.72 %          88.45 %
* (FNR) False Negative Rate or Miss Rate                        19.67 %           1.93 %           6.62 %          25.44 %
* (FPR) False Positive Rate or Fall-Out                          0.94 %           0.74 %          11.48 %           6.34 %
* (FDR) False Discovery Rate                                     2.87 %           2.29 %          41.47 %          15.03 %
* (FOR) False Omission Rate                                      7.31 %           0.62 %           1.28 %          11.55 %
* (F1S) F1 Score                                                87.93 %          97.89 %          71.95 %          79.42 %
*/


#define IMAI_TEST_AVG_ACC 0.8470322281474612 // Accuracy
#define IMAI_TEST_AVG_F1S 0.8523285678392039 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "unlabeled", TP: 23631, FN: 5786, FP: 699, TN: 73396, TPR: 0.8033110106401, TNR: 0.9905661650583, PPV: 0.9712700369913, NPV: 0.9269278371347, FNR: 0.1966889893598, FPR: 0.0094338349416, FDR: 0.0287299630086, FOR: 0.0730721628652, F1S: 0.8793421028150, }, \
 {name: "imbalance", TP: 24708, FN: 487, FP: 579, TN: 77738, TPR: 0.9806707680095, TNR: 0.9926069691127, PPV: 0.9771028591766, NPV: 0.9937743688079, FNR: 0.0193292319904, FPR: 0.0073930308872, FDR: 0.0228971408233, FOR: 0.0062256311920, F1S: 0.9788835624579, }, \
 {name: "working", TP: 25054, FN: 8548, FP: 4433, TN: 65477, TPR: 0.7456103803345, TNR: 0.9365899013016, PPV: 0.8496625631634, NPV: 0.8845254981425, FNR: 0.2543896196654, FPR: 0.0634100986983, FDR: 0.1503374368365, FOR: 0.1154745018574, F1S: 0.7942430534641, }, \
 {name: "impact", TP: 14285, FN: 1013, FP: 10123, TN: 78091, TPR: 0.9337821937508, TNR: 0.8852449724533, PPV: 0.5852589314978, NPV: 0.9871940736245, FNR: 0.0662178062491, FPR: 0.1147550275466, FDR: 0.4147410685021, FOR: 0.0128059263754, F1S: 0.7195386087744, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 85.752 %
* (F1S) F1 Score 86.243 %
* 
* Name of class                                               unlabeled        imbalance           impact          working
* (TP) True Positive or Correct Positive Prediction               70528            75656            39989            78458
* (FN) False Negative or Incorrect Negative Prediction            21088              397             2176            20308
* (FP) False Positive or Incorrect Positive Prediction              241             1583            27259            14886
* (TN) True Negative or Correct Negative Prediction              216743           230964           239176           194948
* (TPR) True Positive Rate or Sensitivity, Recall               76.98 %          99.48 %          94.84 %          79.44 %
* (TNR) True Negative Rate or Specificity, Selectivity          99.89 %          99.32 %          89.77 %          92.91 %
* (PPV) Positive Predictive Value or Precision                  99.66 %          97.95 %          59.46 %          84.05 %
* (NPV) Negative Predictive Value                               91.13 %          99.83 %          99.10 %          90.57 %
* (FNR) False Negative Rate or Miss Rate                        23.02 %           0.52 %           5.16 %          20.56 %
* (FPR) False Positive Rate or Fall-Out                          0.11 %           0.68 %          10.23 %           7.09 %
* (FDR) False Discovery Rate                                     0.34 %           2.05 %          40.54 %          15.95 %
* (FOR) False Omission Rate                                      8.87 %           0.17 %           0.90 %           9.43 %
* (F1S) F1 Score                                                86.87 %          98.71 %          73.10 %          81.68 %
*/


#define IMAI_TRAIN_AVG_ACC 0.8575210628645495 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.8624332434761621 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "unlabeled", TP: 70528, FN: 21088, FP: 241, TN: 216743, TPR: 0.7698218651763, TNR: 0.9988893190281, PPV: 0.9965945541126, NPV: 0.9113319962494, FNR: 0.2301781348236, FPR: 0.0011106809718, FDR: 0.0034054458873, FOR: 0.0886680037505, F1S: 0.8686516611756, }, \
 {name: "imbalance", TP: 75656, FN: 397, FP: 1583, TN: 230964, TPR: 0.9947799560832, TNR: 0.9931927739338, PPV: 0.9795051722575, NPV: 0.9982840668911, FNR: 0.0052200439167, FPR: 0.0068072260661, FDR: 0.0204948277424, FOR: 0.0017159331088, F1S: 0.9870834746757, }, \
 {name: "working", TP: 78458, FN: 20308, FP: 14886, TN: 194948, TPR: 0.7943826822995, TNR: 0.9290582079167, PPV: 0.8405253685293, NPV: 0.9056565206080, FNR: 0.2056173177004, FPR: 0.0709417920832, FDR: 0.1594746314706, FOR: 0.0943434793919, F1S: 0.8168028733538, }, \
 {name: "impact", TP: 39989, FN: 2176, FP: 27259, TN: 239176, TPR: 0.9483932171232, TNR: 0.8976898680728, PPV: 0.5946496550083, NPV: 0.9909841227750, FNR: 0.0516067828767, FPR: 0.1023101319271, FDR: 0.4053503449916, FOR: 0.0090158772249, F1S: 0.7309734675038, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 83.924 %
* (F1S) F1 Score 84.567 %
* 
* Name of class                                               unlabeled        imbalance           impact          working
* (TP) True Positive or Correct Positive Prediction               22321            23827            12903            25309
* (FN) False Negative or Incorrect Negative Prediction             7711              992             1170             6287
* (FP) False Positive or Incorrect Positive Prediction              498              488             9889             5285
* (TN) True Negative or Correct Negative Prediction               69990            75213            76558            63639
* (TPR) True Positive Rate or Sensitivity, Recall               74.32 %          96.00 %          91.69 %          80.10 %
* (TNR) True Negative Rate or Specificity, Selectivity          99.29 %          99.36 %          88.56 %          92.33 %
* (PPV) Positive Predictive Value or Precision                  97.82 %          97.99 %          56.61 %          82.73 %
* (NPV) Negative Predictive Value                               90.08 %          98.70 %          98.49 %          91.01 %
* (FNR) False Negative Rate or Miss Rate                        25.68 %           4.00 %           8.31 %          19.90 %
* (FPR) False Positive Rate or Fall-Out                          0.71 %           0.64 %          11.44 %           7.67 %
* (FDR) False Discovery Rate                                     2.18 %           2.01 %          43.39 %          17.27 %
* (FOR) False Omission Rate                                      9.92 %           1.30 %           1.51 %           8.99 %
* (F1S) F1 Score                                                84.47 %          96.99 %          70.00 %          81.39 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.8392359729407083 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.8456705393456482 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "unlabeled", TP: 22321, FN: 7711, FP: 498, TN: 69990, TPR: 0.7432405434203, TNR: 0.9929349676540, PPV: 0.9781760813357, NPV: 0.9007606079715, FNR: 0.2567594565796, FPR: 0.0070650323459, FDR: 0.0218239186642, FOR: 0.0992393920284, F1S: 0.8446765434901, }, \
 {name: "imbalance", TP: 23827, FN: 992, FP: 488, TN: 75213, TPR: 0.9600306217011, TNR: 0.9935535858178, PPV: 0.9799300843100, NPV: 0.9869824814644, FNR: 0.0399693782988, FPR: 0.0064464141821, FDR: 0.0200699156899, FOR: 0.0130175185355, F1S: 0.9698782920177, }, \
 {name: "working", TP: 25309, FN: 6287, FP: 5285, TN: 63639, TPR: 0.8010191163438, TNR: 0.9233213394463, PPV: 0.8272537098777, NPV: 0.9100906672768, FNR: 0.1989808836561, FPR: 0.0766786605536, FDR: 0.1727462901222, FOR: 0.0899093327231, F1S: 0.8139250683389, }, \
 {name: "impact", TP: 12903, FN: 1170, FP: 9889, TN: 76558, TPR: 0.9168620763163, TNR: 0.8856062095850, PPV: 0.5661196911196, NPV: 0.9849475092630, FNR: 0.0831379236836, FPR: 0.1143937904149, FDR: 0.4338803088803, FOR: 0.0150524907369, F1S: 0.7000135630001, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"(unlabeled)", "imbalance", "working", "impact"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xa4, 0xe9, 0xf3, 0xd5, 0xe8, 0x56, 0x6d, 0x45, 0x88, 0x4a, 0x9c, 0xf6, 0x9e, 0xa2, 0x6b, 0x97}

// First nibble is bit encoding, second nibble is number of bytes
#define IMAGINET_TYPES_NONE	(0x0)
#define IMAGINET_TYPES_FLOAT32	(0x14)
#define IMAGINET_TYPES_FLOAT64	(0x18)
#define IMAGINET_TYPES_INT8	(0x21)
#define IMAGINET_TYPES_INT16	(0x22)
#define IMAGINET_TYPES_INT32	(0x24)
#define IMAGINET_TYPES_INT64	(0x28)
#define IMAGINET_TYPES_QDYN8	(0x31)
#define IMAGINET_TYPES_QDYN16	(0x32)
#define IMAGINET_TYPES_QDYN32	(0x34)

// data_in [6] (24 bytes)
#define IMAI_DATA_IN_COUNT (6)
#define IMAI_DATA_IN_TYPE float
#define IMAI_DATA_IN_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_IN_SCALE (1)
#define IMAI_DATA_IN_OFFSET (0)
#define IMAI_DATA_IN_IS_QUANTIZED (0)

// data_out [4] (16 bytes)
#define IMAI_DATA_OUT_COUNT (4)
#define IMAI_DATA_OUT_TYPE float
#define IMAI_DATA_OUT_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_OUT_SCALE (1)
#define IMAI_DATA_OUT_OFFSET (0)
#define IMAI_DATA_OUT_IS_QUANTIZED (0)

#define IMAI_KEY_MAX (71)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
int IMAI_dequeue(float *restrict data_out);
int IMAI_enqueue(const float *restrict data_in);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
