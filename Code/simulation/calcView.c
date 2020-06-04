#include "calcView.h"
#include <time.h>


/*****************************
 * Les styles des composants *
 * de la fenêtres Calc       *
 *****************************/
static lv_style_t m_calc_styleTa;
static lv_style_t m_calc_styleKb;
static lv_style_t m_calc_styleKbRel;
static lv_style_t m_calc_styleKbPr;
static lv_style_t m_calc_styleBtRefRel;
static lv_style_t m_calc_styleBtRefPr;


/****************************
 * Composants de la fenêtre *
 ****************************/
static lv_obj_t* m_ta_calc;
static lv_obj_t* m_kb_calc;
static lv_obj_t* m_bt_calc;
static lv_obj_t* m_op1_calc;
static lv_obj_t* m_opr_calc;
static lv_obj_t* m_op2_calc;
static lv_obj_t* m_eql_calc;
static lv_obj_t* m_res_calc;
static lv_obj_t* m_mbox_calc;

/*********
 * label *
 * *******/
lv_obj_t* op1;
lv_obj_t* operand;
lv_obj_t* op2;

/***********
 * réponse *
 ***********/
int Greponse;
int vie;


void creatCalc(lv_obj_t* m_calc){

    /**************************************
     * Création et placement du text area *
     **************************************/
    styleCalc(m_calc);
    m_ta_calc = lv_ta_create(m_calc,NULL);
    lv_obj_set_size(m_ta_calc,100,37);
    lv_obj_set_pos(m_ta_calc,50,lv_page_get_scrl_height(m_calc)/2);
    lv_ta_set_style(m_ta_calc,LV_CB_STYLE_BG,&m_calc_styleTa);
    lv_ta_set_max_length(m_ta_calc,3);
    lv_ta_set_text(m_ta_calc,"");
    lv_ta_set_text_sel(m_ta_calc,true);

    /************************************
    * Création et placement du clavier *
    ************************************/
    m_kb_calc = lv_kb_create(m_calc, NULL);
    lv_kb_set_mode(m_kb_calc,LV_KB_MODE_NUM);
    lv_obj_set_size(m_kb_calc, 200, lv_obj_get_height_fit(m_calc)/2 -2);
    lv_obj_align(m_kb_calc, m_ta_calc, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_kb_set_ta(m_kb_calc, m_ta_calc);
    lv_obj_set_pos(m_kb_calc,280,lv_obj_get_height_fit(m_calc) /2 -5);
    lv_kb_set_style(m_kb_calc, LV_KB_STYLE_BG, &m_calc_styleKb);
    lv_kb_set_style(m_kb_calc, LV_KB_STYLE_BTN_REL, &m_calc_styleKbRel);
    lv_kb_set_style(m_kb_calc, LV_KB_STYLE_BTN_PR, &m_calc_styleKbPr);
    lv_obj_set_event_cb(m_kb_calc, kbEventHandler);

    /**********************************************
     * Création et placement du bouton rafraîchir *
     **********************************************/
    lv_obj_t* label;
    m_bt_calc = lv_btn_create(m_calc,NULL);
    lv_obj_set_event_cb(m_bt_calc,btRefreshEventHandler);
    lv_obj_set_size(m_bt_calc,100,30);
    lv_obj_set_pos(m_bt_calc,50,175);
    lv_btn_set_style(m_bt_calc,LV_BTN_STATE_REL,&m_calc_styleBtRefRel);
    lv_btn_set_style(m_bt_calc,LV_BTN_STATE_PR,&m_calc_styleBtRefPr);
    label = lv_label_create(m_bt_calc,NULL);
    lv_label_set_text(label,"rafraichir");


    /***********************************
     * Création et placement des cases *
     ***********************************/
    m_op1_calc = lv_btn_create(m_calc,NULL);
    lv_obj_set_size(m_op1_calc,50,50);
    lv_obj_set_pos(m_op1_calc,10,20);
    lv_btn_set_style(m_op1_calc,LV_BTN_STATE_REL,&lv_style_pretty);
    lv_btn_set_style(m_op1_calc,LV_BTN_STATE_PR,&lv_style_pretty);

    m_opr_calc = lv_btn_create(m_calc,NULL);
    lv_obj_set_size(m_opr_calc,50,50);
    lv_obj_set_pos(m_opr_calc,110,20);
    lv_btn_set_style(m_opr_calc,LV_BTN_STATE_REL,&lv_style_pretty);
    lv_btn_set_style(m_opr_calc,LV_BTN_STATE_PR,&lv_style_pretty);

    m_op2_calc = lv_btn_create(m_calc,NULL);
    lv_obj_set_size(m_op2_calc,50,50);
    lv_obj_set_pos(m_op2_calc,210,20);
    lv_btn_set_style(m_op2_calc,LV_BTN_STATE_REL,&lv_style_pretty);
    lv_btn_set_style(m_op2_calc,LV_BTN_STATE_PR,&lv_style_pretty);

    lv_obj_t* equal;
    m_eql_calc = lv_btn_create(m_calc,NULL);
    lv_obj_set_size(m_eql_calc,50,50);
    lv_obj_set_pos(m_eql_calc,310,20);
    lv_btn_set_style(m_eql_calc,LV_BTN_STATE_REL,&lv_style_pretty);
    lv_btn_set_style(m_eql_calc,LV_BTN_STATE_PR,&lv_style_pretty);
    equal = lv_label_create(m_eql_calc,NULL);
    lv_label_set_text(equal,"=");

    lv_obj_t* answer;
    m_res_calc = lv_btn_create(m_calc,NULL);
    lv_obj_set_size(m_res_calc,50,50);
    lv_obj_set_pos(m_res_calc,410,20);
    lv_btn_set_style(m_res_calc,LV_BTN_STATE_REL,&lv_style_pretty);
    lv_btn_set_style(m_res_calc,LV_BTN_STATE_PR,&lv_style_pretty);
    answer = lv_label_create(m_res_calc,NULL);
    lv_label_set_text(answer,"?");

    op1 = lv_label_create(m_op1_calc,NULL);
    operand = lv_label_create(m_opr_calc,NULL);
    op2 = lv_label_create(m_op2_calc,NULL);
    lv_label_set_text(operand,"");
    lv_label_set_text(op1,"");
    lv_label_set_text(op2,"");
}

void styleCalc(lv_obj_t* m_calc){

    /**********************
     * style du text area *
     **********************/
    lv_style_copy(&m_calc_styleTa, &lv_style_pretty);
    m_calc_styleTa.body.opa = LV_OPA_30;
    m_calc_styleTa.body.radius = 0;
    m_calc_styleTa.text.color = lv_color_hex3(0x222);

    /********************
     * style du clavier *
     ********************/
    lv_style_copy(&m_calc_styleKb, &lv_style_plain);
    m_calc_styleKb.body.opa = LV_OPA_70;
    m_calc_styleKb.body.main_color = lv_color_hex3(0x333);
    m_calc_styleKb.body.grad_color = lv_color_hex3(0x333);
    m_calc_styleKb.body.padding.left = 0;
    m_calc_styleKb.body.padding.right = 0;
    m_calc_styleKb.body.padding.top = 0;
    m_calc_styleKb.body.padding.bottom = 0;
    m_calc_styleKb.body.padding.inner = 0;

    /***************************************
     * style des bouton du clavier lorsque *
     * l'on appuis pas sur une touche      *
     ***************************************/
    lv_style_copy(&m_calc_styleKbRel, &lv_style_plain);
    m_calc_styleKbRel.body.opa = LV_OPA_TRANSP;
    m_calc_styleKbRel.body.radius = 0;
    m_calc_styleKbRel.body.border.width = 1;
    m_calc_styleKbRel.body.border.color = LV_COLOR_SILVER;
    m_calc_styleKbRel.body.border.opa = LV_OPA_50;
    m_calc_styleKbRel.body.main_color = lv_color_hex3(0x333);    /*Recommended if LV_VDB_SIZE == 0 and bpp > 1 fonts are used*/
    m_calc_styleKbRel.body.grad_color = lv_color_hex3(0x333);
    m_calc_styleKbRel.text.color = LV_COLOR_WHITE;

    /***************************************
     * style des bouton du clavier lorsque *
     * l'on appuis sur une touche          *
     ***************************************/
    lv_style_copy(&m_calc_styleKbPr, &lv_style_plain);
    m_calc_styleKbPr.body.radius = 0;
    m_calc_styleKbPr.body.opa = LV_OPA_50;
    m_calc_styleKbPr.body.main_color = LV_COLOR_WHITE;
    m_calc_styleKbPr.body.grad_color = LV_COLOR_WHITE;
    m_calc_styleKbPr.body.border.width = 1;
    m_calc_styleKbPr.body.border.color = LV_COLOR_SILVER;


    /**************************************
     * style du bouton rafraichir lorsque *
     * l'on apppuis pas desus             *
     **************************************/
    lv_style_copy(&m_calc_styleBtRefRel,&lv_style_btn_rel);
    m_calc_styleBtRefRel.body.main_color = lv_color_hex3(0x333);
    m_calc_styleBtRefRel.body.grad_color = LV_COLOR_BLACK;
    m_calc_styleBtRefRel.body.border.color = LV_COLOR_SILVER;
    m_calc_styleBtRefRel.body.border.width = 1;
    m_calc_styleBtRefRel.body.border.opa = LV_OPA_50;
    m_calc_styleBtRefRel.body.radius = 0;

    /**************************************
     * style du bouton rafraichir lorsque *
     * l'on apppuis  desus                *
     **************************************/
    lv_style_copy(&m_calc_styleBtRefPr, &m_calc_styleBtRefRel);
    m_calc_styleBtRefPr.body.main_color = lv_color_make(0x55, 0x96, 0xd8);
    m_calc_styleBtRefPr.body.grad_color = lv_color_make(0x37, 0x62, 0x90);
    m_calc_styleBtRefPr.text.color = lv_color_make(0xbb, 0xd5, 0xf1);

}

static void kbEventHandler(lv_obj_t* kb, lv_event_t event){

    lv_kb_def_event_cb(kb, event);
    /************************************
     * si nous appuiyons sur le bouton  *
     * CANCEL OU APPLY                  *
     ************************************/
    if(event == LV_EVENT_APPLY || event == LV_EVENT_CANCEL) {
        char data[3];
        lv_obj_t * parent = lv_obj_get_parent(lv_obj_get_parent(kb));
        strcpy(data,lv_ta_get_text(m_ta_calc));
        int value = atoi(data);
        if(reponse(value) == 0){
            m_mbox_calc = lv_mbox_create(parent,NULL);
            lv_mbox_set_text(m_mbox_calc,"vous avez gagne");
            static const char * mbox_btns[] = {"Ok", ""};
            lv_mbox_add_btns(m_mbox_calc, mbox_btns);    /*The default action is close*/
            lv_obj_set_size(m_mbox_calc,200,50);
            lv_obj_set_x(m_mbox_calc,200);
            lv_obj_set_y(m_mbox_calc,50);
            Greponse = generatCalcul();
        }
        else if(vie == 0){
            m_mbox_calc = lv_mbox_create(parent,NULL);
            lv_mbox_set_text(m_mbox_calc,"vous avez perdu");
            static const char * mbox_btns[] = {"Ok", ""};
            lv_mbox_add_btns(m_mbox_calc, mbox_btns);    /*The default action is close*/
            lv_obj_set_size(m_mbox_calc,200,50);
            lv_obj_set_x(m_mbox_calc,200);
            lv_obj_set_y(m_mbox_calc,50);
            Greponse = generatCalcul();
        }
        else{
            vie--;
            char badReply[30]; "Mauvaise réponse : 3 vie(s)";
            sprintf(badReply,"Mauvaise reponse : %d vie(s)",vie);
            m_mbox_calc = lv_mbox_create(parent,NULL);
            lv_mbox_set_text(m_mbox_calc,badReply);
            static const char * mbox_btns[] = {"Ok", ""};
            lv_mbox_add_btns(m_mbox_calc, mbox_btns);    /*The default action is close*/
            lv_obj_set_size(m_mbox_calc,200,50);
            lv_obj_set_x(m_mbox_calc,200);
            lv_obj_set_y(m_mbox_calc,50);
        }
        lv_ta_set_text(m_ta_calc,"");
    }
}

static void btRefreshEventHandler(lv_obj_t* bt,lv_event_t event){
    if(event == LV_EVENT_CLICKED){
        Greponse = generatCalcul();
    }
}

int generatCalcul(){
    int a = 0;
    int b = 0;
    int c = 0;
    vie = 3;

    srand (time(NULL));
    a = rand()%11;
    b = rand()%11;
    c = rand()%3;

    return displayCalcul(a,b,c);
}

int displayCalcul(int a,int b,int c){
    char c_a[2];
    char c_b[2];
    strcpy(c_a,"\0");
    strcpy(c_b,"\0");

    sprintf(c_a,"%d",a);
    sprintf(c_b,"%d",b);


    lv_label_set_text(op1,c_a);
    lv_label_set_text(op2,c_b);

    if(c==0){
        lv_label_set_text(operand,"+");
        return  a + b;
    } else if(c==1){
        lv_label_set_text(operand,"-");
        return  a - b;
    } else {
        lv_label_set_text(operand,"*");
        return a * b;
    }

}

int reponse(int data){
    if(data == Greponse){
        return 0;
    }
    return -1;
}


