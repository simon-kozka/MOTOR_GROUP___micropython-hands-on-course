# SPDX-FileCopyrightText: Copyright (c) 2023 Jose D. Montoya
#
# SPDX-License-Identifier: MIT

import time
from machine import I2C
from micropython_bmi270 import bmi270

i2c = I2C(scl='P0_2', sda='P0_3') # Correct I2C pins for PSOC6 AI Kit
bmi = bmi270.BMI270(i2c)

while True:
    accx, accy, accz = bmi.acceleration
    print(f"x:{accx:.2f}m/s2, y:{accy:.2f}m/s2, z{accz:.2f}m/s2")
    time.sleep(0.5)
    gyrox, gyroy, gyroz = bmi.gyro
    print("x:{:.2f}°/s, y:{:.2f}°/s, z{:.2f}°/s".format(gyrox, gyroy, gyroz))
    time.sleep(0.5)