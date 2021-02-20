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

static unsigned char pm_state, pm_old_state, pm_saved_state;
static unsigned long pm_seconds;
static unsigned char pm_ticks;
static unsigned char old_tip, cur_tip;
static unsigned char pm_button;

unsigned short max_rise, max_drop, max_combined;

void power_manager_init(void)
{
    logger_print_start_msg(S_POWER_MANAGER);

    power_manager_reset();
}

void power_manager_reset_max(void)
{
    max_rise = 0;
    max_drop = 0;
    max_combined = 0;
}

void power_manager_reset(void)
{
    pm_seconds = 0;
    pm_ticks = 0;

    cur_tip = tip_detect_get_status();
    old_tip = TIP_MISSING;

    rf_manager_set_mode(RF_POWER_OFF);
    pm_old_state = PM_OFF;
    pm_state = PM_OFF;

    pm_saved_state = PM_MANUAL_OFF;

    power_manager_reset_max();

    power_manager_init_state();
}

void power_manager_init_state(void)
{
    if(active_config.startup_default & STARTUP_MANUAL)
    {
        if(active_config.startup_default & STARTUP_ON)
        {
            power_manager_set_state(PM_MANUAL_NORMAL);
            pm_saved_state = PM_MANUAL_NORMAL;
        }
        else
        {
            power_manager_set_state(PM_MANUAL_OFF);
            pm_saved_state = PM_MANUAL_NORMAL;
        }
    }
    else
    {
        if(active_config.startup_default & STARTUP_ON)
        {
            power_manager_set_state(PM_HEATUP);
        }
        else
        {
            power_manager_set_state(PM_OFF);
        }
    }
}

