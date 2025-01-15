#include "styles.h"
#include "images.h"
#include "fonts.h"

void apply_style_next(lv_obj_t *obj) {
    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0ec63c), LV_PART_MAIN | LV_STATE_DEFAULT);
};
void apply_style_button_rly(lv_obj_t *obj) {
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff14ff78), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
};
void apply_style_back1(lv_obj_t *obj) {
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0df567), LV_PART_MAIN | LV_STATE_DEFAULT);
};

