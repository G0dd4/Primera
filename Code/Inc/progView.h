#ifndef PROGVIEW_H
#define PROGVIEW_H
#include "lvgl/lvgl.h"
//#include <string>




/**************************
 * Création de la fenêtre *
 **************************/
void creatProg(lv_obj_t* m_prog);
void styleProg(lv_obj_t* m_prog);

/********************
 * fonctions string *
 ********************/
int verifTa();

/*******************
 * différent event *
 *******************/
static void taEventHandler(lv_obj_t* ta, lv_event_t event);
static void kbEventHandler(lv_obj_t* kb, lv_event_t event);
static void btValidEventHandler(lv_obj_t* bt, lv_event_t event);
static void btVerifEventHandler(lv_obj_t* bt, lv_event_t event);
static void kbHide(lv_anim_t* a);




#endif // PROGVIEW_H
