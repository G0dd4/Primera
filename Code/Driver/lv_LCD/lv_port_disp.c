/**
 * @file lv_port_disp_templ.c
 *
 */

 /*Copy this file as "lv_port_disp.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_disp.h"
#include "lvgl/lvgl.h"
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_sdram.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void disp_init(void);

static void disp_flush(lv_disp_drv_t* disp_drv, const lv_area_t* area, lv_color_t* color_p);

#if LV_USE_GPU
DMA2D_HandleTypeDef Dma2dHandle;
static void DMA2D_Config(void);
static void Error_Handler(void);
static void DMA2D_TransferComplete(DMA2D_HandleTypeDef *hdma2d);
static void DMA2D_TransferError(DMA2D_HandleTypeDef *hdma2d);
static void gpu_blend(lv_disp_drv_t * disp_drv,lv_color_t * dest, const lv_color_t * src, uint32_t length, lv_opa_t opa);
static void gpu_fill(lv_disp_drv_t * disp_drv,lv_color_t *  dest_buf, lv_coord_t dest_width, const lv_area_t * fill_area, lv_color_t color);
#endif

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_disp_init(void)
{
    /*-------------------------
     * Initialize your display
     * -----------------------*/
    disp_init();

    /*-----------------------------
     * Create a buffer for drawing
     *----------------------------*/

    /* LittlevGL requires a buffer where it draws the objects. The buffer's has to be greater than 1 display row
     *
     * There are three buffering configurations:
     * 1. Create ONE buffer with some rows: 
     *      LittlevGL will draw the display's content here and writes it to your display
     * 
     * 2. Create TWO buffer with some rows: 
     *      LittlevGL will draw the display's content to a buffer and writes it your display.
     *      You should use DMA to write the buffer's content to the display.
     *      It will enable LittlevGL to draw the next part of the screen to the other buffer while
     *      the data is being sent form the first buffer. It makes rendering and flushing parallel.
     * 
     * 3. Create TWO screen-sized buffer: 
     *      Similar to 2) but the buffer have to be screen sized. When LittlevGL is ready it will give the
     *      whole frame to display. This way you only need to change the frame buffer's address instead of
     *      copying the pixels.
     * */

    /* Example for 1) */
    static lv_disp_buf_t disp_buf_1;
    static lv_color_t buf1_1[LV_HOR_RES_MAX * 10];                      /*A buffer for 10 rows*/
    lv_disp_buf_init(&disp_buf_1, buf1_1, NULL, LV_HOR_RES_MAX * 10);   /*Initialize the display buffer*/

    /* Example for 2) */
    //static lv_disp_buf_t disp_buf_2;
    //static lv_color_t buf2_1[LV_HOR_RES_MAX * 10];                        /*A buffer for 10 rows*/
    //static lv_color_t buf2_2[LV_HOR_RES_MAX * 10];                        /*An other buffer for 10 rows*/
    //lv_disp_buf_init(&disp_buf_2, buf2_1, buf2_2, LV_HOR_RES_MAX * 10);   /*Initialize the display buffer*/

    /* Example for 3) */
    //static lv_disp_buf_t disp_buf_3;
    //static lv_color_t buf3_1[LV_HOR_RES_MAX * LV_VER_RES_MAX];            /*A screen sized buffer*/
    //static lv_color_t buf3_2[LV_HOR_RES_MAX * LV_VER_RES_MAX];            /*An other screen sized buffer*/
    //lv_disp_buf_init(&disp_buf_3, buf3_1, buf3_2, LV_HOR_RES_MAX * LV_VER_RES_MAX);   /*Initialize the display buffer*/


    /*-----------------------------------
     * Register the display in LittlevGL
     *----------------------------------*/

    lv_disp_drv_t disp_drv;                         /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);                    /*Basic initialization*/
    /*Set up the functions to access to your display*/
    /*Set the resolution of the display*/
    disp_drv.hor_res = 480;
    disp_drv.ver_res = 272;
    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = disp_flush;
    /*Set a display buffer*/
    disp_drv.buffer = &disp_buf_1;
#if LV_USE_GPU
    /*Optionally add functions to access the GPU. (Only in buffered mode, LV_VDB_SIZE != 0)*/
    DMA2D_Config();
    /*Blend two color array using opacity*/
    disp_drv.gpu_blend_cb = gpu_blend;
    /*Fill a memory array with a color*/
    disp_drv.gpu_fill_cb = gpu_fill;
#endif
    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* Initialize your display and the required peripherals. */
static void disp_init(void){
    /*You code here*/
    BSP_LCD_Init();
#if LV_COLOR_DEPTH == 16
    Dma2dHandle.LayerCfg[0].InputColorMode = DMA2D_INPUT_RGB565;
     BSP_LCD_LayerRgb565Init(1, LCD_FB_START_ADDRESS));
#elif LV_COLOR_DEPTH == 24 || LV_COLOR_DEPTH == 32
    BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);
#endif
    BSP_LCD_DisplayOn();
    BSP_LCD_SelectLayer(0);
}

/* Flush the content of the internal buffer the specific area on the display
 * You can use DMA or any hardware acceleration to do this operation in the background but
 * 'lv_disp_flush_ready()' has to be called when finished. */
static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p){
    //The most simple case (but also the slowest) to put all pixels to the screen one-by-one
    uint16_t x, y;
    for(y = area->y1; y <= area->y2; y++) {
        for(x = area->x1; x <= area->x2; x++) {
            //put_px(x, y, *color_p)
            BSP_LCD_DrawPixel( x, y, color_p->full);
            color_p++;
        }
    }
    // IMPORTANT!!!* Inform the graphics library that you are ready with the flushing
    lv_disp_flush_ready(disp_drv);
}


