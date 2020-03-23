#include "DRV8825.h"


DRV8825::DRV8825(){
    m_en = new DigitalOut(D7);
    m_dir = new DigitalOut(D5);
    m_step = new PwmOut(D6);
    m_step->write(0.50);
}


DRV8825::DRV8825(PinName en, PinName dir ,PinName step){
    m_en = new DigitalOut(en);
    m_dir = new DigitalOut(dir);
    m_step = new PwmOut(step);
    m_step->write(0.50);
}

void DRV8825::setDir(uint8_t dir){
        m_dir->write(dir);
}

void DRV8825::setEnable(uint8_t en){
        m_en->write(en);
}

void DRV8825::move(float frequency){
        m_step->period((float)1/frequency);
}
