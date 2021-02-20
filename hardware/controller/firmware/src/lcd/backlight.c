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

#pragma udata access _BL_DATA
static near unsigned char backlight_config;
static near unsigned char backlight_level;
static near unsigned char backlight_target;
static near unsigned short backlight_count;
static near unsigned short backlight_speed;
static near unsigned char backlight_current;
static near unsigned char backlight_is_temp_mode;
#pragma udata

const rom unsigned char rom blevels[64] =
{
	  0,   1,   1,   2,   3,   4,   5,   6,
          7,   8,   9,  11,  12,  13,  14,  16,
	 18,  20,  22,  24,  26,  28,  30,  33,
         35,  38,  41,  44,  47,  50,  53,  57,
	 61,  65,  69,  72,  76,  81,  85,  90,
         95,  99, 105, 110, 115, 120, 126, 132,
	138, 144, 150, 156, 162, 169, 176, 183,
        190, 198, 208, 219, 227, 235, 245, 255
};

void backlight_init(void)
{
    logger_print_start_msg(S_LCD_BACKLIGHT);
    
    backlight_config = 0;
    backlight_level = 0;
    backlight_target = 0;
    backlight_count = 0;
    backlight_speed = 0;

    backlight_current = BACKLIGHT_CONSTANT;
    backlight_is_temp_mode = 0;
    
    backlight_set(0);
}

void backlight_enter_temp(void)
{
    backlight_current = backlight_config;
    backlight_is_temp_mode = 1;
    backlight_set(63);
}

void backlight_leave_temp(void)
{
    backlight_is_temp_mode = 0;
    backlight_mode(backlight_current);
}

// backlight pwm is on CCP2
void backlight_set(unsigned char bval)
{
    backlight_config = BACKLIGHT_CONSTANT;
    CCPR2L = blevels[bval & 63];
}

void backlight_mode(unsigned char mval)
{
    if(backlight_is_temp_mode == 1)
    {
        backlight_current = mval;
    }
    else
    {
        if(mval & BACKLIGHT_CONSTANT)
        {
            backlight_set(active_config.backlight_constant_level);
        }
        else if(mval & BACKLIGHT_FADE)
        {
            backlight_fade(active_config.backlight_constant_level, 50);
        }
        else if(mval & BACKLIGHT_PULSE)
        {
            backlight_start_pulse();
        }
        else if(mval & BACKLIGHT_FLASH)
        {
            backlight_start_flash();
        }
    }
}

void backlight_process(void)
{
    if(backlight_config & BACKLIGHT_FADE)
    {
        if(backlight_config & BACKLIGHT_UP)
        {
            if(backlight_count >= backlight_speed)
            {
                backlight_count = 0;
                backlight_level++;
                if(backlight_level >= backlight_target)
                {
                    backlight_level = backlight_target;
                    backlight_config = BACKLIGHT_CONSTANT;
                }
            }
            else
            {
                backlight_count++;
            }
        }
        else if(backlight_config & BACKLIGHT_DOWN)
        {
            if(backlight_count >= backlight_speed)
            {
                backlight_count = 0;
                backlight_level--;
                if(backlight_level <= backlight_target)
                {
                    backlight_level = backlight_target;
                    backlight_config = BACKLIGHT_CONSTANT;
                }
            }
            else
            {
                backlight_count++;
            }
        }

        CCPR2L = blevels[backlight_level & 63];
    }
    else if(backlight_config & BACKLIGHT_PULSE)
    {
        if(backlight_config & BACKLIGHT_UP)
        {
            if(backlight_count >= active_config.backlight_pulse_speed)
            {
                backlight_count = 0;
                backlight_level++;
                if(backlight_level >= active_config.hi_pulse_backlight)
                {
                    backlight_level = active_config.hi_pulse_backlight;
                    backlight_config &= ~BACKLIGHT_UP;
                    backlight_config |= BACKLIGHT_DOWN;
                }
            }
            else
            {
                backlight_count++;
            }
        }
        else if(backlight_config & BACKLIGHT_DOWN)
        {
            if(backlight_count >= active_config.backlight_pulse_speed)
            {
                backlight_count = 0;
                backlight_level--;
                if(backlight_level <= active_config.low_pulse_backlight)
                {
                    backlight_level = active_config.low_pulse_backlight;
                    backlight_config &= ~BACKLIGHT_DOWN;
                    backlight_config |= BACKLIGHT_UP;
                }
            }
            else
            {
                backlight_count++;
            }
        }

        CCPR2L = blevels[backlight_level & 63];
    }
    else if(backlight_config & BACKLIGHT_FLASH)
    {
        if(backlight_config & BACKLIGHT_FLASHON)
        {
            if(backlight_count >= active_config.backlight_flash_ton)
            {

                backlight_level--;
                backlight_count = 0;
                if(backlight_level <= active_config.low_flash_backlight)
                {
                    backlight_config &= ~BACKLIGHT_FLASHON;
                    backlight_config |= BACKLIGHT_FLASHOFF;
                }
            }
            else
            {
                backlight_count++;
            }
        }
        else if(backlight_config & BACKLIGHT_FLASHOFF)
        {
            if(backlight_count >= active_config.backlight_flash_toff)
            {
                backlight_count = 0;
                backlight_level = active_config.hi_flash_backlight;
                backlight_config &= ~BACKLIGHT_FLASHOFF;
                backlight_config |= BACKLIGHT_FLASHON;
            }
            else
            {
                backlight_count++;
            }
        }

        CCPR2L = blevels[backlight_level & 63];
    }
}

void backlight_fade(unsigned char target, unsigned short speed)
{
    backlight_config = 0;
    backlight_count = 0;

    if(target > 63)
    {
        backlight_target = 63;
    }
    else
    {
        backlight_target = target;
    }

    backlight_speed = speed;
    
    if(backlight_level < backlight_target)
    {
        backlight_config = BACKLIGHT_FADE | BACKLIGHT_UP;
    }
    else
    {
        backlight_config = BACKLIGHT_FADE | BACKLIGHT_DOWN;
    }
}

void backlight_set_pulse(unsigned char low, unsigned char hi, unsigned short speed)
{
    if(low > 63)
    {
        active_config.low_pulse_backlight = 63;
    }
    else
    {
        active_config.low_pulse_backlight = low;
    }

    if(hi > 63)
    {
        active_config.hi_pulse_backlight = 63;
    }
    else
    {
        active_config.hi_pulse_backlight = hi;
    }

    active_config.backlight_pulse_speed = speed;

}

void backlight_start_pulse(void)
{
    backlight_config = 0;
    backlight_count = 0;
    backlight_config = BACKLIGHT_PULSE | BACKLIGHT_UP;
}

void backlight_set_flash(unsigned char low, unsigned char hi, unsigned short ton, unsigned short toff)
{
    if(low > 63)
    {
        active_config.low_flash_backlight = 63;
    }
    else
    {
        active_config.low_flash_backlight = low;
    }

    if(hi > 63)
    {
        active_config.hi_flash_backlight = 63;
    }
    else
    {
        active_config.hi_flash_backlight = hi;
    }

    active_config.backlight_flash_ton = ton;
    active_config.backlight_flash_toff = toff;

}

void backlight_start_flash(void)
{
    backlight_config = 0;
    backlight_count = 0;
    backlight_config = BACKLIGHT_FLASH | BACKLIGHT_FLASHON;
}
