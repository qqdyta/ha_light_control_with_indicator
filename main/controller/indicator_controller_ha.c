#include "indicator_controller_ha.h"
#include "lvgl.h"
#include "ui.h"
#include "indicator_view.h"
#include "ui_helpers.h"
#include <time.h>
#include <sys/time.h>
#include "esp_tls.h"
#include "esp_http_client.h"
#include <string.h>
#include "config.h"
static const char *TAG = "controller-ha";

#define MAX_HTTP_RECV_BUFFER 512
#define MAX_HTTP_OUTPUT_BUFFER 2048

static const char *TOKEN = "Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJhNjBkYzkzMjViOTE0ZDFmOTEwN2ZhM2EzNDM4ZWUwMyIsImlhdCI6MTcwNDMzMTY2OCwiZXhwIjoyMDE5NjkxNjY4fQ.YH1jnG7FLiP0yW1kvrLVncmJ0qase8axFnirTYm316o";
static const char *ON_URL =  "http://192.168.12.253:8123/api/services/switch/turn_on";
static const char *OFF_URL = "http://192.168.12.253:8123/api/services/switch/turn_off";
static const char *STU_TEST_01_LIGHT = "switch.9b_stu_test_switch_1";
static const char *STU_TEST_02_LIGHT = "switch.9b_stu_test_switch_2";
static const char *STU_TEST_03_LIGHT = "switch.9b_stu_test_switch_3";
static const char *STU_TEST_04_LIGHT = "switch.9b_stu_test_switch_4";
static const char *IAG_01_LIGHT_1 = "switch.iag_01_switch_1";
static const char *IAG_01_LIGHT_2 = "switch.iag_01_switch_2";
static const char *IAG_01_LIGHT_3 = "switch.iag_01_switch_3";
static const char *IAG_01_LIGHT_4 = "switch.iag_01_switch_4";

static const char *FRONT_1 = "switch.front_1_switch_1";
static const char *FRONT_2 = "switch.front_1_switch_2";
static const char *FRONT_3 = "switch.front_1_switch_3";
static const char *FRONT_4 = "switch.front_1_switch_4";

static const char *REST_1 = "switch.rest_1_switch_1";
static const char *REST_2 = "switch.rest_1_switch_2";
static const char *REST_3 = "switch.rest_1_switch_3";
static const char *REST_4 = "switch.rest_1_switch_4";



static const char *COM_1 = "switch.com_1_switch_1";

static const char *HR_1 = "switch.hr_1_switch_1";
static const char *HR_2 = "switch.hr_1_switch_2";




static const char *REST_1_LIGHT = "switch.rest_1_switch_1";
static const char *REST_2_LIGHT = "switch.rest_1_switch_2";
static const char *REST_3_LIGHT = "switch.rest_1_switch_3";
static const char *REST_4_LIGHT = "switch.rest_1_switch_4";

static const char *T_1_LIGHT = "switch.trainingroomlight_switch_1";
static const char *T_2_LIGHT = "switch.trainingroomlight_switch_2";
static const char *T_3_LIGHT = "switch.trainingroomlight_switch_3";


static const char *FIN_ROAD_LIGHT = "switch.fin_road_switch_1";
static const char *FIN_ROAD_LIGHT_2 = "switch.fin_road_switch_2";



esp_err_t _http_event_handler(esp_http_client_event_t *evt) {
    switch(evt->event_id) {
        case HTTP_EVENT_ERROR:
            ESP_LOGE(TAG, "HTTP_EVENT_ERROR");
            break;
        case HTTP_EVENT_ON_CONNECTED:
            ESP_LOGI(TAG, "HTTP_EVENT_ON_CONNECTED");
            break;
        case HTTP_EVENT_HEADER_SENT:
            ESP_LOGI(TAG, "HTTP_EVENT_HEADER_SENT");
            break;
        case HTTP_EVENT_ON_HEADER:
            ESP_LOGI(TAG, "HTTP_EVENT_ON_HEADER, key=%s, value=%s", evt->header_key, evt->header_value);
            break;
        case HTTP_EVENT_ON_DATA:
            ESP_LOGI(TAG, "HTTP_EVENT_ON_DATA, len=%d, data=%s", evt->data_len, evt->data);
            // 如果需要处理接收到的数据，可以在这里做
            break;
        case HTTP_EVENT_ON_FINISH:
            ESP_LOGI(TAG, "HTTP_EVENT_ON_FINISH");
            break;
        case HTTP_EVENT_DISCONNECTED:
            ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
            break;
    }
    return ESP_OK;
}




