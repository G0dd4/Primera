#ifndef DRV8825_H
#define DRV8825_H

#include "mbed.h"
#include "platform/mbed_thread.h"
#include "FastPWM.h"

#define FORWARD 1
#define BACKWARD 0

#define START 0
#define STOP 1

class DRV8825{
    public:
    DRV8825();
    DRV8825(PinName  pinEN, PinName pinDIR, PinName pinStep);

    void setDir(uint8_t dir);
    void setEnable(uint8_t en);
    void move(unsigned int Frequency);


    private:
    DigitalOut* m_en;
    DigitalOut* m_dir;
    FastPWM* m_step;

};


#endif DRV8825_H //DRV8825_H
