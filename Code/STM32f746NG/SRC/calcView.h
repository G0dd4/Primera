#ifndef CALCVIEW_H
#define CALCVIEW_H
#include "lvgl/lvgl.h"


/**************************
 * Création de la fenêtre *
 **************************/
void creatCalc(lv_obj_t* m_calc);
void styleCalc(lv_obj_t* m_calc);


/*********************
 * différents events *
 *********************/
static void kbEventHandler(lv_obj_t* kb, lv_event_t event);
static void btRefreshEventHandler(lv_obj_t* bt,lv_event_t event);

/********************
 * fonctions du jeu *
 ********************/
int generatCalcul();
int displayCalcul(int a,int b,int c);
int reponse(int r);
void conclusion(int c, int r);

#endif // CALCVIEW_H

