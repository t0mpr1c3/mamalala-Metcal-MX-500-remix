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

static unsigned short data_crc;

void config_manager_init(void)
{
    static unsigned char cnt;
    logger_print_start_msg(S_CONFIG_MANAGER);

    for(cnt = 0; cnt < NUM_CONFIGS; cnt++)
    {
        if(config_memory_check_config(cnt) == 0)
        {
            config_memory_default_config(cnt);
            config_memory_save_config(cnt);
        }
    }

    config_manager_load_main_config();
    config_manager_load_config(main_config.config_num);
}

unsigned char config_manager_load_main_config(void)
{
    if(config_memory_load_main_config() == 0)
    {
        logger_print_module_msg(S_CONFIG_MANAGER, S_INVALID_MAINCFG);
        
        config_memory_default_main_config();
        config_memory_save_main_config();

        if(config_memory_load_main_config() == 0)
        {
            config_memory_default_main_config();
            return 0;
        }
        else
        {
            return 1;
        }

    }
}

unsigned char config_manager_load_config(unsigned char config_num)
{
    if(config_memory_load_config(config_num) == 0)
    {
        logger_print_module_msg(S_CONFIG_MANAGER, S_INVALID_CFG);

        config_memory_default_config(config_num);
        config_memory_save_config(config_num);

        if(config_memory_load_config(config_num) == 0)
        {
            config_memory_default_config(config_num);
            config_memory_swap(CONFIG_EDIT_TO_ACTIVE);
            return 0;
        }
    }
    config_memory_swap(CONFIG_EDIT_TO_ACTIVE);
    return 1;
}

void config_manager_activate_config(void)
{
    config_manager_load_config(main_config.config_num);
    power_manager_reset();
}