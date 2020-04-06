#ifndef DRV8825_H
#define DRV8825_H

#include "mbed.h"
#include "FastPWM.h"

#define FORWARD 1
#define BACKWARD 0

#define START 0
#define STOP 1

/**
 * @class DRV8825
 * @author Aissaoui Yannis
 * @brief permet de contrôler le module DRV8825
 * @version 1.0
 * @file drv8825.h
 * @date 6 avril 2020
 */
class DRV8825{
    public:
    DRV8825();
    DRV8825(PinName  pinEN, PinName pinDIR, PinName pinStep);
    ~DRV8825();
    DRV8825& operator=(DRV8825*& drv8825);

    void setDir(uint8_t dir);
    void setEnable(uint8_t en);
    void move(unsigned int Frequency);


    private:
    void initDrv8825();
    DigitalOut* m_en;
    DigitalOut* m_dir;
    FastPWM* m_step;

};


#endif //DRV8825_H
