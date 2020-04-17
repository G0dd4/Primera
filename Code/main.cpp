/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */


#include "SRC/interface.h"
#include "SRC/DRV8825.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"


#define pinEN PI_3
#define pinDIR PI_0
#define pinSTEP PH_6


int main()
{
    DRV8825 drv8825(pinEN,pinDIR,pinSTEP);
    initWindow();

    while (true) {
        drv8825.setEnable(START);
        drv8825.setDir(STOP);
        drv8825.move(1);

    }
}
