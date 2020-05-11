#ifndef INTERFACE_H
#define INTERFACE_H

#include "progView.h"
#include "LabiView.h"
#include "calcView.h"
#include <SDL2/SDL.h> //provisoir (simulation PC)
#include "lvgl/lvgl.h"
#include "lv_drivers/display/monitor.h" //provisoir (simulation PC)
#include "lv_drivers/indev/mouse.h" //provisoir (simulation PC)
#include "lv_drivers/indev/mousewheel.h" //provisoir (simulation PC)
#include "lv_drivers/indev/keyboard.h" //provisoir (simulation PC)

static lv_obj_t* m_calc;
static lv_obj_t* m_labi;
static lv_obj_t* m_prog;

void initWindow();
void styleWindow();

#endif // INTERFACE_H