esp_err_t light_controal(const char *id, const char *state){
    const char* action;
    if(state == "on"){
        action = ON_URL;
    } else {
        action = OFF_URL;
    }
    esp_http_client_config_t config = {
            .url = action, // 你需要使用指定的URL
            .event_handler = _http_event_handler, // 你需要实现这个事件处理函数
            // 其他配置可以根据需要添加
            .timeout_ms = 6000,
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);
    if (client == NULL) {
        ESP_LOGE(TAG, "Failed to initialize HTTP client");
        return ESP_FAIL;
    }

    // 设置请求头
    esp_http_client_set_header(client, "Content-Type", "application/json");

    char auth_header[256];
    snprintf(auth_header, sizeof(auth_header), TOKEN);
    esp_http_client_set_header(client, "Authorization", auth_header);
    esp_http_client_set_method(client, HTTP_METHOD_POST);
    // 构造包含id的键值对的POST请求的body
    char post_data[256];
    snprintf(post_data, sizeof(post_data), "{\"entity_id\":\"%s\"}", id);

    ESP_LOGE(TAG, "POST data: %s", post_data);

    // 设置POST请求的body
    esp_http_client_set_post_field(client, post_data, strlen(post_data));


    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK) {
        int status_code = esp_http_client_get_status_code(client);
        if (status_code == 200) {
            ESP_LOGI(TAG, "HTTP request succeeded");
        } else {
            ESP_LOGE(TAG, "HTTP request failed with status code %d", status_code);
        }
    } else {
        ESP_LOGE(TAG, "HTTP request failed: %s", esp_err_to_name(err));
    }

    esp_http_client_cleanup(client);
    return err;
}

// 你需要实现这个事件处理函数来处理HTTP事件

// 你可以像这样调用函数
// turn_off("http://example.com/api/endpoint", "Bearer YOUR_TOKEN_HERE", "12345");



void ui_event_screen_ha_data(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT)
    {
        _ui_screen_change(ui_screen_setting, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0);
    }
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        _ui_screen_change(ui_screen_sensor, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0);
    }
    if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP  ) {
        _ui_screen_change( ui_screen_time, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 0);
    }
}


void ui_event_ha_data_wifi_btn( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if ( event_code == LV_EVENT_CLICKED) {
        ui_screen_last = ui_screen_ha_data;
        _ui_screen_change( ui_screen_wifi, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 0);
    }
}




void ui_event_com_btn(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if ( event_code == LV_EVENT_CLICKED) {
        ESP_LOGI(TAG, "ui_event_com_btn");
        struct view_data_ha_switch_data switch_data;
        switch_data.index = 10;
        if ( lv_obj_has_state(ui_com_all, LV_STATE_CHECKED) ) {
            switch_data.value = 1;
            light_controal("switch.w604_euf5_4gang_7_switch_1_3", "on");
            light_controal("switch.w604_euf5_4gang_7_switch_2_3", "on");
            lv_img_set_src(ui_com_all_logo, &ui_img_ic_switch2_on_png);
        } else {
            switch_data.value = 0;
            light_controal("switch.w604_euf5_4gang_7_switch_1_3", "off");
            light_controal("switch.w604_euf5_4gang_7_switch_2_3", "off");
            lv_img_set_src(ui_com_all_logo, &ui_img_ic_switch2_off_png);
        }
        esp_event_post_to(view_event_handle, VIEW_EVENT_BASE, VIEW_EVENT_HA_SWITCH_ST, &switch_data, sizeof(switch_data), portMAX_DELAY);
        ESP_LOGI(TAG, "switch%d: %d", switch_data.index + 1, switch_data.value);
    }
}


