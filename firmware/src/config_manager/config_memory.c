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

MainConfigDataType main_config;

ConfigDataType active_config;
ConfigDataType edit_config;

static unsigned short cfg_mem_crc;

void config_memory_init(void)
{
    eeprom_read_block(0, MAIN_CONFIG_SIZE, (unsigned char*) &main_config.raw);

    if(main_config.crc != crc_calc_block(MAIN_CONFIG_SEED, MAIN_CONFIG_PAYLOAD_SIZE, main_config.data))
    {
        config_memory_default_main_config();
    }
}

void config_memory_default_main_config(void)
{
    main_config.version_major       = VERSION_MAJOR;
    main_config.version_minor       = VERSION_MINOR;
    main_config.language            = LANG_ENGLISH;
    main_config.baudrate            = BAUD_115200; // 38400;
    main_config.logger_config       = ( LOG_VERSION | LOG_STARTUPS | LOG_MODULES );
    main_config.config_num          = 0;

    main_config.crc = crc_calc_block(MAIN_CONFIG_SEED, MAIN_CONFIG_PAYLOAD_SIZE, main_config.data);
}

unsigned char config_memory_load_main_config(void)
{
    logger_print_module_msg(S_CONFIG_MEMORY, S_USING_SAVEDMAINCFG);
    
    eeprom_read_block(0, MAIN_CONFIG_SIZE, (unsigned char*) &main_config.raw);

    if(main_config.crc != crc_calc_block(MAIN_CONFIG_SEED, MAIN_CONFIG_PAYLOAD_SIZE, main_config.data))
    {
        logger_print_module_msg(S_CONFIG_MEMORY, S_CHECKSUM_WRONG);
        logger_print_module_msg(S_CONFIG_MEMORY, S_USING_INTMAINCFG);
        return 0;
    }
    else
    {
        logger_print_module_msg(S_CONFIG_MEMORY, S_CHECKSUM_OK);
        return 1;
    }
}

void config_memory_save_main_config(void)
{
    logger_print_module_msg(S_CONFIG_MEMORY, S_SAVING_MAINCFG);

    main_config.crc = crc_calc_block(MAIN_CONFIG_SEED, MAIN_CONFIG_PAYLOAD_SIZE, main_config.data);
    eeprom_write_block(0, MAIN_CONFIG_SIZE, (unsigned char*) &main_config.raw);
}

unsigned char config_memory_check_config(unsigned char cfg_num)
{
    static unsigned short signature;

    eeprom_read_block(MAIN_CONFIG_SIZE + CONFIG_PAYLOAD_SIZE + (CONFIG_SIZE * cfg_num), 2, (unsigned char*) &signature);

    if(signature != CONFIG_OK_SIGNATURE)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

char* config_memory_get_name(unsigned char cfg_num)
{
    static char cfg_name[17];
    cfg_name[16] = 0;

    if(config_memory_check_config(cfg_num))
    {
        eeprom_read_block(MAIN_CONFIG_SIZE + (CONFIG_SIZE * cfg_num), 16, (unsigned char*) &cfg_name);
    }
    else
    {
        copy_romstring_to_ram("*INVALID CONFIG*", cfg_name, 16);
    }

    return (char*)&cfg_name;
}

void config_memory_swap(unsigned char swp)
{
    static unsigned char cnt;

    switch(swp)
    {
        case CONFIG_EDIT_TO_ACTIVE:
            for(cnt = 0; cnt < CONFIG_SIZE; cnt++)
            {
                active_config.raw[cnt] = edit_config.raw[cnt];
            }
            break;

        case CONFIG_ACTIVE_TO_EDIT:
            for(cnt = 0; cnt < CONFIG_SIZE; cnt++)
            {
                edit_config.raw[cnt] = active_config.raw[cnt];
            }
            break;
    }
}

void config_memory_default_config(unsigned char cfg_num)
{
    copy_romstring_to_ram("Default Config  ", edit_config.name, 16);
    edit_config.name[15] = '0'+cfg_num;
    edit_config.name[16] = 0;

    logger_print_module_msg_ramval(S_CONFIG_MEMORY, S_USING_INTCFG, (char*) &edit_config.name);

    // default startup config
    edit_config.startup_default             = STARTUP_OFF;

    // heatup config
    edit_config.heatup_config               = PM_CFG_HEATUP_NORMAL;
    edit_config.heatup_limit_time           = 60;
    edit_config.heatup_limit_power          = 60;
    edit_config.heatup_boost_time           = 5;
    edit_config.heatup_boost_power          = 300;

    // idle mode config
    edit_config.idle_threshold              = 10;

    // sleep mode config
    edit_config.sleep_config                = ( PM_CFG_ENABLE_SLEEP | PM_CFG_ENABLE_POWERDOWN );
    edit_config.enter_sleep_time            = 3600; // 1 hour
    edit_config.light_sleep_time            = 1;
    edit_config.light_sleep_threshold       = 25;
    edit_config.sleep_threshold             = 15;
    edit_config.enter_off_time              = 3600*4; // 4 hours

    // wakeup config
    edit_config.wakeup_config               = ( PM_CFG_WAKEUP_BOOST | PM_CFG_WAKEUP_TIMED );
    edit_config.wakeup_boost_time           = 5;
    edit_config.wakeup_boost_power          = 300;

    // mode backlight config
    edit_config.normal_backlight            = BACKLIGHT_FADE;
    edit_config.sleep_backlight             = BACKLIGHT_PULSE;
    edit_config.auto_off_backlight          = BACKLIGHT_FLASH;

    // backlight modes parameters
    edit_config.backlight_constant_level    = 63;

    edit_config.low_pulse_backlight         = 15;
    edit_config.hi_pulse_backlight          = 40;
    edit_config.backlight_pulse_speed       = 250;

    edit_config.low_flash_backlight         = 5;
    edit_config.hi_flash_backlight          = 15;
    edit_config.backlight_flash_ton         = 100;
    edit_config.backlight_flash_toff        = 5000;

    edit_config.crc = crc_calc_block(CONFIG_SEED, CONFIG_PAYLOAD_SIZE, edit_config.data);

    edit_config.config_ok = CONFIG_OK_SIGNATURE;
}

unsigned char config_memory_load_config(unsigned char cfg_num)
{
    logger_print_module_msg(S_CONFIG_MEMORY, S_USING_SAVEDCFG);

    eeprom_read_block(MAIN_CONFIG_SIZE + (CONFIG_SIZE * cfg_num), CONFIG_SIZE, (unsigned char*) &edit_config.raw);

    if(edit_config.crc != crc_calc_block(CONFIG_SEED, CONFIG_PAYLOAD_SIZE, edit_config.data))
    {
        logger_print_module_msg(S_CONFIG_MEMORY, S_CHECKSUM_WRONG);
        return 0;
    }
    else
    {
        logger_print_module_msg(S_CONFIG_MEMORY, S_CHECKSUM_OK);
        logger_print_module_msg_ramval(S_CONFIG_MEMORY, S_LOADED_CFG, (char*) &edit_config.name);
        return 1;
    }
}

void config_memory_save_config(unsigned char cfg_num)
{
    logger_print_module_msg_ramval(S_CONFIG_MEMORY, S_SAVING_CFG, (char*) &edit_config.name);

    edit_config.crc = crc_calc_block(CONFIG_SEED, CONFIG_PAYLOAD_SIZE, edit_config.data);
    edit_config.config_ok = CONFIG_OK_SIGNATURE;
    eeprom_write_block(MAIN_CONFIG_SIZE + (CONFIG_SIZE * cfg_num), CONFIG_SIZE, (unsigned char*) &edit_config.raw);
}

