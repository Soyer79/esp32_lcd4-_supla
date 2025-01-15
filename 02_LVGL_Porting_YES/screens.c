#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_main(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_main_btn_0_next(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_CLICKED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr1_btn_1_next(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_CLICKED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr1_btn_1_back(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_CLICKED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr1_rly_1_brama1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_CLICKED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr1_rly_1_brama2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_CLICKED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr1_btn_0_sleep(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr2_rly_2_lampa1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr2_rly_2_lampa2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr2_btn_2_back(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_CLICKED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr2_btn_2_next(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_CLICKED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr3_btn_3_update(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr3_btn_3_back(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_CLICKED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr3_btn_3_reset(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr4_btn_4_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr4_btn_4_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr4_btn_4_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr4_btn_4_5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr4_btn_4_4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr4_btn_4_6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr4_btn_4_8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr4_btn_4_7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr4_btn_4_9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr4_btn_4_0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr4_btn_4_back(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_CLICKED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr5_scr5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr5_btn_5_sleep(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr6_btn_6_main(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

static void event_handler_cb_scr7_btn_7_main(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_akcja(e);
    }
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_main_main, LV_EVENT_ALL, 0);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0df567), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // lbl_0_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_0_1 = obj;
            lv_obj_set_pos(obj, 344, 3);
            lv_obj_set_size(obj, 133, 33);
            lv_label_set_text(obj, "created by Soyer");
            lv_obj_set_style_text_opa(obj, 110, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 13, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_0_next
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_0_next = obj;
            lv_obj_set_pos(obj, 400, 430);
            lv_obj_set_size(obj, 70, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_main_btn_0_next, LV_EVENT_ALL, 0);
            apply_style_next(obj);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfffa0505), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0ec63c), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Dalej");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // cont_0_temp
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.cont_0_temp = obj;
            lv_obj_set_pos(obj, 100, 80);
            lv_obj_set_size(obj, 280, 110);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff14ff78), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff0a890a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 73, -10);
                    lv_obj_set_size(obj, 104, 30);
                    lv_label_set_text(obj, "Temperatura:");
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // cont_0_wind
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.cont_0_wind = obj;
            lv_obj_set_pos(obj, 98, 319);
            lv_obj_set_size(obj, 280, 110);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff14ff78), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff0a890a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 214, 330);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Wiatr:");
            lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // lbl_0_wind
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_0_wind = obj;
            lv_obj_set_pos(obj, 110, 340);
            lv_obj_set_size(obj, 263, 70);
            lv_label_set_text(obj, "12 km/h");
            lv_obj_set_style_text_font(obj, &ui_font_oswald_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 1, LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // lbl_0_date
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_0_date = obj;
            lv_obj_set_pos(obj, 11, 5);
            lv_obj_set_size(obj, 244, 28);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
            lv_label_set_text(obj, "Witam, Niedziela   11 Styczeń   2021        ");
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // lbl_0_time
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_0_time = obj;
            lv_obj_set_pos(obj, 126, 33);
            lv_obj_set_size(obj, 228, 39);
            lv_label_set_text(obj, "16:23:45");
            lv_obj_set_style_text_font(obj, &ui_font_time_32, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff0a890a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffff0207), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // lbl_0_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_0_temp = obj;
            lv_obj_set_pos(obj, 120, 110);
            lv_obj_set_size(obj, 240, 63);
            lv_label_set_text(obj, "-0.5*C");
            lv_obj_set_style_text_font(obj, &ui_font_oswald_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff212121), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // cont_0_air
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.cont_0_air = obj;
            lv_obj_set_pos(obj, 98, 200);
            lv_obj_set_size(obj, 280, 110);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff0a890a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff14ff78), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 170, 210);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Jakość powietrza:");
            lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // lbl_0_air
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_0_air = obj;
            lv_obj_set_pos(obj, 119, 240);
            lv_obj_set_size(obj, 240, 52);
            lv_label_set_text(obj, "OK");
            lv_obj_set_style_text_font(obj, &ui_font_oswald_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // lbl_0_alert
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_0_alert = obj;
            lv_obj_set_pos(obj, 152, 440);
            lv_obj_set_size(obj, 182, 30);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
            lv_label_set_text(obj, "Ładuję dane z serwera...      ");
            lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff0059ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 11, 406);
            lv_obj_set_size(obj, 64, 64);
            lv_img_set_src(obj, &img_t);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff0a890a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_main() {
}

