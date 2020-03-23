/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */




// Blinking rate in milliseconds
#include "DRV8825.h"
#define BLINKING_RATE_MS 500


int main()
{
    // Initialise the digital pin LED1 as an output
    DRV8825 drv8825(D7,D5,D6);

    while (true) {
        drv8825.setDir(FORWARD);
        drv8825.setEnable(START);
        drv8825.move(10000);

    }
}
