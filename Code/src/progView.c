#include "progView.h"
#include <stdio.h>
#include <string.h>

void creatProg(lv_obj_t* m_prog){
    styleProg(m_prog);

    /**************************************
     * Création et placement du text area *
     **************************************/
    m_ta_prog = lv_ta_create(m_prog,NULL);
    lv_obj_set_size(m_ta_prog,lv_page_get_scrl_width(m_prog)/2+30,lv_page_get_scrl_height(m_prog)/2);
    lv_ta_set_style(m_ta_prog,LV_CB_STYLE_BG,&m_prog_styleTa);
    lv_ta_set_text(m_ta_prog,"");
    lv_obj_set_event_cb(m_ta_prog, taEventHandler);
    lv_ta_set_text_sel(m_prog,true);

    /*************************
     *  Création d'une liste *
     *************************/
    m_list_prog = lv_list_create(m_prog,NULL);
    lv_obj_set_height(m_list_prog, 2*lv_obj_get_height(m_prog) / 3 );
    lv_list_set_style(m_list_prog, LV_LIST_STYLE_BG, &lv_style_transp_tight);
    lv_list_set_style(m_list_prog, LV_LIST_STYLE_SCRL, &lv_style_transp_tight);
    lv_list_set_style(m_list_prog, LV_LIST_STYLE_BTN_REL, &m_prog_styleBtRel);
    lv_list_set_style(m_list_prog, LV_LIST_STYLE_BTN_PR, &m_prog_styleBtPr);
    lv_obj_align(m_list_prog, NULL, LV_ALIGN_IN_TOP_MID, 0, LV_DPI / 4);
    lv_obj_set_pos(m_list_prog,lv_page_get_scrl_width(m_prog)/2 +30,0);

    /**********************
     * ajouts des boutons *
     **********************/
    m_listBt_prog = lv_list_add_btn(m_list_prog,LV_SYMBOL_OK,"valider");
    lv_obj_set_event_cb(m_listBt_prog,btValidEventHandler);
    m_listBt_prog = lv_list_add_btn(m_list_prog,LV_SYMBOL_REFRESH, "verifier");
    lv_obj_set_event_cb(m_listBt_prog,btVerifEventHandler);



}

void styleProg(lv_obj_t* m_prog){
    /****************************
     * style de notre view prog *
     ****************************/
    lv_page_set_style(m_prog,LV_PAGE_STYLE_BG, &lv_style_transp_fit);
    lv_page_set_style(m_prog,LV_PAGE_STYLE_SCRL,&lv_style_transp_fit);
    lv_page_set_sb_mode(m_prog,LV_SB_MODE_OFF);

    /**********************
     * style du text area *
     **********************/
    lv_style_copy(&m_prog_styleTa, &lv_style_pretty);
    m_prog_styleTa.body.opa = LV_OPA_30;
    m_prog_styleTa.body.radius = 0;
    m_prog_styleTa.text.color = lv_color_hex3(0x222);

    /********************
     * style du clavier *
     ********************/
    lv_style_copy(&m_prog_styleKb, &lv_style_plain);
    m_prog_styleKb.body.opa = LV_OPA_70;
    m_prog_styleKb.body.main_color = lv_color_hex3(0x333);
    m_prog_styleKb.body.grad_color = lv_color_hex3(0x333);
    m_prog_styleKb.body.padding.left = 0;
    m_prog_styleKb.body.padding.right = 0;
    m_prog_styleKb.body.padding.top = 0;
    m_prog_styleKb.body.padding.bottom = 0;
    m_prog_styleKb.body.padding.inner = 0;

    /***************************************
     * style des bouton du clavier lorsque *
     * l'on appuis pas sur une touche      *
     ***************************************/
    lv_style_copy(&m_prog_styleKbRel, &lv_style_plain);
    m_prog_styleKbRel.body.opa = LV_OPA_TRANSP;
    m_prog_styleKbRel.body.radius = 0;
    m_prog_styleKbRel.body.border.width = 1;
    m_prog_styleKbRel.body.border.color = LV_COLOR_SILVER;
    m_prog_styleKbRel.body.border.opa = LV_OPA_50;
    m_prog_styleKbRel.body.main_color = lv_color_hex3(0x333);    /*Recommended if LV_VDB_SIZE == 0 and bpp > 1 fonts are used*/
    m_prog_styleKbRel.body.grad_color = lv_color_hex3(0x333);
    m_prog_styleKbRel.text.color = LV_COLOR_WHITE;

    /***************************************
     * style des bouton du clavier lorsque *
     * l'on appuis sur une touche          *
     ***************************************/
    lv_style_copy(&m_prog_styleKbPr, &lv_style_plain);
    m_prog_styleKbPr.body.radius = 0;
    m_prog_styleKbPr.body.opa = LV_OPA_50;
    m_prog_styleKbPr.body.main_color = LV_COLOR_WHITE;
    m_prog_styleKbPr.body.grad_color = LV_COLOR_WHITE;
    m_prog_styleKbPr.body.border.width = 1;
    m_prog_styleKbPr.body.border.color = LV_COLOR_SILVER;


    /************************************
     * style de la liste bouton lorsque *
     * l'on appuis pas sur une touche   *
     ************************************/
    lv_style_copy(&m_prog_styleBtRel, &lv_style_btn_rel);
    m_prog_styleBtRel.body.main_color = lv_color_hex3(0x333);
    m_prog_styleBtRel.body.grad_color = LV_COLOR_BLACK;
    m_prog_styleBtRel.body.border.color = LV_COLOR_SILVER;
    m_prog_styleBtRel.body.border.width = 1;
    m_prog_styleBtRel.body.border.opa = LV_OPA_50;
    m_prog_styleBtRel.body.radius = 0;

    /************************************
     * style de la liste bouton lorsque *
     * l'on appuis sur une touche       *
     ************************************/
    lv_style_copy(&m_prog_styleBtPr, &m_prog_styleBtRel);
    m_prog_styleBtPr.body.main_color = lv_color_make(0x55, 0x96, 0xd8);
    m_prog_styleBtPr.body.grad_color = lv_color_make(0x37, 0x62, 0x90);
    m_prog_styleBtPr.text.color = lv_color_make(0xbb, 0xd5, 0xf1);

}