void ui_event_hr_btn(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if ( event_code == LV_EVENT_CLICKED) {
        ESP_LOGI(TAG, "ui_event_hr_btn");
        struct view_data_ha_switch_data switch_data;
        switch_data.index = 10;
        if ( lv_obj_has_state(ui_hr_all, LV_STATE_CHECKED) ) {
            switch_data.value = 1;
            light_controal("switch.w604_euf5_4gang_7_switch_3_3", "on");
            lv_img_set_src(ui_hr_all_logo, &ui_img_ic_switch2_on_png);

        } else {
            switch_data.value = 0;

            light_controal("switch.w604_euf5_4gang_7_switch_3_3", "off");
            lv_img_set_src(ui_hr_all_logo, &ui_img_ic_switch2_off_png);
        }
        esp_event_post_to(view_event_handle, VIEW_EVENT_BASE, VIEW_EVENT_HA_SWITCH_ST, &switch_data, sizeof(switch_data), portMAX_DELAY);
        ESP_LOGI(TAG, "switch%d: %d", switch_data.index + 1, switch_data.value);
    }
}


void ui_event_rest01_btn(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if ( event_code == LV_EVENT_CLICKED) {
        ESP_LOGI(TAG, "ui_event_rest01_btn");
        struct view_data_ha_switch_data switch_data;
        switch_data.index = 10;
        if ( lv_obj_has_state(ui_rest_01, LV_STATE_CHECKED) ) {
            light_controal("switch.9a_rest_switch_1", "on");
            light_controal("switch.9a_rest_switch_2", "on");
            light_controal("switch.9a_rest_switch_3", "on");
            switch_data.value = 1;
            lv_img_set_src(ui_rest_01_logo, &ui_img_ic_switch1_on_png);
        } else {
            light_controal("switch.9a_rest_switch_1", "off");
            light_controal("switch.9a_rest_switch_2", "off");
            light_controal("switch.9a_rest_switch_3", "off");
            switch_data.value = 0;
            lv_img_set_src(ui_rest_01_logo, &ui_img_ic_switch1_off_png);
        }
        esp_event_post_to(view_event_handle, VIEW_EVENT_BASE, VIEW_EVENT_HA_SWITCH_ST, &switch_data, sizeof(switch_data), portMAX_DELAY);
        ESP_LOGI(TAG, "switch%d: %d", switch_data.index + 1, switch_data.value);
    }
}


void ui_event_rest02_btn(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if ( event_code == LV_EVENT_CLICKED) {
        ESP_LOGI(TAG, "ui_event_rest02_btn");
        struct view_data_ha_switch_data switch_data;
        switch_data.index = 10;
        if ( lv_obj_has_state(ui_rest_02, LV_STATE_CHECKED) ) {
            light_controal("switch.finroad_switch_1", "on");
            light_controal("switch.finroad_switch_2", "on");
            switch_data.value = 1;
            lv_img_set_src(ui_rest_02_logo, &ui_img_ic_switch1_on_png);
        } else {
            light_controal("switch.finroad_switch_1", "off");
            light_controal("switch.finroad_switch_2", "off");
            switch_data.value = 0;
            lv_img_set_src(ui_rest_02_logo, &ui_img_ic_switch1_off_png);
        }
        esp_event_post_to(view_event_handle, VIEW_EVENT_BASE, VIEW_EVENT_HA_SWITCH_ST, &switch_data, sizeof(switch_data), portMAX_DELAY);
        ESP_LOGI(TAG, "switch%d: %d", switch_data.index + 1, switch_data.value);
    }
}

