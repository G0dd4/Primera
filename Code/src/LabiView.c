#include "LabiView.h"

void creatLabi(lv_obj_t* m_labi){
    styleLabi(m_labi);


    /************************
     * création des ddlists *
     ************************/
    m_ddlistB_labi = lv_ddlist_create(m_labi,NULL);
    lv_ddlist_set_options(m_ddlistB_labi,"Gauche\n"
                                          "Droite\n"
                                          "Avance\n"
                                          "Reculer");
    lv_obj_set_pos(m_ddlistB_labi,120,30);
    lv_obj_set_style(m_ddlistB_labi, &m_labi_styleSqrB);

    m_ddlistG_labi = lv_ddlist_create(m_labi,m_ddlistB_labi);
    lv_obj_set_style(m_ddlistG_labi, &m_labi_styleSqrG);
    lv_obj_set_pos(m_ddlistG_labi,360,30);


    m_ddlistR_labi = lv_ddlist_create(m_labi,m_ddlistB_labi);
    lv_obj_set_style(m_ddlistR_labi, &m_labi_styleSqrR);
    lv_obj_set_pos(m_ddlistR_labi,120,120);

    m_ddlistP_labi = lv_ddlist_create(m_labi,m_ddlistB_labi);
    lv_obj_set_style(m_ddlistP_labi, &m_labi_styleSqrP);
    lv_obj_set_pos(m_ddlistP_labi,360,120);


}

void styleLabi(lv_obj_t* m_labi){

    lv_style_copy(&m_labi_styleSqrB, &lv_style_pretty);
    m_labi_styleSqrB.body.shadow.width = 4;
    m_labi_styleSqrB.text.color = LV_COLOR_BLUE;

    lv_style_copy(&m_labi_styleSqrG, &m_labi_styleSqrB);
    m_labi_styleSqrG.text.color = LV_COLOR_GREEN;

    lv_style_copy(&m_labi_styleSqrR, &m_labi_styleSqrB);
    m_labi_styleSqrR.text.color = LV_COLOR_RED;

    lv_style_copy(&m_labi_styleSqrP, &m_labi_styleSqrB);
    m_labi_styleSqrP.text.color = LV_COLOR_PURPLE;


}