void power_manager_process(void)
{
    pm_button = encoder_get_button();

    if(power_manager_get_state() != PM_OFF)
    {
        logger_print_params();

        cur_tip = tip_detect_get_status();
        
        if(cur_tip != old_tip)
        {
            if(old_tip == TIP_MISSING)
            {
                power_manager_init_state();
                infodisplay_reset();
                if(power_manager_get_state() == PM_OFF)
                {
                    power_manager_set_state(PM_HEATUP);
                }
                else if(power_manager_get_state() == PM_MANUAL_OFF)
                {
                    power_manager_set_state(PM_MANUAL_NORMAL);
                }
            }
            old_tip = cur_tip;
        }
    }

    if(pm_state <= PM_WAKEUP_POWER_BOOST)
    {
        if(pm_button == BUTTON_CLICKED)
        {
            power_manager_set_state(PM_OFF);
            rf_manager_set_mode(RF_POWER_OFF);
            backlight_mode(active_config.normal_backlight);
            infodisplay_reset();
            return;
        }
        else if(pm_button == BUTTON_CLICKPUSH)
        {
            encoder_clear_button();
            power_manager_set_state(PM_ENTER_SLEEP);
            rf_manager_set_mode(RF_POWER_LIMIT);
            backlight_mode(active_config.sleep_backlight);
            infodisplay_reset();
            return;
        }
    }
    
    if(pm_ticks & 0x01)
    {
        rf_manager_store_delta();
    }
    if(pm_ticks >= 10)
    {
        pm_ticks = 0;
        pm_seconds++;
    }
    pm_ticks++;

    switch(pm_state)
    {
        case PM_HEATUP:
            backlight_mode(active_config.normal_backlight);
            if(active_config.heatup_config & PM_CFG_HEATUP_LIMIT)
            {
                if(pm_ticks > 1)
                {
                    if(active_config.heatup_config & PM_CFG_HEATUP_TIMED)
                    {
                        power_manager_set_state(PM_HEATUP_TIMED_LIMIT);
                    }
                    else
                    {
                        power_manager_set_state(PM_HEATUP_POWER_LIMIT);
                    }
                }
                rf_manager_set_mode(RF_POWER_LIMIT);
            }
            else if(active_config.heatup_config & PM_CFG_HEATUP_BOOST)
            {
                if(pm_ticks > 1)
                {
                    if(active_config.heatup_config & PM_CFG_HEATUP_TIMED)
                    {
                        power_manager_set_state(PM_HEATUP_TIMED_BOOST);
                    }
                    else
                    {
                        power_manager_set_state(PM_HEATUP_POWER_BOOST);
                    }
                }
                rf_manager_set_mode(RF_POWER_BOOST);
            }
            else
            {
                power_manager_set_state(PM_HEATING);
                rf_manager_set_mode(RF_POWER_NORMAL);
            }
            break;

        case PM_HEATUP_TIMED_LIMIT:
            if(pm_seconds >= active_config.heatup_limit_time)
            {
                power_manager_set_state(PM_HEATING);
                rf_manager_set_mode(RF_POWER_NORMAL);
            }
            break;

        case PM_HEATUP_POWER_LIMIT:
            if(rf_manager_get_reading(RF_POWER) <= active_config.heatup_limit_power)
            {
                power_manager_set_state(PM_HEATING);
                rf_manager_set_mode(RF_POWER_NORMAL);
            }
            break;


        case PM_HEATUP_TIMED_BOOST:
            if(pm_seconds >= active_config.heatup_boost_time)
            {
                power_manager_set_state(PM_HEATING);
                rf_manager_set_mode(RF_POWER_NORMAL);
            }
            break;

        case PM_HEATUP_POWER_BOOST:
            if(rf_manager_get_reading(RF_POWER) <= active_config.heatup_boost_power)
            {
                power_manager_set_state(PM_HEATING);
                rf_manager_set_mode(RF_POWER_NORMAL);
            }
            break;

        case PM_HEATING:
            if((pm_seconds >= 2) && (active_config.idle_threshold > rf_manager_get_reading(RF_POWER_COMBINED)) && (rf_manager_get_reading(RF_POWER) < 500))
            {
                power_manager_set_state(PM_HEATED);
            }
            break;

        case PM_HEATED:
            if(active_config.idle_threshold < rf_manager_get_reading(RF_POWER_RISE))
            {
                power_manager_set_state(PM_HEATING);
            }
            else if(pm_seconds >= 5) //active_config.enter_idle_time)
            {
                power_manager_set_state(PM_IDLE);
            }
            break;

        case PM_IDLE:
            if(active_config.idle_threshold < rf_manager_get_reading(RF_POWER_RISE))
            {
                power_manager_set_state(PM_HEATING);
            }
            else
            {
                if(active_config.sleep_config & PM_CFG_ENABLE_SLEEP)
                {
                    if(pm_seconds >= active_config.enter_sleep_time)
                    {
                        rf_manager_clear_delta();
                        power_manager_set_state(PM_ENTER_SLEEP);
                        backlight_mode(active_config.sleep_backlight);
                        rf_manager_set_mode(RF_POWER_LIMIT);
                    }
                }
            }
            break;

        case PM_ENTER_SLEEP:
            if(pm_seconds >= 1)
            {
                power_manager_set_state(PM_SLEEP);
            }

        case PM_SLEEP:
            if(pm_seconds >= 1)
            {
                if(pm_seconds == 1 && pm_ticks == 1)
                {
                    power_manager_reset_max();
                }
                if(pm_seconds < active_config.light_sleep_time)
                {
                    if(active_config.light_sleep_threshold < rf_manager_get_reading(RF_POWER_RISE))
                    {
                       power_manager_set_state(PM_WAKEUP);
                    }
                }
                else if((active_config.sleep_threshold < rf_manager_get_reading(RF_POWER_RISE)) || (encoder_get() != 0))
                {
                   power_manager_set_state(PM_WAKEUP);
                }

                if(active_config.sleep_config & PM_CFG_ENABLE_POWERDOWN)
                {
                    if(pm_seconds >= active_config.enter_off_time)
                    {
                        power_manager_set_state(PM_ENTER_POWERDOWN);
                    }
                }
            }
            break;

        case PM_WAKEUP:
            backlight_mode(active_config.normal_backlight);
            if(active_config.wakeup_config & PM_CFG_WAKEUP_BOOST)
            {
                if(active_config.wakeup_config & PM_CFG_WAKEUP_TIMED)
                {
                    power_manager_set_state(PM_WAKEUP_TIMED_BOOST);
                }
                else
                {
                    power_manager_set_state(PM_WAKEUP_POWER_BOOST);
                }
                rf_manager_set_mode(RF_POWER_BOOST);
            }
            else
            {
                power_manager_set_state(PM_HEATING);
                rf_manager_set_mode(RF_POWER_NORMAL);
            }
            break;

        case PM_WAKEUP_TIMED_BOOST:
            if(pm_seconds >= active_config.wakeup_boost_time)
            {
                power_manager_set_state(PM_HEATING);
                rf_manager_set_mode(RF_POWER_NORMAL);
            }
            break;

        case PM_WAKEUP_POWER_BOOST:
            if(rf_manager_get_reading(RF_POWER) <= active_config.wakeup_boost_power)
            {
                power_manager_set_state(PM_HEATING);
                rf_manager_set_mode(RF_POWER_NORMAL);
            }
            break;

        case PM_ENTER_POWERDOWN:
            backlight_mode(active_config.auto_off_backlight);
            power_manager_set_state(PM_POWERDOWN);
            rf_manager_set_mode(RF_POWER_OFF);
            break;

        case PM_POWERDOWN:
            if((pm_button == BUTTON_CLICKED))
            {
                power_manager_set_state(PM_HEATUP);
            }
            break;

        case PM_MANUAL_OFF:
            if(rf_manager_get_mode() != RF_POWER_OFF)
            {
                rf_manager_set_mode(RF_POWER_OFF);
            }
            
            if(pm_button == BUTTON_CLICKED)
            {
                switch(pm_saved_state)
                {
                    case PM_MANUAL_LIMIT:
                        power_manager_set_state(PM_MANUAL_LIMIT);
                        rf_manager_set_mode(RF_POWER_LIMIT);
                        break;

                    case PM_MANUAL_NORMAL:
                        power_manager_set_state(PM_MANUAL_NORMAL);
                        rf_manager_set_mode(RF_POWER_NORMAL);
                        break;

                    case PM_MANUAL_BOOST:
                        power_manager_set_state(PM_MANUAL_BOOST);
                        rf_manager_set_mode(RF_POWER_BOOST);
                        break;
                }
            }

            if(encoder_get() > 0)
            {
                power_manager_set_state(PM_MANUAL_LIMIT);
                rf_manager_set_mode(RF_POWER_LIMIT);
                pm_saved_state = PM_MANUAL_LIMIT;
            }

            break;

        case PM_MANUAL_LIMIT:
            if(encoder_get() > 0)
            {
                power_manager_set_state(PM_MANUAL_NORMAL);
                rf_manager_set_mode(RF_POWER_NORMAL);
            }

            if((pm_button == BUTTON_CLICKED))
            {
                pm_saved_state = pm_state;
                power_manager_set_state(PM_MANUAL_OFF);
                rf_manager_set_mode(RF_POWER_OFF);
            }
            break;

        case PM_MANUAL_NORMAL:
            if(encoder_get() < 0)
            {
                power_manager_set_state(PM_MANUAL_LIMIT);
                rf_manager_set_mode(RF_POWER_LIMIT);
            }
            else if(encoder_get() > 0)
            {
                power_manager_set_state(PM_MANUAL_BOOST);
                rf_manager_set_mode(RF_POWER_BOOST);
            }

            if((pm_button == BUTTON_CLICKED))
            {
                pm_saved_state = pm_state;
                power_manager_set_state(PM_MANUAL_OFF);
                rf_manager_set_mode(RF_POWER_OFF);
            }
            break;

        case PM_MANUAL_BOOST:
            if(encoder_get() < 0)
            {
                power_manager_set_state(PM_MANUAL_NORMAL);
                rf_manager_set_mode(RF_POWER_NORMAL);
            }
            
            if((pm_button == BUTTON_CLICKED))
            {
                pm_saved_state = pm_state;
                power_manager_set_state(PM_MANUAL_OFF);
                rf_manager_set_mode(RF_POWER_OFF);
            }
            break;

        case PM_OFF:
            if(rf_manager_get_mode() != RF_POWER_OFF)
            {
                rf_manager_set_mode(RF_POWER_OFF);
            }
            if((pm_button == BUTTON_CLICKED))
            {
                power_manager_set_state(PM_HEATUP);
                pm_ticks = 0;
                logger_print_header();
            }
            break;

        default:
            break;
    }

    if(max_rise < rf_manager_get_reading(RF_POWER_RISE))
    {
        max_rise = rf_manager_get_reading(RF_POWER_RISE);
    };
    if(max_drop < rf_manager_get_reading(RF_POWER_DROP))
    {
        max_drop = rf_manager_get_reading(RF_POWER_DROP);
    };
    if(max_combined < rf_manager_get_reading(RF_POWER_COMBINED))
    {
        max_combined = rf_manager_get_reading(RF_POWER_COMBINED);
    };


}

