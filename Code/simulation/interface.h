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

void initWindow();
void styleWindow();

#endif // INTERFACE_H
