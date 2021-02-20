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

static unsigned char logger_cfg;
static unsigned long logger_ticks;

void logger_init(void)
{
    logger_cfg = main_config.logger_config;
    logger_ticks = 0;
}

void logger_set_config(void)
{
    logger_cfg = main_config.logger_config;
    uart_print_romstring("\r\n");
}

void logger_print_version(void)
{
    if(!(logger_cfg & LOG_PARAMETERS))
    {
        if(logger_cfg & LOG_VERSION)
        {
            uart_print_romstring("\r\n\r\n");
            uart_print_romstring("<<< ");
            uart_print_romstring(PROJECT_NAME);
            uart_print_romstring(" Version ");
            uart_print_longnum(VERSION_MAJOR, 2, 0);
            uart_print_romstring(".");
            uart_print_longnum(VERSION_MINOR, 2, 0);
            uart_print_romstring(" >>>\r\n");
        }
    }
}

void logger_print_twostrings(unsigned short str1, unsigned short str2)
{
    uart_print_romstring(tr(str1));
    uart_print_romstring(": ");
    uart_print_romstring(tr(str2));
}

void logger_print_start_msg(unsigned short stringnum)
{
    if(!(logger_cfg & LOG_PARAMETERS))
    {
        if(logger_cfg & LOG_STARTUPS)
        {
            logger_print_twostrings(S_STARTING, stringnum);
            uart_print_romstring("\r\n");
        }
    }
}

void logger_print_module_msg(unsigned short mod_stringnum, unsigned short msg_stringnum)
{
    if(!(logger_cfg & LOG_PARAMETERS))
    {
        if(logger_cfg & LOG_MODULES)
        {
            logger_print_twostrings(mod_stringnum, msg_stringnum);
            uart_print_romstring("\r\n");
        }
    }
}

void logger_print_module_msg_val(unsigned short mod_stringnum, unsigned short msg_stringnum, unsigned short val_stringnum)
{
    if(!(logger_cfg & LOG_PARAMETERS))
    {
        if(logger_cfg & LOG_MODULES)
        {
            logger_print_twostrings(mod_stringnum, msg_stringnum);

            uart_print_romstring(": \"");
            uart_print_romstring(tr(val_stringnum));
            uart_print_romstring("\"\r\n");
        }
    }
}

void logger_print_module_msg_stringval(unsigned short mod_stringnum, unsigned short msg_stringnum, const rom char *val_str)
{
    if(!(logger_cfg & LOG_PARAMETERS))
    {
        if(logger_cfg & LOG_MODULES)
        {
            logger_print_twostrings(mod_stringnum, msg_stringnum);

            uart_print_romstring(": \"");
            uart_print_romstring(val_str);
            uart_print_romstring("\"\r\n");
        }
    }
}

void logger_print_module_msg_ramval(unsigned short mod_stringnum, unsigned short msg_stringnum, char *val_str)
{
    if(!(logger_cfg & LOG_PARAMETERS))
    {
        if(logger_cfg & LOG_MODULES)
        {
            logger_print_twostrings(mod_stringnum, msg_stringnum);
            uart_print_romstring(": \"");
            uart_print_ramstring(val_str);
            uart_print_romstring("\"\r\n");
        }
    }
}

void logger_print_timed_change_msg(unsigned short mod_stringnum, unsigned short msg_stringnum, unsigned short state_stringnum, unsigned long secs)
{
    if(!(logger_cfg & LOG_PARAMETERS))
    {
        if(logger_cfg & LOG_MODULES)
        {
            logger_print_twostrings(mod_stringnum, msg_stringnum);
            uart_print_romstring(" \"");
            uart_print_romstring(tr(state_stringnum));
            uart_print_romstring("\" ");

            uart_print_romstring(tr(S_AFTER));
            uart_print_romstring(" ");
            uart_print_seconds_as_time(secs);
            uart_print_romstring("\r\n");
        }
    }
}

void logger_print_elapsed_seconds(unsigned long seconds)
{
    if(!(logger_cfg & LOG_PARAMETERS))
    {
        if(logger_cfg & LOG_TIME)
        {
            uart_print_longnum(seconds, 8, 0);
            uart_print_romstring("\r");
        }
    }
}

void logger_print_header(void)
{
    if(logger_cfg & LOG_PARAMETERS)
    {
        uart_print_romstring("#secs\t\t");
        if(logger_cfg & LOG_TIME)
        {
            uart_print_romstring("pm_secs\t\t");
        }        
        uart_print_romstring("Vsup\tVSWR\tFWD\tREF\tPower\trise\tdrop\tTDelta\tMRise\tMDrop\tMTotal\tMode\r\n");
    }
}

void logger_print_params(void)
{
    if(logger_cfg & LOG_PARAMETERS)
    {
        if(logger_cfg & LOG_TIME)
        {
            uart_print_longnum(logger_ticks, 10, 1);
            uart_fifo_putchar('\t');
            logger_ticks++;
        }
        
        uart_print_longnum(power_manager_get_state_seconds(), 10, 0);
        uart_fifo_putchar('\t');

        uart_print_longnum(rf_manager_get_reading(RF_SUPPLY), 4, 2);
        uart_fifo_putchar('\t');

        uart_print_longnum(rf_manager_get_reading(RF_VSWR), 4, 2);
        uart_fifo_putchar('\t');

        uart_print_longnum(rf_manager_get_reading(RF_VFORWARD), 4, 2);
        uart_fifo_putchar('\t');

        uart_print_longnum(rf_manager_get_reading(RF_VREFLECTED), 4, 2);
        uart_fifo_putchar('\t');

        uart_print_longnum(rf_manager_get_reading(RF_POWER), 4, 1);
        uart_fifo_putchar('\t');

        uart_print_longnum(rf_manager_get_reading(RF_POWER_RISE), 3, 1);
        uart_fifo_putchar('\t');

        uart_print_longnum(rf_manager_get_reading(RF_POWER_DROP), 3, 1);
        uart_fifo_putchar('\t');

        uart_print_longnum(rf_manager_get_reading(RF_POWER_COMBINED), 3, 1);
        uart_fifo_putchar('\t');

        uart_print_longnum(max_rise, 3, 1);
        uart_fifo_putchar('\t');

        uart_print_longnum(max_drop, 3, 1);
        uart_fifo_putchar('\t');

        uart_print_longnum(max_combined, 3, 1);
        uart_fifo_putchar('\t');

        uart_print_romstring(tr(power_manager_get_state_string()));

        uart_fifo_putchar('\r');

        if(logger_cfg & LOG_NEWLINE)
        {
            uart_fifo_putchar('\n');
        }
    }
}
