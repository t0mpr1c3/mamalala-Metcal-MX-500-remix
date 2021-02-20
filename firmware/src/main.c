/*
 * (c) 2013 Ch. klippel  -  ck@atelier-klippel.de / c.klippel@gmx.de
 *
 * This code is released under the terms of the GPL, version 2 or newer.
 * See the file COPYING for more information about the license.
 *
 * Changelog:
 *
 * v00.01: - Initial version
 *
 */

#include "rfsupply.h"

voidfunc uifunc;

void default_ui_func(void);

void main_return_func(void)
{
    backlight_leave_temp();
    infodisplay_reset();
    infodisplay_show();
    set_ui_func(default_ui_func);
    encoder_clear_button();
}

void default_ui_func(void)
{
    if(encoder_get_button() == BUTTON_LONGPUSH)
    {
        backlight_enter_temp();
        menu_start((const rom void *) &main_return_func);
        encoder_clear_button();
    }
    else
    {
        infodisplay_show();
    }
}

void modules_init(void)
{
    // the following modules _MUST_ be initialized first in the given order
    config_memory_init();
    uart_init();
    logger_init();
    languages_init();
    config_manager_init();

    // these modules can be initialized in any order
    tip_detect_init();
    time_init();
    lcd_init();
    backlight_init();
    encoder_init();
    adc_init();
    rf_manager_init();
    power_manager_init();

    backlight_mode(active_config.normal_backlight);

    encoder_reset_button();
    encoder_reset();

    infodisplay_init();
}

void main(void)
{
    set_ui_func(default_ui_func);

    hardware_init();
    interrupt_init();
    modules_init();
    
    while(1)
    {
        if(time_get_reset_delta_ticks())
        {
            uifunc();
            power_manager_process();
            
            if(encoder_get_button() != BUTTON_IDLE)
            {
                encoder_reset_all();
            }
            else
            {
                encoder_reset();
            }
        }
    }
}

