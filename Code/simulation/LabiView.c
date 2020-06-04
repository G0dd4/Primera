#include "LabiView.h"

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
static lv_obj_t* m_mbox_labi;

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
    lv_obj_set_style(m_ddlistB_labi, &m_labi_styleDdlist);

    m_ddlistG_labi = lv_ddlist_create(m_labi,m_ddlistB_labi);
    lv_obj_set_style(m_ddlistG_labi, &m_labi_styleDdlist);
    lv_obj_set_pos(m_ddlistG_labi,360,30);


    m_ddlistR_labi = lv_ddlist_create(m_labi,m_ddlistB_labi);
    lv_obj_set_style(m_ddlistR_labi, &m_labi_styleDdlist);
    lv_obj_set_pos(m_ddlistR_labi,120,120);

    m_ddlistP_labi = lv_ddlist_create(m_labi,m_ddlistB_labi);
    lv_obj_set_style(m_ddlistP_labi, &m_labi_styleDdlist);
    lv_obj_set_pos(m_ddlistP_labi,360,120);



    /*****************************************
     * création des carrés pour les couleurs *
     *****************************************/
    m_SqrB_labi = lv_btn_create(m_labi,NULL);
    lv_obj_set_size(m_SqrB_labi,50,50);
    lv_obj_set_pos(m_SqrB_labi,70,20);
    lv_btn_set_style(m_SqrB_labi,LV_BTN_STATE_REL,&m_labi_styleSqrB);
    lv_btn_set_style(m_SqrB_labi,LV_BTN_STATE_PR,&m_labi_styleSqrB);

    m_SqrG_labi = lv_btn_create(m_labi,m_SqrB_labi);
    lv_obj_set_pos(m_SqrB_labi,310,20);
    lv_btn_set_style(m_SqrB_labi,LV_BTN_STATE_REL,&m_labi_styleSqrG);
    lv_btn_set_style(m_SqrB_labi,LV_BTN_STATE_PR,&m_labi_styleSqrG);

    m_SqrR_labi = lv_btn_create(m_labi,m_SqrB_labi);
    lv_obj_set_pos(m_SqrR_labi,70,110);
    lv_btn_set_style(m_SqrR_labi,LV_BTN_STATE_REL,&m_labi_styleSqrR);
    lv_btn_set_style(m_SqrR_labi,LV_BTN_STATE_PR,&m_labi_styleSqrR);

    m_SqrP_labi = lv_btn_create(m_labi,m_SqrB_labi);
    lv_obj_set_pos(m_SqrP_labi,310,110);
    lv_btn_set_style(m_SqrP_labi,LV_BTN_STATE_REL,&m_labi_styleSqrP);
    lv_btn_set_style(m_SqrP_labi,LV_BTN_STATE_PR,&m_labi_styleSqrP);

    lv_obj_t* label;
    m_btn_labi = lv_btn_create(m_labi,NULL);
    lv_obj_set_event_cb(m_btn_labi,btValidEventHandler);
    lv_obj_set_size(m_btn_labi,100,30);
    lv_obj_set_pos(m_btn_labi,190,175);
    lv_btn_set_style(m_btn_labi,LV_BTN_STATE_REL,&m_labi_styleBtnRel);
    lv_btn_set_style(m_btn_labi,LV_BTN_STATE_PR,&m_labi_styleBtnPr);
    label = lv_label_create(m_btn_labi,NULL);
    lv_label_set_text(label,"valider");




}

void styleLabi(lv_obj_t* m_labi){
    /********************
     * style des carrés *
     ********************/
    lv_style_copy(&m_labi_styleSqrB, &lv_style_pretty);
    m_labi_styleSqrB.body.shadow.width = 0;
    m_labi_styleSqrB.body.main_color = LV_COLOR_BLUE;
    m_labi_styleSqrB.body.opa = LV_OPA_COVER;
    m_labi_styleSqrB.body.grad_color = LV_COLOR_BLUE;

    lv_style_copy(&m_labi_styleSqrG, &m_labi_styleSqrB);
    m_labi_styleSqrG.body.main_color = LV_COLOR_GREEN;
    m_labi_styleSqrG.body.grad_color = LV_COLOR_GREEN;

    lv_style_copy(&m_labi_styleSqrR, &m_labi_styleSqrB);
    m_labi_styleSqrR.body.main_color = LV_COLOR_RED;
    m_labi_styleSqrR.body.grad_color = LV_COLOR_RED;

    lv_style_copy(&m_labi_styleSqrP, &m_labi_styleSqrB);
    m_labi_styleSqrP.body.main_color = LV_COLOR_PURPLE;
    m_labi_styleSqrP.body.grad_color = LV_COLOR_PURPLE;


    /*********************
     * style des ddlists *
     *********************/
    lv_style_copy(&m_labi_styleDdlist, &lv_style_pretty);
    m_labi_styleSqrB.body.shadow.width = 4;
    m_labi_styleSqrB.text.color = LV_COLOR_MAKE(0x10, 0x20, 0x50);



    /***********************************
     * style du bouton valider lorsque *
     * l'on apppuis pas desus          *
     ***********************************/
    lv_style_copy(&m_labi_styleBtnRel,&lv_style_btn_rel);
    m_labi_styleBtnRel.body.main_color = lv_color_hex3(0x333);
    m_labi_styleBtnRel.body.grad_color = LV_COLOR_BLACK;
    m_labi_styleBtnRel.body.border.color = LV_COLOR_SILVER;
    m_labi_styleBtnRel.body.border.width = 1;
    m_labi_styleBtnRel.body.border.opa = LV_OPA_50;
    m_labi_styleBtnRel.body.radius = 0;

    /***********************************
     * style du bouton valider lorsque *
     * l'on apppuis desus              *
     ***********************************/
    lv_style_copy(&m_labi_styleBtnPr, &m_labi_styleBtnRel);
    m_labi_styleBtnPr.body.main_color = lv_color_make(0x55, 0x96, 0xd8);
    m_labi_styleBtnPr.body.grad_color = lv_color_make(0x37, 0x62, 0x90);
    m_labi_styleBtnPr.text.color = lv_color_make(0xbb, 0xd5, 0xf1);

}

static void btValidEventHandler(lv_obj_t* bt,lv_event_t event){
    if(event == LV_EVENT_CLICKED){
        lv_obj_t * parent = lv_obj_get_parent(lv_obj_get_parent(bt));
        m_mbox_labi = lv_mbox_create(parent,NULL);
        lv_mbox_set_text(m_mbox_labi,"choix enregistrer");
        static const char * mbox_btns[] = {"Ok", ""};
        lv_mbox_add_btns(m_mbox_labi, mbox_btns);    /*The default action is close*/
        lv_obj_set_size(m_mbox_labi,200,50);
        lv_obj_set_x(m_mbox_labi,200);
        lv_obj_set_y(m_mbox_labi,50);
    }
}


