#ifndef LABIVIEW_H
#define LABIVIEW_H
#include "lvgl/lvgl.h"

/*****************************
 * Les styles des composants *
 * de la fenêtres Labi       *
 *****************************/
static lv_style_t m_labi_styleSqrR;
static lv_style_t m_labi_styleSqrB;
static lv_style_t m_labi_styleSqrG;
static lv_style_t m_labi_styleSqrP;
static lv_style_t m_labi_styleDdlist;
static lv_style_t m_labi_styleBtnRel;
static lv_style_t m_labi_styleBtnPr;

/****************************
 * composants de la fenêtre *
 * Labi                     *
 ****************************/
static lv_obj_t* m_SqrR_labi;
static lv_obj_t* m_SqrB_labi;
static lv_obj_t* m_SqrG_labi;
static lv_obj_t* m_SqrP_labi;
static lv_obj_t* m_ddlistR_labi;
static lv_obj_t* m_ddlistB_labi;
static lv_obj_t* m_ddlistG_labi;
static lv_obj_t* m_ddlistP_labi;
static lv_obj_t* m_btn_labi;



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
