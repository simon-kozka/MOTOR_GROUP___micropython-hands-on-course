import enum
class ReturnStatus(enum.Enum): 
    RET_SUCCESS = 0
    RET_NODATA = -1
    RET_NOMEM = -2

import ctypes
import numpy as np


class Model:
    def __init__(self):                          
        self.data_in_count = 1
        self.data_in_shape = (1,)   
        self.data_out_count = 4
        self.data_out_shape = (4,)
        self.api = 'queue'
        
        self._native = ctypes.cdll.LoadLibrary('./model.dll') 
        
        # void init(void);
        self._native.IMAI_init.argtypes = ()
        self._native.IMAI_init.restype = None
        
        # int enqueue(const float *restrict data_in, const float *restrict time_in);
        self._native.IMAI_enqueue.argtypes = [
            np.ctypeslib.ndpointer(dtype=np.float32, ndim=len(self.data_in_shape), flags='C_CONTIGUOUS')
        ]
        self._native.IMAI_enqueue.restype = ctypes.c_int
        
        # int dequeue(float *restrict data_out, float *restrict time_out);
        self._native.IMAI_dequeue.argtypes = [
            np.ctypeslib.ndpointer(dtype=np.float32, ndim=len(self.data_out_shape), flags='C_CONTIGUOUS')
        ]
        self._native.IMAI_dequeue.restype = ctypes.c_int
        
        # init C code
        self._native.IMAI_init()
        
    def enqueue(self, data_in : np.array):
        """
        Enqueue features. Returns SUCCESS (0) on success, else RET_NOMEM (-2) when low on memory.
        
        Parameters:
         data_in(float[1]): Input features. Shape {1}
        """
        return ReturnStatus(self._native.IMAI_enqueue(data_in));
        
    def dequeue(self, data_out : np.array):
        """
        Dequeue features. RET_SUCCESS (0) on success, RET_NODATA (-1) if no data is available, RET_NOMEM (-2) on internal memory error
        
        Parameters:
         data_out(float[4]): Output data. Shape {4}
        """
        
        return ReturnStatus(self._native.IMAI_dequeue(data_out))

