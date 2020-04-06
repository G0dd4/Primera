#include "DRV8825.h"

/**
 * @brief Création d'un objet DRV8825 qui configure les attribues
 */
DRV8825::DRV8825(){
    m_en = new DigitalOut(PI_3);
    m_dir = new DigitalOut(PI_0);
    m_step = new FastPWM(PH_6);
    initDrv8825();
}

/**
 * @brief DRV8825::DRV8825
 * @param en = pin reliée à EN
 * @param dir = pin reliée à DIR
 * @param step = pin reliée à STEP
 */
DRV8825::DRV8825(PinName en, PinName dir ,PinName step){
    m_en = new DigitalOut(en);
    m_dir = new DigitalOut(dir);
    m_step = new FastPWM(step);
    m_step->write(0.50);
    initDrv8825();
}

/**
 * @brief cela nous permet de détruire notre objet
 */
DRV8825::~DRV8825(){
    delete m_en;
    delete m_dir;
    delete m_step;
}

/**
 * @brief Permet d'utiliser l'opérateur égale à notre class
 * @param drv8825 = un objet de type DRV8825 dont on va prendre les atributs
 * @return retourne l'objet modifié
 */
DRV8825& DRV8825::operator=(DRV8825* &drv8825 ){
    this->m_en = drv8825->m_en;
    this->m_dir = drv8825->m_en;
    this->m_step = drv8825->m_en;
    return *this;
}

/**
 * @brief nous permet de modifier l'état de la pin DIR
 * @param dir = l'état que l'on souhaite appliquer (FORWARD = 1 | BACKWARD = 0)
 */
void DRV8825::setDir(uint8_t dir){
    m_dir->write(dir);
}

/**
 * @brief nous permet de modifier l'état de la pin EN
 * @param dir = l'état que l'on souhaite appliquer (START = 0 | STOP = 0)
 */
void DRV8825::setEnable(uint8_t en){
    m_en->write(en);
}

/**
 * @brief nous permet de modifier la fréquence PWM de la pin STEP
 * @param period = le temps d'une répétition (en ms)
 */
void DRV8825::move(unsigned int period){
    m_step->period_ms(period);
    m_step->write(0.50);
}

/**
 * @brief nous permet d'initialiser le module
 */
void DRV8825::initDrv8825(){
    setDir(FORWARD);
    setEnable(STOP);
}