void create_screen_scr1() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.scr1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    apply_style_back1(obj);
    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // btn_1_next
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_1_next = obj;
            lv_obj_set_pos(obj, 400, 430);
            lv_obj_set_size(obj, 70, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_scr1_btn_1_next, LV_EVENT_ALL, 0);
            apply_style_next(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0ec63c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfffa0505), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Dalej");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btn_1_back
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_1_back = obj;
            lv_obj_set_pos(obj, 10, 430);
            lv_obj_set_size(obj, 70, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_scr1_btn_1_back, LV_EVENT_ALL, 0);
            apply_style_next(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0ec63c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfffa0505), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Wstecz");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // rly_1_brama1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.rly_1_brama1 = obj;
            lv_obj_set_pos(obj, 73, 95);
            lv_obj_set_size(obj, 335, 110);
            lv_obj_add_event_cb(obj, event_handler_cb_scr1_rly_1_brama1, LV_EVENT_ALL, 0);
            apply_style_button_rly(obj);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfffa0505), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff14ff78), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 4, -3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Brama wjazdowa");
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lbl_1_brama1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_1_brama1 = obj;
                    lv_obj_set_pos(obj, 0, 32);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "ZAMKNIĘTA");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // rly_1_brama2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.rly_1_brama2 = obj;
            lv_obj_set_pos(obj, 73, 240);
            lv_obj_set_size(obj, 335, 110);
            lv_obj_add_event_cb(obj, event_handler_cb_scr1_rly_1_brama2, LV_EVENT_ALL, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff14ff78), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfffa0505), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lbl_1_brama2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_1_brama2 = obj;
                    lv_obj_set_pos(obj, -4, 31);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "ZAMKNIĘTA");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // lbl_0_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_0_2 = obj;
            lv_obj_set_pos(obj, 338, 13);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "created by Soyer");
            lv_obj_set_style_text_opa(obj, 90, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 95, 249);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Brama garażowa");
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_oswald_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_0_sleep
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_0_sleep = obj;
            lv_obj_set_pos(obj, 191, 430);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_scr1_btn_0_sleep, LV_EVENT_ALL, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0df567), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 209, 14);
            lv_obj_set_size(obj, 64, 64);
            lv_img_set_src(obj, &img_t);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_scr1() {
}

void create_screen_scr2() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.scr2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    apply_style_back1(obj);
    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // rly_2_lampa1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.rly_2_lampa1 = obj;
            lv_obj_set_pos(obj, 73, 95);
            lv_obj_set_size(obj, 335, 110);
            lv_obj_add_event_cb(obj, event_handler_cb_scr2_rly_2_lampa1, LV_EVENT_ALL, 0);
            apply_style_button_rly(obj);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfffa0505), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff14ff78), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lbl_2_lampa1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_2_lampa1 = obj;
                    lv_obj_set_pos(obj, 0, 30);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "WYŁĄCZONE");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // rly_2_lampa2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.rly_2_lampa2 = obj;
            lv_obj_set_pos(obj, 73, 240);
            lv_obj_set_size(obj, 335, 110);
            lv_obj_add_event_cb(obj, event_handler_cb_scr2_rly_2_lampa2, LV_EVENT_ALL, 0);
            apply_style_button_rly(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff14ff78), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfffa0505), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lbl_2_lampa2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_2_lampa2 = obj;
                    lv_obj_set_pos(obj, 1, 31);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "WYŁĄCZONE");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // lbl_0_3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_0_3 = obj;
            lv_obj_set_pos(obj, 338, 13);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "created by Soyer");
            lv_obj_set_style_text_opa(obj, 90, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 82, 100);
            lv_obj_set_size(obj, 316, 71);
            lv_label_set_text(obj, "Światło podjazd");
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_oswald_48, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 82, 249);
            lv_obj_set_size(obj, 316, 62);
            lv_label_set_text(obj, "Światło plac");
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_oswald_48, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_2_back
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_2_back = obj;
            lv_obj_set_pos(obj, 10, 430);
            lv_obj_set_size(obj, 70, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_scr2_btn_2_back, LV_EVENT_ALL, 0);
            apply_style_next(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfffa0505), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Wstecz");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btn_2_next
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_2_next = obj;
            lv_obj_set_pos(obj, 400, 430);
            lv_obj_set_size(obj, 70, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_scr2_btn_2_next, LV_EVENT_ALL, 0);
            apply_style_next(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfffa0505), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Service");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 209, 14);
            lv_obj_set_size(obj, 64, 64);
            lv_img_set_src(obj, &img_t);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_scr2() {
}

