#ifndef INTERFACE_H
#define INTERFACE_H

#include "mbed.h"
#include "lvgl/lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"

#include "progView.h"
#include "LabiView.h"
#include "calcView.h"

#include "lvgl/lvgl.h"
 
#define LVGL_TICK 5                             //Time tick value for lvgl in ms (1-10msa)
#define TICKER_TIME 0.001 * LVGL_TICK           //modified to miliseconds
#define WAIT_TIME 1000 * LVGL_TICK              //modified to microseconds


static lv_obj_t* m_calc;
static lv_obj_t* m_labi;
static lv_obj_t* m_prog;


void initWindow();
void styleWindow();

void lv_ticker_func();

#endif // INTERFACE_H

