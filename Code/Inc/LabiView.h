#ifndef LABIVIEW_H
#define LABIVIEW_H
#include "lvgl/lvgl.h"





/**************************
 * Création de la fenêtre *
 **************************/
void creatLabi(lv_obj_t* m_labi);
void styleLabi(lv_obj_t* m_labi);

/*******************
 * différent event *
 *******************/
static void btValidEventHandler(lv_obj_t* bt,lv_event_t event);




#endif // LABIVIEW_H