void create_screen_scr3() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.scr3 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0df567), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // lbl_0_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_0_4 = obj;
            lv_obj_set_pos(obj, 338, 13);
            lv_obj_set_size(obj, 121, 16);
            lv_label_set_text(obj, "created by Soyer");
            lv_obj_set_style_text_opa(obj, 110, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_3_update
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_3_update = obj;
            lv_obj_set_pos(obj, 150, 63);
            lv_obj_set_size(obj, 180, 125);
            lv_obj_add_event_cb(obj, event_handler_cb_scr3_btn_3_update, LV_EVENT_ALL, 0);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfffa0404), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lbl_3_update
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_3_update = obj;
                    lv_obj_set_pos(obj, 1, 1);
                    lv_obj_set_size(obj, 131, 26);
                    lv_label_set_text(obj, "UPDATE");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btn_3_back
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_3_back = obj;
            lv_obj_set_pos(obj, 191, 397);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_scr3_btn_3_back, LV_EVENT_ALL, 0);
            apply_style_next(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfffa0505), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "GŁÓWNA");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btn_3_reset
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_3_reset = obj;
            lv_obj_set_pos(obj, 150, 250);
            lv_obj_set_size(obj, 180, 125);
            lv_obj_add_event_cb(obj, event_handler_cb_scr3_btn_3_reset, LV_EVENT_ALL, 0);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfffa0404), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -1, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "RESET ESP");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // lbl_3_alert
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_3_alert = obj;
            lv_obj_set_pos(obj, 28, 200);
            lv_obj_set_size(obj, 423, 35);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 13, 14);
            lv_obj_set_size(obj, 64, 64);
            lv_img_set_src(obj, &img_t);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfffa0404), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_scr3() {
}

