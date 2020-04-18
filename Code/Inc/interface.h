#ifndef INTERFACE_H
#define INTERFACE_H

#include "progView.h"
#include "LabiView.h"
#include <SDL2/SDL.h>
#include "lvgl/lvgl.h"
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/indev/mouse.h"
#include "lv_drivers/indev/mousewheel.h"
#include "lv_drivers/indev/keyboard.h"

static lv_obj_t* m_calc;
static lv_obj_t* m_labi;
static lv_obj_t* m_prog;

void initWindow();
void styleWindow();

#endif // INTERFACE_H