void power_manager_set_state(unsigned char new_state)
{
    if(pm_old_state != new_state)
    {
        pm_state = new_state;
        logger_print_timed_change_msg(S_POWER_MANAGER, S_CHANGE_STATE, power_manager_get_state_string(), pm_seconds);
        
        pm_old_state = new_state;
        pm_seconds = 0;
        pm_ticks = 0;

        power_manager_reset_max();
    }
}

unsigned char power_manager_get_state(void)
{
    return pm_state;
}

unsigned short power_manager_get_state_string(void)
{

    switch(pm_state)
    {
        case PM_HEATUP:
            return S_PM_HEATUP;
            break;

        case PM_HEATUP_TIMED_LIMIT:
            return S_PM_HEATUP_TIMED_LIMIT;
            break;

        case PM_HEATUP_POWER_LIMIT:
            return S_PM_HEATUP_POWER_LIMIT;
            break;

        case PM_HEATUP_TIMED_BOOST:
            return S_PM_HEATUP_TIMED_BOOST;
            break;

        case PM_HEATUP_POWER_BOOST:
            return S_PM_HEATUP_POWER_BOOST;
            break;

        case PM_HEATING:
            return S_PM_HEATING;
            break;

        case PM_HEATED:
            return S_PM_HEATED;
            break;

        case PM_IDLE:
            return S_PM_IDLE;
            break;

        case PM_ENTER_SLEEP:
            return S_PM_ENTER_SLEEP;
            break;

        case PM_SLEEP:
            return S_PM_SLEEP;
            break;

        case PM_WAKEUP:
            return S_PM_WAKEUP;
            break;

        case PM_WAKEUP_TIMED_BOOST:
            return S_PM_WAKEUP_TIMED_BOOST;
            break;

        case PM_WAKEUP_POWER_BOOST:
            return S_PM_WAKEUP_POWER_BOOST;
            break;

        case PM_ENTER_POWERDOWN:
            return S_PM_ENTER_POWERDOWN;
            break;

        case PM_POWERDOWN:
            return S_PM_POWERDOWN;
            break;

        case PM_MANUAL_OFF:
            return S_PM_MANUAL_OFF;
            break;

        case PM_MANUAL_LIMIT:
            return S_PM_MANUAL_LIMIT;
            break;

        case PM_MANUAL_NORMAL:
            return S_PM_MANUAL_NORMAL;
            break;

        case PM_MANUAL_BOOST:
            return S_PM_MANUAL_BOOST;
            break;

        case PM_OFF:
            return S_PM_OFF;
            break;

        default:
            return S_INVALID;
            break;


    }
}

void power_manager_set_config(unsigned char cfg)
{
    active_config.sleep_config = cfg;
}

void power_manager_set_sleeptime(unsigned short stime)
{
    active_config.enter_sleep_time = stime;
}

unsigned long power_manager_get_state_seconds(void)
{
    return pm_seconds;
}