void create_screen_scr4() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.scr4 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0df567), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // lbl_4_pin
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_4_pin = obj;
            lv_obj_set_pos(obj, 150, 41);
            lv_obj_set_size(obj, 183, 47);
            lv_label_set_text(obj, "****");
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_oswald_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // lbl_0_5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_0_5 = obj;
            lv_obj_set_pos(obj, 338, 13);
            lv_obj_set_size(obj, 121, 16);
            lv_label_set_text(obj, "created by Soyer");
            lv_obj_set_style_text_opa(obj, 110, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_4_2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_4_2 = obj;
            lv_obj_set_pos(obj, 203, 112);
            lv_obj_set_size(obj, 75, 75);
            lv_obj_add_event_cb(obj, event_handler_cb_scr4_btn_4_2, LV_EVENT_ALL, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0ec63c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "2");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btn_4_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_4_3 = obj;
            lv_obj_set_pos(obj, 301, 112);
            lv_obj_set_size(obj, 75, 75);
            lv_obj_add_event_cb(obj, event_handler_cb_scr4_btn_4_3, LV_EVENT_ALL, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0ec63c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "3");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btn_4_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_4_1 = obj;
            lv_obj_set_pos(obj, 107, 112);
            lv_obj_set_size(obj, 75, 75);
            lv_obj_add_event_cb(obj, event_handler_cb_scr4_btn_4_1, LV_EVENT_ALL, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0ec63c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "1");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btn_4_5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_4_5 = obj;
            lv_obj_set_pos(obj, 203, 203);
            lv_obj_set_size(obj, 75, 75);
            lv_obj_add_event_cb(obj, event_handler_cb_scr4_btn_4_5, LV_EVENT_ALL, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0ec63c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "5");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btn_4_4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_4_4 = obj;
            lv_obj_set_pos(obj, 107, 203);
            lv_obj_set_size(obj, 75, 75);
            lv_obj_add_event_cb(obj, event_handler_cb_scr4_btn_4_4, LV_EVENT_ALL, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0ec63c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "4");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btn_4_6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_4_6 = obj;
            lv_obj_set_pos(obj, 301, 203);
            lv_obj_set_size(obj, 75, 75);
            lv_obj_add_event_cb(obj, event_handler_cb_scr4_btn_4_6, LV_EVENT_ALL, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0ec63c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "6");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btn_4_8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_4_8 = obj;
            lv_obj_set_pos(obj, 203, 290);
            lv_obj_set_size(obj, 75, 75);
            lv_obj_add_event_cb(obj, event_handler_cb_scr4_btn_4_8, LV_EVENT_ALL, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0ec63c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "8");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btn_4_7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_4_7 = obj;
            lv_obj_set_pos(obj, 107, 290);
            lv_obj_set_size(obj, 75, 75);
            lv_obj_add_event_cb(obj, event_handler_cb_scr4_btn_4_7, LV_EVENT_ALL, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0ec63c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "7");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btn_4_9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_4_9 = obj;
            lv_obj_set_pos(obj, 301, 290);
            lv_obj_set_size(obj, 75, 75);
            lv_obj_add_event_cb(obj, event_handler_cb_scr4_btn_4_9, LV_EVENT_ALL, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0ec63c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "9");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btn_4_0
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_4_0 = obj;
            lv_obj_set_pos(obj, 203, 381);
            lv_obj_set_size(obj, 75, 75);
            lv_obj_add_event_cb(obj, event_handler_cb_scr4_btn_4_0, LV_EVENT_ALL, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0ec63c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // btn_4_back
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_4_back = obj;
            lv_obj_set_pos(obj, 10, 430);
            lv_obj_set_size(obj, 70, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_scr4_btn_4_back, LV_EVENT_ALL, 0);
            apply_style_next(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfffa0505), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Wstecz");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 10, 14);
            lv_obj_set_size(obj, 64, 64);
            lv_img_set_src(obj, &img_t);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_scr4() {
}

void create_screen_scr5() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.scr5 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_scr5_scr5, LV_EVENT_ALL, 0);
    {
        lv_obj_t *parent_obj = obj;
        {
            // btn_5_sleep
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_5_sleep = obj;
            lv_obj_set_pos(obj, 27, 95);
            lv_obj_set_size(obj, 427, 242);
            lv_obj_add_event_cb(obj, event_handler_cb_scr5_btn_5_sleep, LV_EVENT_ALL, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0df567), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfff60631), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 151, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
                    lv_label_set_text(obj, "         ");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_oswald_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfff80505), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 27, 377);
            lv_obj_set_size(obj, 427, 69);
            lv_obj_set_style_text_font(obj, &ui_font_oswald_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff60631), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff090000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff0df567), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
                    lv_label_set_text(obj, "Aby włączyć naciśnij RESET z boku urządzenia");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 96, 154);
            lv_obj_set_size(obj, 290, 144);
            lv_label_set_text(obj, "Kliknij tutaj aby wyłączyć ekran...        ");
            lv_obj_set_style_text_font(obj, &ui_font_oswald_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfff60631), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 208, 16);
            lv_obj_set_size(obj, 64, 64);
            lv_img_set_src(obj, &img_t);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfffa0404), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_scr5() {
}

void create_screen_scr6() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.scr6 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_dzieci);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // btn_6_main
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_6_main = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 480, 480);
                    lv_obj_add_event_cb(obj, event_handler_cb_scr6_btn_6_main, LV_EVENT_ALL, 0);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
            }
        }
    }
}

void tick_screen_scr6() {
}

void create_screen_scr7() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.scr7 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_proc);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // btn_7_main
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_7_main = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 480, 480);
                    lv_obj_add_event_cb(obj, event_handler_cb_scr7_btn_7_main, LV_EVENT_ALL, 0);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
            }
        }
    }
}

void tick_screen_scr7() {
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_scr1();
    create_screen_scr2();
    create_screen_scr3();
    create_screen_scr4();
    create_screen_scr5();
    create_screen_scr6();
    create_screen_scr7();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_scr1,
    tick_screen_scr2,
    tick_screen_scr3,
    tick_screen_scr4,
    tick_screen_scr5,
    tick_screen_scr6,
    tick_screen_scr7,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