void ui_event_front01_btn(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED) {
        ESP_LOGI(TAG, "ui_event_front01_btn");
        struct view_data_ha_switch_data switch_data;
        switch_data.index = 10;
        if ( lv_obj_has_state(ui_front_01, LV_STATE_CHECKED) ) {
            light_controal("switch.afront_switch_1", "on");
            light_controal("switch.afront_switch_2", "on");
            light_controal("switch.afront_switch_3", "on");
            light_controal("switch.afront_switch_4", "on");
            light_controal("switch.afrontlogo_switch_1", "on");
            light_controal("switch.afrontlogo_switch_2", "on");
            light_controal("switch.afrontlogo_switch_3", "on");
            light_controal("switch.afrontlogo_switch_4", "on");
            switch_data.value = 1;
            lv_img_set_src(ui_front_01_logo, &ui_img_ic_switch1_on_png);
        } else {
            light_controal("switch.afront_switch_1", "off");
            light_controal("switch.afront_switch_2", "off");
            light_controal("switch.afront_switch_3", "off");
            light_controal("switch.afront_switch_4", "off");
            light_controal("switch.afrontlogo_switch_1", "off");
            light_controal("switch.afrontlogo_switch_2", "off");
            light_controal("switch.afrontlogo_switch_3", "off");
            light_controal("switch.afrontlogo_switch_4", "off");
            switch_data.value = 0;
            lv_img_set_src(ui_front_01_logo, &ui_img_ic_switch1_off_png);
        }
        esp_event_post_to(view_event_handle, VIEW_EVENT_BASE, VIEW_EVENT_HA_SWITCH_ST, &switch_data, sizeof(switch_data), portMAX_DELAY);
        ESP_LOGI(TAG, "switch%d: %d", switch_data.index + 1, switch_data.value);
    }
}

void ui_event_front02_btn(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED) {
        ESP_LOGI(TAG, "ui_event_front02_btn");
        struct view_data_ha_switch_data switch_data;
        switch_data.index = 10;
        if ( lv_obj_has_state(ui_front_02, LV_STATE_CHECKED) ) {
            switch_data.value = 1;
            light_controal("switch.trainingroomlight_switch_1", "on"),
            light_controal("switch.trainingroomlight_switch_2", "on"),
            light_controal("switch.trainingroomlight_switch_3", "on"),
            lv_img_set_src(ui_front_02_logo, &ui_img_ic_switch1_on_png);
        } else {
            switch_data.value = 0;
            light_controal("switch.trainingroomlight_switch_1", "off"),
            light_controal("switch.trainingroomlight_switch_2", "off"),
            light_controal("switch.trainingroomlight_switch_3", "off"),
            lv_img_set_src(ui_front_02_logo, &ui_img_ic_switch1_off_png);
        }
        esp_event_post_to(view_event_handle, VIEW_EVENT_BASE, VIEW_EVENT_HA_SWITCH_ST, &switch_data, sizeof(switch_data), portMAX_DELAY);
        ESP_LOGI(TAG, "switch%d: %d", switch_data.index + 1, switch_data.value);
    }
}



void ui_event_ha_init(void)
{
    lv_obj_add_event_cb(ui_screen_ha_data, ui_event_screen_ha_data, LV_EVENT_ALL, NULL);
    //9A HR & COM
    lv_obj_add_event_cb(ui_com_all, ui_event_com_btn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_hr_all, ui_event_hr_btn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_rest_01, ui_event_rest01_btn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_rest_02, ui_event_rest02_btn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_front_01, ui_event_front01_btn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_front_02, ui_event_front02_btn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ha_data_wifi_btn, ui_event_ha_data_wifi_btn, LV_EVENT_ALL, NULL);
}


void ui_event_stu_all_btn_update( bool value ) {
    if( value ) {
        lv_obj_add_state(ui_stu_all_btn, LV_STATE_CHECKED);
        lv_img_set_src(ui_stu_all_logo, &ui_img_ic_switch1_on_png);
    } else {
        lv_obj_clear_state(ui_stu_all_btn, LV_STATE_CHECKED);
        lv_img_set_src(ui_stu_all_logo, &ui_img_ic_switch1_off_png);
    }
}


int indicator_controller_ha_init(void)
{
    ui_event_ha_init();
    return 0;
}


