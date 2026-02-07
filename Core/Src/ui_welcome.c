/*
 * ui_welcome.c
 *
 *  Created on: Dec 7, 2025
 *      Author: Florian
 */

#include "ui_welcome.h"

/**
 * @brief Initialize and display the Arcade Welcome Screen.
 */
void ui_welcome_screen_init(void)
{
    /* Get the active screen */
    lv_obj_t * scr = lv_scr_act();

    /* Set background color to black for an arcade feel */
    lv_obj_set_style_bg_color(scr, lv_color_black(), LV_PART_MAIN);

    /* create a style for the title */
    static lv_style_t style_title;
    lv_style_init(&style_title);
    lv_style_set_text_font(&style_title, &lv_font_montserrat_28);
    lv_style_set_text_color(&style_title, lv_color_hex(0xFFD700)); /* Gold color */

    /* Create the "WELCOME" label */
    lv_obj_t * label_welcome = lv_label_create(scr);
    lv_label_set_text(label_welcome, "WELCOME");
    lv_obj_add_style(label_welcome, &style_title, 0);
    lv_obj_align(label_welcome, LV_ALIGN_CENTER, 0, -40);

    /* Create the "TO ARCADE" label below */
    lv_obj_t * label_arcade = lv_label_create(scr);
    lv_label_set_text(label_arcade, "TO ARCADE");
    lv_obj_add_style(label_arcade, &style_title, 0);
    lv_obj_align(label_arcade, LV_ALIGN_CENTER, 0, 0);

    /* Create a spinner */
    lv_obj_t * spinner = lv_spinner_create(scr, 1000, 60);
    lv_obj_set_size(spinner, 60, 60);
    lv_obj_align(spinner, LV_ALIGN_BOTTOM_MID, 0, -20);
    lv_obj_set_style_arc_color(spinner, lv_color_hex(0x00FF00), LV_PART_INDICATOR); /* Green spinner */
}
