#ifndef PROGVIEW_H
#define PROGVIEW_H
#include "lvgl/lvgl.h"

/*****************************
 * Les styles des composants *
 * de la fenêtres Prog       *
 *****************************/
static lv_style_t m_prog_styleTa;
static lv_style_t m_prog_styleKb;
static lv_style_t m_prog_styleKbRel;
static lv_style_t m_prog_styleKbPr;
static lv_style_t m_prog_styleBtRel;
static lv_style_t m_prog_styleBtPr;


/****************************
 * composants de la fenêtre *
 * Prog                     *
 ****************************/
static lv_obj_t* m_ta_prog;
static lv_obj_t* m_kb_prog;
static lv_obj_t* m_list_prog;
static lv_obj_t* m_listBt_prog;


/**************************
 * Création de la fenêtre *
 **************************/
void creatProg(lv_obj_t* m_prog);
void styleProg(lv_obj_t* m_prog);


/*******************
 * différent event *
 *******************/
static void taEventHandler(lv_obj_t* ta, lv_event_t event);
static void kbEventHandler(lv_obj_t* kb, lv_event_t event);
static void btValidEventHandler(lv_obj_t* bt, lv_event_t event);
static void btVerifEventHandler(lv_obj_t* bt, lv_event_t event);
static void kbHide(lv_anim_t* a);




#endif // PROGVIEW_H
