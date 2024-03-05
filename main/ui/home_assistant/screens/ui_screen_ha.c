// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: ASIS

#include "../ui.h"

void ui_screen_ha_screen_init(void)
{
ui_screen_ha = lv_obj_create(NULL);
lv_obj_clear_flag( ui_screen_ha, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_screen_ha, lv_color_hex(0x1C1C1C), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_screen_ha, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ha_wifi_btn = lv_btn_create(ui_screen_ha);
lv_obj_set_width( ui_ha_wifi_btn, 60);
lv_obj_set_height( ui_ha_wifi_btn, 60);
lv_obj_set_x( ui_ha_wifi_btn, -10 );
lv_obj_set_y( ui_ha_wifi_btn, 10 );
lv_obj_set_align( ui_ha_wifi_btn, LV_ALIGN_TOP_RIGHT );
lv_obj_add_flag( ui_ha_wifi_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_ha_wifi_btn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ha_wifi_btn, lv_color_hex(0x1C1C1C), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ha_wifi_btn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_color(ui_ha_wifi_btn, lv_color_hex(0x1C1C1C), LV_PART_MAIN | LV_STATE_DEFAULT );

ui_ha_wifi_st = lv_img_create(ui_ha_wifi_btn);
lv_img_set_src(ui_ha_wifi_st, &ui_img_wifi_disconet_png);
lv_obj_set_width( ui_ha_wifi_st, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_ha_wifi_st, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_ha_wifi_st, LV_ALIGN_TOP_RIGHT );
lv_obj_add_flag( ui_ha_wifi_st, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_ha_wifi_st, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_ha_time = lv_label_create(ui_screen_ha);
lv_obj_set_width( ui_ha_time, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_ha_time, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_ha_time, 30 );
lv_obj_set_y( ui_ha_time, 20 );
lv_label_set_text(ui_ha_time,"21:20");
lv_obj_set_style_text_font(ui_ha_time, &ui_font_font1, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_screen_home_none_lable = lv_label_create(ui_screen_ha);
lv_obj_set_width( ui_screen_home_none_lable, 316);
lv_obj_set_height( ui_screen_home_none_lable, 38);
lv_obj_set_x( ui_screen_home_none_lable, 82 );
lv_obj_set_y( ui_screen_home_none_lable, 58 );
lv_label_set_text(ui_screen_home_none_lable,"9B STU & 9B IAG\n");
lv_obj_set_style_text_color(ui_screen_home_none_lable, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_screen_home_none_lable, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_screen_home_none_lable, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_screen_home_none_lable, &ui_font_font0, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_iag_all_btn = lv_btn_create(ui_screen_ha);
lv_obj_set_width( ui_iag_all_btn, 214);
lv_obj_set_height( ui_iag_all_btn, 164);
lv_obj_set_x( ui_iag_all_btn, 244 );
lv_obj_set_y( ui_iag_all_btn, 96 );
lv_obj_add_flag( ui_iag_all_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_iag_all_btn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_iag_all_btn, 12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_iag_all_btn, lv_color_hex(0x282828), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_iag_all_btn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_add_flag(ui_iag_all_btn, LV_OBJ_FLAG_CHECKABLE);


ui_iag_all_logo = lv_img_create(ui_iag_all_btn);
lv_img_set_src(ui_iag_all_logo, &ui_img_ic_switch2_on_png);
lv_obj_set_width( ui_iag_all_logo, LV_SIZE_CONTENT);  /// 45
lv_obj_set_height( ui_iag_all_logo, LV_SIZE_CONTENT);   /// 45
lv_obj_set_x( ui_iag_all_logo, 40 );
lv_obj_set_y( ui_iag_all_logo, 6 );
lv_obj_add_flag( ui_iag_all_logo, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_iag_all_logo, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_iag_all_label = lv_label_create(ui_iag_all_btn);
lv_obj_set_width( ui_iag_all_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_iag_all_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_iag_all_label, 0 );
lv_obj_set_y( ui_iag_all_label, -5 );
lv_obj_set_align( ui_iag_all_label, LV_ALIGN_BOTTOM_MID );
lv_label_set_text(ui_iag_all_label, CONFIG_SENSOR6_UI_NAME);
lv_obj_set_style_text_color(ui_iag_all_label, lv_color_hex(0x9E9E9E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_iag_all_label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_iag_all_label, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);


ui_iag_01_btn = lv_btn_create(ui_screen_ha);
lv_obj_set_width( ui_iag_01_btn, 214);
lv_obj_set_height( ui_iag_01_btn, 78);
lv_obj_set_x( ui_iag_01_btn, 244 );
lv_obj_set_y( ui_iag_01_btn, 268 );
lv_obj_add_flag( ui_iag_01_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_iag_01_btn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_iag_01_btn, 15, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_iag_01_btn, 20, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_bg_color(ui_iag_01_btn, lv_color_hex(0x282828), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_iag_01_btn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_iag_01_btn, lv_color_hex(0x3E3E3E), LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_bg_opa(ui_iag_01_btn, 255, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_add_flag(ui_iag_01_btn, LV_OBJ_FLAG_CHECKABLE);

ui_iag_01_logo = lv_img_create(ui_iag_01_btn);
lv_img_set_src(ui_iag_01_logo, &ui_img_ic_switch1_off_png);
lv_obj_set_x( ui_iag_01_logo, 120 );
lv_obj_set_y( ui_iag_01_logo, 2 );
lv_obj_add_flag( ui_iag_01_logo, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_iag_01_logo, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_iag_01_label = lv_label_create(ui_iag_01_btn);
lv_obj_set_width( ui_iag_01_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_iag_01_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_iag_01_label, 16 );
lv_obj_set_y( ui_iag_01_label, 22 );
lv_label_set_text(ui_iag_01_label, CONFIG_IAG_01_UI_NAME);
lv_obj_set_style_text_color(ui_iag_01_label, lv_color_hex(0x9E9E9E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_iag_01_label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_iag_01_label, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);


ui_iag_02_btn = lv_btn_create(ui_screen_ha);
lv_obj_set_width( ui_iag_02_btn, 214);
lv_obj_set_height( ui_iag_02_btn, 78);
lv_obj_set_x( ui_iag_02_btn, 244 );
lv_obj_set_y( ui_iag_02_btn, 354 );
lv_obj_add_flag( ui_iag_02_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_iag_02_btn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_iag_02_btn, 15, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_iag_02_btn, 20, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_bg_color(ui_iag_02_btn, lv_color_hex(0x282828), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_iag_02_btn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_iag_02_btn, lv_color_hex(0x3E3E3E), LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_bg_opa(ui_iag_02_btn, 255, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_add_flag(ui_iag_02_btn, LV_OBJ_FLAG_CHECKABLE);

ui_iag_02_logo = lv_img_create(ui_iag_02_btn);
lv_img_set_src(ui_iag_02_logo, &ui_img_ic_switch1_off_png);
lv_obj_set_x( ui_iag_02_logo, 120 );
lv_obj_set_y( ui_iag_02_logo, 2 );
lv_obj_add_flag( ui_iag_02_logo, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_iag_02_logo, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_iag_02_label = lv_label_create(ui_iag_02_btn);
lv_obj_set_width( ui_iag_02_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_iag_02_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_iag_02_label, 16 );
lv_obj_set_y( ui_iag_02_label, 22 );
lv_label_set_text(ui_iag_02_label, CONFIG_IAG_02_UI_NAME);
lv_obj_set_style_text_color(ui_iag_02_label, lv_color_hex(0x9E9E9E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_iag_02_label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_iag_02_label, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);




ui_stu_all_btn = lv_btn_create(ui_screen_ha);
lv_obj_set_width( ui_stu_all_btn, 214);
lv_obj_set_height( ui_stu_all_btn, 164);
lv_obj_set_x( ui_stu_all_btn, 22 );
lv_obj_set_y( ui_stu_all_btn, 96 );
lv_obj_add_flag( ui_stu_all_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_stu_all_btn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_stu_all_btn, 15, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_stu_all_btn, 20, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_bg_color(ui_stu_all_btn, lv_color_hex(0x282828), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_stu_all_btn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_stu_all_btn, lv_color_hex(0x3E3E3E), LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_bg_opa(ui_stu_all_btn, 255, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_add_flag(ui_stu_all_btn, LV_OBJ_FLAG_CHECKABLE);


ui_stu_all_logo = lv_img_create(ui_stu_all_btn);
lv_img_set_src(ui_stu_all_logo, &ui_img_ic_switch2_off_png);
lv_obj_set_width( ui_stu_all_logo, LV_SIZE_CONTENT);  /// 45
lv_obj_set_height( ui_stu_all_logo, LV_SIZE_CONTENT);   /// 45
lv_obj_set_x( ui_stu_all_logo, 40 );
lv_obj_set_y( ui_stu_all_logo, 6 );
lv_obj_add_flag( ui_stu_all_logo, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_stu_all_logo, LV_OBJ_FLAG_SCROLLABLE );    /// Flags


ui_stu_all_label = lv_label_create(ui_stu_all_btn);
lv_obj_set_width( ui_stu_all_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_stu_all_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_stu_all_label, 0 );
lv_obj_set_y( ui_stu_all_label, -5 );
lv_obj_set_align( ui_stu_all_label, LV_ALIGN_BOTTOM_MID );
lv_label_set_text(ui_stu_all_label, CONFIG_SWITCH1_UI_NAME);
lv_obj_set_style_text_color(ui_stu_all_label, lv_color_hex(0x9E9E9E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_stu_all_label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_stu_all_label, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);


ui_stu_01_btn = lv_btn_create(ui_screen_ha);
lv_obj_set_width( ui_stu_01_btn, 214);
lv_obj_set_height( ui_stu_01_btn, 78);
lv_obj_set_x( ui_stu_01_btn, 22 );
lv_obj_set_y( ui_stu_01_btn, 268 );
lv_obj_add_flag( ui_stu_01_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_stu_01_btn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_stu_01_btn, 15, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_stu_01_btn, 20, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_bg_color(ui_stu_01_btn, lv_color_hex(0x282828), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_stu_01_btn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_stu_01_btn, lv_color_hex(0x3E3E3E), LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_bg_opa(ui_stu_01_btn, 255, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_add_flag(ui_stu_01_btn, LV_OBJ_FLAG_CHECKABLE);

ui_stu_01_logo = lv_img_create(ui_stu_01_btn);
lv_img_set_src(ui_stu_01_logo, &ui_img_ic_switch1_off_png);
lv_obj_set_x( ui_stu_01_logo, 120 );
lv_obj_set_y( ui_stu_01_logo, 2 );
lv_obj_add_flag( ui_stu_01_logo, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_stu_01_logo, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_stu_01_label = lv_label_create(ui_stu_01_btn);
lv_obj_set_width( ui_stu_01_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_stu_01_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_stu_01_label, 16 );
lv_obj_set_y( ui_stu_01_label, 22 );
lv_label_set_text(ui_stu_01_label, CONFIG_SWITCH2_UI_NAME);
lv_obj_set_style_text_color(ui_stu_01_label, lv_color_hex(0x9E9E9E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_stu_01_label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_stu_01_label, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_stu_03_btn = lv_btn_create(ui_screen_ha);
lv_obj_set_width( ui_stu_03_btn, 214);
lv_obj_set_height( ui_stu_03_btn, 78);
lv_obj_set_x( ui_stu_03_btn, 22 );
lv_obj_set_y( ui_stu_03_btn, 354 );
lv_obj_add_flag( ui_stu_03_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_stu_03_btn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_stu_03_btn, 15, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_stu_03_btn, 20, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_bg_color(ui_stu_03_btn, lv_color_hex(0x282828), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_stu_03_btn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_stu_03_btn, lv_color_hex(0x3E3E3E), LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_bg_opa(ui_stu_03_btn, 255, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_add_flag(ui_stu_03_btn, LV_OBJ_FLAG_CHECKABLE);

ui_stu_03_logo = lv_img_create(ui_stu_03_btn);
lv_img_set_src(ui_stu_03_logo, &ui_img_ic_switch1_off_png);
lv_obj_set_x( ui_stu_03_logo, 120 );
lv_obj_set_y( ui_stu_03_logo, 2 );
lv_obj_add_flag( ui_stu_03_logo, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_stu_03_logo, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_stu_03_label = lv_label_create(ui_stu_03_btn);
lv_obj_set_width( ui_stu_03_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_stu_03_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_stu_03_label, 16 );
lv_obj_set_y( ui_stu_03_label, 22 );
lv_label_set_text(ui_stu_03_label, CONFIG_SWITCH3_UI_NAME);
lv_obj_set_style_text_color(ui_stu_03_label, lv_color_hex(0x9E9E9E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_stu_03_label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_stu_03_label, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);


creat_scrolldots(ui_screen_ha, 3);

}
