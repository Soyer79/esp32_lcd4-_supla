#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *scr1;
    lv_obj_t *scr2;
    lv_obj_t *scr3;
    lv_obj_t *scr4;
    lv_obj_t *scr5;
    lv_obj_t *scr6;
    lv_obj_t *scr7;
    lv_obj_t *btn_0_next;
    lv_obj_t *btn_0_sleep;
    lv_obj_t *btn_1_back;
    lv_obj_t *btn_1_next;
    lv_obj_t *btn_2_back;
    lv_obj_t *btn_2_next;
    lv_obj_t *btn_3_back;
    lv_obj_t *btn_3_reset;
    lv_obj_t *btn_3_update;
    lv_obj_t *btn_4_0;
    lv_obj_t *btn_4_1;
    lv_obj_t *btn_4_2;
    lv_obj_t *btn_4_3;
    lv_obj_t *btn_4_4;
    lv_obj_t *btn_4_5;
    lv_obj_t *btn_4_6;
    lv_obj_t *btn_4_7;
    lv_obj_t *btn_4_8;
    lv_obj_t *btn_4_9;
    lv_obj_t *btn_4_back;
    lv_obj_t *btn_5_sleep;
    lv_obj_t *btn_6_main;
    lv_obj_t *btn_7_main;
    lv_obj_t *cont_0_air;
    lv_obj_t *cont_0_temp;
    lv_obj_t *cont_0_wind;
    lv_obj_t *lbl_0_1;
    lv_obj_t *lbl_0_2;
    lv_obj_t *lbl_0_3;
    lv_obj_t *lbl_0_4;
    lv_obj_t *lbl_0_5;
    lv_obj_t *lbl_0_air;
    lv_obj_t *lbl_0_alert;
    lv_obj_t *lbl_0_date;
    lv_obj_t *lbl_0_temp;
    lv_obj_t *lbl_0_time;
    lv_obj_t *lbl_0_wind;
    lv_obj_t *lbl_1_brama1;
    lv_obj_t *lbl_1_brama2;
    lv_obj_t *lbl_2_lampa1;
    lv_obj_t *lbl_2_lampa2;
    lv_obj_t *lbl_3_alert;
    lv_obj_t *lbl_3_update;
    lv_obj_t *lbl_4_pin;
    lv_obj_t *rly_1_brama1;
    lv_obj_t *rly_1_brama2;
    lv_obj_t *rly_2_lampa1;
    lv_obj_t *rly_2_lampa2;
    lv_obj_t *qr1;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_SCR1 = 2,
    SCREEN_ID_SCR2 = 3,
    SCREEN_ID_SCR3 = 4,
    SCREEN_ID_SCR4 = 5,
    SCREEN_ID_SCR5 = 6,
    SCREEN_ID_SCR6 = 7,
    SCREEN_ID_SCR7 = 8,
};

void create_screen_main();
void tick_screen_main();

void create_screen_scr1();
void tick_screen_scr1();

void create_screen_scr2();
void tick_screen_scr2();

void create_screen_scr3();
void tick_screen_scr3();

void create_screen_scr4();
void tick_screen_scr4();

void create_screen_scr5();
void tick_screen_scr5();

void create_screen_scr6();
void tick_screen_scr6();

void create_screen_scr7();
void tick_screen_scr7();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/