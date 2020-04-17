#ifndef INTERFACE_H
#define INTERFACE_H

#include "progView.h"
#include "lvgl/lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"


static lv_obj_t* m_calc;
static lv_obj_t* m_labi;
static lv_obj_t* m_prog;

void initWindow();
void styleWindow();

#endif // INTERFACE_H