static void btValidEventHandler(lv_obj_t* bt, lv_event_t event){

}
static void btVerifEventHandler(lv_obj_t* bt, lv_event_t event){

    lv_obj_t * parent = lv_obj_get_parent(lv_obj_get_parent(m_ta_prog));
    lv_coord_t hres = lv_disp_get_hor_res(NULL);
    if(event == LV_EVENT_CLICKED){
        int length = strlen(lv_ta_get_text(m_ta_prog));

        char text[length+1];
        strcpy(text,lv_ta_get_text(m_ta_prog));

        char data[10];
        int j = 0;
        int ligne = 0;


        for (int i = 0;i < length; i++) {
            if (text[i] == '\n' || i == length - 1) {
                data[j] = '\0';
                ligne++;
                if (strcmp(data,"Avancer\0")==0 || strcmp(data,"avancer\0")==0 || strcmp(data,"AVANCER\0")==0){
                    printf("Avancer\n");
                }
                else if (strcmp(data, "Reculer\0")==0 || strcmp(data, "reculer\0")==0 || strcmp(data,"RECULER\0")==0){
                    printf("Reculer \n");
                }
                else if (strcmp(data,"Gauche\0")==0 || strcmp(data,"gauche\0")==0 || strcmp(data,"GAUCHE\0")==0){
                    printf("Gauche  \n");
                }
                else if (strcmp(data,"Droite\0") == 0 || strcmp(data, "droite\0")==0 || strcmp( data, "DROITE\0")==0){

                    printf("Droite \n");
                }
                else {

                    printf("wrong\n");
                    m_mbox_prog = lv_mbox_create(parent,NULL);
                    lv_mbox_set_text(m_mbox_prog,"Vous avez une erreur à la ligne : 1");
                    static const char * mbox_btns[] = {"Ok", ""};
                    lv_mbox_add_btns(m_mbox_prog, mbox_btns);    /*The default action is close*/
                    lv_obj_set_size(m_mbox_prog,200,50);
                    lv_obj_set_x(m_mbox_prog,200);
                    lv_obj_set_y(m_mbox_prog,50);


                }
                j = 0;
            }
            else {
                data[j] = text[i];
                j++;


            }

        }
    }

}
static void taEventHandler(lv_obj_t* ta, lv_event_t event){

    lv_obj_t * parent = lv_obj_get_parent(lv_obj_get_parent(ta));

    if(event == LV_EVENT_CLICKED) {
        if(m_kb_prog == NULL) {
            /************************************
             * Création et placement du clavier *
             ************************************/
            m_kb_prog = lv_kb_create(parent, NULL);
            lv_obj_set_size(m_kb_prog, lv_obj_get_width_fit(parent), lv_obj_get_height_fit(parent) / 2);
            lv_obj_align(m_kb_prog, ta, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
            lv_kb_set_ta(m_kb_prog, ta);
            lv_obj_set_pos(m_kb_prog,120,lv_obj_get_height_fit(parent) / 2);
            lv_kb_set_style(m_kb_prog, LV_KB_STYLE_BG, &m_prog_styleKb);
            lv_kb_set_style(m_kb_prog, LV_KB_STYLE_BTN_REL, &m_prog_styleKbRel);
            lv_kb_set_style(m_kb_prog, LV_KB_STYLE_BTN_PR, &m_prog_styleKbPr);
            lv_obj_set_event_cb(m_kb_prog, kbEventHandler);

            /*********************************
             * création d'une animation pour *
             * l'apparition du clavier       *
             *********************************/
            lv_anim_t a;
            a.var = m_kb_prog;
            a.start = LV_VER_RES;
            a.end = lv_obj_get_y(m_kb_prog);
            a.exec_cb = (lv_anim_exec_xcb_t)lv_obj_set_y;
            a.path_cb = lv_anim_path_linear;
            a.ready_cb = NULL;
            a.act_time = 0;
            a.time = 300;
            a.playback = 0;
            a.playback_pause = 0;
            a.repeat = 0;
            a.repeat_pause = 0;
            lv_anim_create(&a);

        }
    }
}
static void kbEventHandler(lv_obj_t* kb, lv_event_t event){

    lv_kb_def_event_cb(kb, event);
    /************************************
     * si nous appuiyons sur le bouton  *
     * CANCEL OU APPLY                  *
     ************************************/
    if(event == LV_EVENT_APPLY || event == LV_EVENT_CANCEL) {
        /*********************************
         * Création d'une animation pour *
         * la disparition du clavier     *
         *********************************/
        lv_anim_t a;
        a.var = kb;
        a.start = lv_obj_get_y(kb);
        a.end = LV_VER_RES;
        a.exec_cb = (lv_anim_exec_xcb_t)lv_obj_set_y;
        a.path_cb = lv_anim_path_linear;
        a.ready_cb = kbHide;
        a.act_time = 0;
        a.time = 300;
        a.playback = 0;
        a.playback_pause = 0;
        a.repeat = 0;
        a.repeat_pause = 0;
        lv_anim_create(&a);
    }
}

static void kbHide(lv_anim_t* a){
    /*******************************************
     * à la fin de l'animation nous détruisons *
     * le clavier et l'animation               *
     *******************************************/
    lv_obj_del(a->var);
    m_kb_prog = NULL;
}