/*OPTIONAL: GPU INTERFACE*/
#if LV_USE_GPU

/* If your MCU has hardware accelerator (GPU) then you can use it to blend to memories using opacity
 * It can be used only in buffered mode (LV_VDB_SIZE != 0 in lv_conf.h)*/

static void DMA2D_Config(void){
    //onfigure the DMA2D Mode, Color Mode and output offset
    Dma2dHandle.Init.Mode         = DMA2D_M2M_BLEND;
#if LV_COLOR_DEPTH == 16
    Dma2dHandle.Init.ColorMode    = DMA2D_RGB565;
#elif LV_COLOR_DEPTH == 24 || LV_COLOR_DEPTH == 32
    Dma2dHandle.Init.ColorMode    = DMA2D_ARGB8888;
#endif
    Dma2dHandle.Init.OutputOffset = 0x0;
    //DMA2D Callbacks Configuration
    Dma2dHandle.XferCpltCallback  = DMA2D_TransferComplete;
    Dma2dHandle.XferErrorCallback = DMA2D_TransferError;
    //Foreground Configuration
    Dma2dHandle.LayerCfg[1].AlphaMode = DMA2D_REPLACE_ALPHA;
    Dma2dHandle.LayerCfg[1].InputAlpha = 0xFF;
#if LV_COLOR_DEPTH == 16
    Dma2dHandle.LayerCfg[1].InputColorMode = DMA2D_INPUT_RGB565;
#elif LV_COLOR_DEPTH == 24 || LV_COLOR_DEPTH == 32
    Dma2dHandle.LayerCfg[1].InputColorMode = DMA2D_INPUT_ARGB8888;
#endif
    Dma2dHandle.LayerCfg[1].InputOffset = 0x0;
    //Background Configuration 
    Dma2dHandle.LayerCfg[0].AlphaMode = DMA2D_REPLACE_ALPHA;
    Dma2dHandle.LayerCfg[0].InputAlpha = 0xFF;
#if LV_COLOR_DEPTH == 16
    Dma2dHandle.LayerCfg[0].InputColorMode = DMA2D_INPUT_RGB565;
#elif LV_COLOR_DEPTH == 24 || LV_COLOR_DEPTH == 32
    Dma2dHandle.LayerCfg[0].InputColorMode = DMA2D_INPUT_ARGB8888;
#endif
    Dma2dHandle.LayerCfg[0].InputOffset = 0x0;
    Dma2dHandle.Instance   = DMA2D;
    //DMA2D Initialization
    if(HAL_DMA2D_Init(&Dma2dHandle) != HAL_OK){
        Error_Handler();// Initialization Error 
    }
    HAL_DMA2D_ConfigLayer(&Dma2dHandle, 0);
    HAL_DMA2D_ConfigLayer(&Dma2dHandle, 1);
}

static void gpu_blend(lv_disp_drv_t * disp_drv, lv_color_t * dest, const lv_color_t * src, uint32_t length, lv_opa_t opa){
    /*Wait for the previous operation*/
    HAL_DMA2D_PollForTransfer(&Dma2dHandle, 100);
    Dma2dHandle.Init.Mode         = DMA2D_M2M_BLEND;
    /* DMA2D Initialization */
    if(HAL_DMA2D_Init(&Dma2dHandle) != HAL_OK){
        /* Initialization Error */
        while(1);
    }
    Dma2dHandle.LayerCfg[1].InputAlpha = opa;
    HAL_DMA2D_ConfigLayer(&Dma2dHandle, 1);
    HAL_DMA2D_BlendingStart(&Dma2dHandle, (uint32_t) src, (uint32_t) dest, (uint32_t)dest, length, 1);
}

/* If your MCU has hardware accelerator (GPU) then you can use it to fill a memory with a color
 * It can be used only in buffered mode (LV_VDB_SIZE != 0 in lv_conf.h)*/
static void gpu_fill(lv_disp_drv_t * disp_drv, lv_color_t * dest_buf, lv_coord_t dest_width, const lv_area_t * fill_area, lv_color_t color){
    /*Wait for the previous operation*/
    HAL_DMA2D_PollForTransfer(&Dma2dHandle, 100);
    Dma2dHandle.Init.Mode         = DMA2D_R2M;
   /* DMA2D Initialization */
   if(HAL_DMA2D_Init(&Dma2dHandle) != HAL_OK){
     /* Initialization Error */
     while(1);
   }
   Dma2dHandle.LayerCfg[1].InputAlpha = 0xff;
   HAL_DMA2D_ConfigLayer(&Dma2dHandle, 1);
   lv_color_t * dest_buf_ofs = dest_buf;
   dest_buf_ofs += dest_width * fill_area->y1;
   dest_buf_ofs += fill_area->x1;
   lv_coord_t area_w = lv_area_get_width(fill_area);
   uint32_t i;
   for(i = fill_area->y1; i <= fill_area->y2; i++) {
       /*Wait for the previous operation*/
       HAL_DMA2D_PollForTransfer(&Dma2dHandle, 100);
       HAL_DMA2D_BlendingStart(&Dma2dHandle, (uint32_t) lv_color_to32(color), (uint32_t) dest_buf_ofs, (uint32_t)dest_buf_ofs, area_w, 1);
       dest_buf_ofs += dest_width;
   }
}

static void Error_Handler(void){
    while(1){}
}

static void DMA2D_TransferComplete(DMA2D_HandleTypeDef *hdma2d){

}

static void DMA2D_TransferError(DMA2D_HandleTypeDef *hdma2d){
    
}

#endif  /*LV_USE_GPU*/

#else /* Enable this file at the top */

/* This dummy typedef exists purely to silence -Wpedantic. */
typedef int keep_pedantic_happy;
#endif

