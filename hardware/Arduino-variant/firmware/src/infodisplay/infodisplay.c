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

static unsigned char tbar;
static unsigned char old_state, cur_state;
static unsigned char old_mode, cur_mode;
static unsigned short old_pwr, cur_pwr;
static unsigned char show_state;

void infodisplay_init(void)
{
    time_get_reset_delta_seconds();
    infodisplay_reset();
}

void infodisplay_reset(void)
{
    lcd_write_string_at(0, 0, "                ");
    lcd_write_string_at(0, 1, "                ");
    tbar = 0;
    cur_state = power_manager_get_state();
    old_state = 0xFF;
    cur_mode = rf_manager_get_mode();
    old_mode = 0xFF;
    cur_pwr = rf_manager_get_reading(RF_POWER);
    old_pwr = 9999;

    show_state = 0;
    
    infodisplay_show_powericon(0, 0, 0);
    infodisplay_show();
}

void infodisplay_show_version(void)
{
    lcd_write_line_at(0, 0, PROJECT_NAME);
    lcd_write_line_at(0, 1, "Version ");
    lcd_write_vnum(8,1, VERSION_MAJOR);
    lcd_write_char_at(10, 1, '.');
    lcd_write_vnum(11,1, VERSION_MINOR);
}

void infodisplay_show_powericon(unsigned char col, unsigned char row, unsigned char ico)
{
    lcd_upload_infoicon_ticker(3, (const rom unsigned char*)&powerinfoicons[ico][0], tickerbar[tbar]);
    lcd_write_char_at(col, row, 3);
}

void infodisplay_update_powericon(unsigned char ico)
{
    lcd_upload_infoicon_ticker(3, (const rom unsigned char*)&powerinfoicons[ico][0], tickerbar[tbar]);
}

void infodisplay_update_powericon_tick(void)
{
    tbar++;
    if(tbar >= 10)
    {
        tbar = 0;
    }

    lcd_upload_ramglyph_line(3, 7, tickerbar[tbar]);
}


void infodisplay_show(void)
{
    infodisplay_update_powericon_tick();


    cur_mode = rf_manager_get_mode();
    if(cur_mode != old_mode)
    {
        old_mode = cur_mode;

        infodisplay_update_powericon(cur_mode);
    }

    if(encoder_get_button() == BUTTON_DOUBLECLICKED)
    {
        show_state ^= 0x01;
        old_state = 99;
        encoder_clear_button();
    }

    if(show_state == 0)
    {
        cur_state = power_manager_get_state();
        if(cur_state != old_state)
        {
            old_state = cur_state;
            switch(power_manager_get_state())
            {

                case PM_HEATUP:
                    lcd_write_tr_line_at(0,1, SI_HEATUP);
                    break;

                case PM_HEATUP_TIMED_LIMIT:
                    lcd_write_tr_line_at(0,1, SI_HEATUP_LIMIT_TIMED);
                    break;

                case PM_HEATUP_POWER_LIMIT:
                    lcd_write_tr_line_at(0,1, SI_HEATUP_LIMIT_POWER);
                    break;

                case PM_HEATUP_TIMED_BOOST:
                    lcd_write_tr_line_at(0,1, SI_HEATUP_BOOST_TIMED);
                    break;

                case PM_HEATUP_POWER_BOOST:
                    lcd_write_tr_line_at(0,1, SI_HEATUP_BOOST_POWER);
                    break;

                case PM_HEATING:
                    lcd_write_tr_line_at(0,1, SI_HEATING);
                    break;

                case PM_HEATED:
                    lcd_write_tr_line_at(0,1, SI_HEATED);
                    break;

                case PM_IDLE:
                    lcd_write_tr_line_at(0,1, SI_IDLE);
                    break;

                case PM_SLEEP:
                    lcd_write_tr_line_at(0,1, SI_SLEEP);
                    break;

                case PM_WAKEUP:
                    lcd_write_tr_line_at(0,1, SI_WAKEUP);
                    break;

                case PM_WAKEUP_TIMED_BOOST:
                    lcd_write_tr_line_at(0,1, SI_WAKEUP_BOOST_TIMED);
                    break;

                case PM_WAKEUP_POWER_BOOST:
                    lcd_write_tr_line_at(0,1, SI_WAKEUP_BOOST_POWER);
                    break;

                case PM_POWERDOWN:
                    lcd_write_tr_line_at(0,1, SI_POWERDOWN);
                    break;

                case PM_MANUAL_OFF:
                    lcd_write_tr_line_at(0,1, SI_MANUAL_OFF);
                    break;

                case PM_MANUAL_LIMIT:
                    lcd_write_tr_line_at(0,1, SI_MANUAL_LIMIT);
                    break;

                case PM_MANUAL_NORMAL:
                    lcd_write_tr_line_at(0,1, SI_MANUAL_NORMAL);
                    break;

                case PM_MANUAL_BOOST:
                    lcd_write_tr_line_at(0,1, SI_MANUAL_BOOST);
                    break;

                case PM_OFF:
                    lcd_write_tr_line_at(0,1, SI_OFF);
                    break;
            }
        }
    }
    else
    {
        lcd_write_line_ram_at(0, 1, active_config.name);
    }
    
    if(rf_manager_get_mode() != RF_POWER_OFF)
    {
        if(tip_detect_get_status() == TIP_OK)
        {
            cur_pwr = rf_manager_get_reading(RF_POWER);
            if(cur_pwr != old_pwr)
            {
                old_pwr = cur_pwr;
                lcd_draw_bargraph(1, 0, cur_pwr, 75);
            }
        }
        else
        {
            lcd_write_tr_string_at(1, 0, SI_NO_TIP);
        }
    }
    else
    {
        lcd_write_string_at(1, 0, "---------------");
    }
}
