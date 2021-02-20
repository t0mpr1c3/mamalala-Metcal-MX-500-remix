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

rom const NamedSelectionEnum language_config_items[] =
{
    { CS_ENGLISH },
    { CS_GERMAN }
};

rom const NamedSelectionEnum baudrate_config_items[] =
{
    { CS_BAUD_2400 },
    { CS_BAUD_4800 },
    { CS_BAUD_7200 },
    { CS_BAUD_9600 },
    { CS_BAUD_14400 },
    { CS_BAUD_19200 },
    { CS_BAUD_28800 },
    { CS_BAUD_31520 },
    { CS_BAUD_38400 },
    { CS_BAUD_57600 },
    { CS_BAUD_115200 }
};

rom const NamedSelection logger_config_items[] =
{
    { CS_LOG_VERSION,       LOG_VERSION },
    { CS_LOG_STARTUPS,      LOG_STARTUPS },
    { CS_LOG_MODULES,       LOG_MODULES },
    { CS_LOG_PARAMETERS,    LOG_PARAMETERS },
    { CS_LOG_TIME,          LOG_TIME },
    { CS_LOG_NEWLINE,       LOG_NEWLINE }
};

rom const ConfigData main_config_items[] =
{
    {
      CONFIG_NAMEDSELECTION_ENUM_UPDATE,
      CS_LANGUAGE,
      numentries(language_config_items, NamedSelectionEnum),
      (rom const void*)&language_config_items,
      (void*) &main_config.language,
      0,
      (rom const voidfunc)languages_reload
    },
    {
      CONFIG_NAMEDSELECTION_ENUM_UPDATE,
      CS_BAUDRATE,
      numentries(baudrate_config_items, NamedSelectionEnum),
      (rom const void*)&baudrate_config_items,
      (void*) &main_config.baudrate,
      0,
      (rom const voidfunc)uart_set_baudrate,
    },
    {
      CONFIG_NAMEDRADIOSELECTION_UPDATE,
      CS_LOGGER,
      numentries(logger_config_items, NamedSelection),
      (rom const void*)&logger_config_items,
      (void*) &main_config.logger_config,
      0,
      (rom const voidfunc)logger_set_config,
    },
    {
      CONFIG_STARTUP_SETTINGS,
      CS_STARTUP_SETTINGS,
      NUM_CONFIGS,
      0,
      (void*) &main_config.config_num,
      0,
      (rom const voidfunc)config_manager_activate_config,
    },
};

rom const ConfigData main_config_data =
{
    CONFIG_ITEMS,
    CS_MAIN_CONFIG,
    numentries(main_config_items, ConfigData),
    (rom const void*)&main_config_items,
    0,
    0,
    (rom const voidfunc)config_memory_save_main_config
};


/***********************************/

rom const NamedSelection pm_startup_items[] =
{
    { CS_PM_AUTO_ON,        STARTUP_ON },
    { CS_PM_AUTO_OFF,       STARTUP_OFF },
    { CS_PM_MANUAL_ON,      (STARTUP_MANUAL | STARTUP_ON) },
    { CS_PM_MANUAL_OFF,     (STARTUP_MANUAL | STARTUP_OFF) },
};

rom const NamedSelection pm_heatup_parameter_items[] =
{
    { CS_PM_HEATUP_NORMAL,     PM_CFG_HEATUP_NORMAL },
    { CS_PM_HEATUP_LIMIT,      PM_CFG_HEATUP_LIMIT },
    { CS_PM_HEATUP_BOOST,      PM_CFG_HEATUP_BOOST }
};

rom const NamedSelection pm_heatup_endcondition_items[] =
{
    { CS_PM_HEATUP_END_TIMED,      PM_CFG_HEATUP_TIMED },
    { CS_PM_HEATUP_END_POWERLEVEL, PM_CFG_HEATUP_POWER },
};

rom const ValueItem pm_heatup_endcondition_parameter_items[] =
{
    {
        CS_PM_HEATUP_END_LIMIT_TIME,
        CONFIG_UCHAR,
        1,
        100,
        (void*)&edit_config.heatup_limit_time
    },
    {
        CS_PM_HEATUP_END_LIMIT_POWER,
        CONFIG_USHORT_1D,
        50,
        1000,
        (void*)&edit_config.heatup_limit_power
    },
    {
        CS_PM_HEATUP_END_BOOST_TIME,
        CONFIG_UCHAR,
        1,
        100,
        (void*)&edit_config.heatup_boost_time
    },
    {
        CS_PM_HEATUP_END_BOOST_POWER,
        CONFIG_USHORT_1D,
        50,
        1000,
        (void*)&edit_config.heatup_boost_power
    },
};

rom const ValueItem pm_idle_items[] =
{
    {
        CS_PM_IDLE_THREHOLD,
        CONFIG_UCHAR_1D,
        1,
        255,
        (void*)&edit_config.idle_threshold
    },
    {
        CS_PM_ENTER_SLEEP_TIME,
        CONFIG_TIME,
        1,
        65535,
        (void*)&edit_config.enter_sleep_time
    },
};

rom const NamedSelection pm_sleep_options_items[] =
{
    { CS_PM_ENABLE_SLEEP,       PM_CFG_ENABLE_SLEEP },
    { CS_PM_ENABLE_POWERDOWN,   PM_CFG_ENABLE_POWERDOWN }
};

rom const ValueItem pm_sleep_items[] =
{
    {
        CS_PM_LIGHT_SLEEP_TIME,
        CONFIG_UCHAR,
        1,
        255,
        (void*)&edit_config.light_sleep_time
    },
    {
        CS_PM_LIGHT_SLEEP_THRESHOLD,
        CONFIG_UCHAR_1D,
        1,
        255,
        (void*)&edit_config.light_sleep_threshold
    },
    {
        CS_PM_SLEEP_THRESHOLD,
        CONFIG_UCHAR_1D,
        1,
        255,
        (void*)&edit_config.light_sleep_threshold
    },
    {
        CS_PM_AUTO_OFF_TIME,
        CONFIG_TIME,
        1,
        65535,
        (void*)&edit_config.enter_off_time
    },
};

rom const NamedSelection pm_wakeup_parameter_items[] =
{
    { CS_PM_WAKEUP_NORMAL,     PM_CFG_WAKEUP_NORMAL },
    { CS_PM_WAKEUP_BOOST,      PM_CFG_WAKEUP_BOOST },
};

rom const NamedSelection pm_wakeup_endcondition_items[] =
{
    { CS_PM_WAKEUP_END_TIMED,      PM_CFG_WAKEUP_TIMED },
    { CS_PM_WAKEUP_END_POWERLEVEL, PM_CFG_WAKEUP_POWER },
};

rom const ValueItem pm_wakeup_endcondition_parameter_items[] =
{
    {
        CS_PM_WAKEUP_END_BOOST_TIME,
        CONFIG_UCHAR,
        1,
        100,
        (void*)&edit_config.wakeup_boost_time
    },
    {
        CS_PM_WAKEUP_END_BOOST_POWER,
        CONFIG_USHORT_1D,
        50,
        1000,
        (void*)&edit_config.wakeup_boost_power
    },
};

//*******
// backlight stuff

rom const NamedSelection pm_backlight_modes[] =
{
    { CS_PM_BACKLIGHT_CONSTANT,     BACKLIGHT_FADE },
    { CS_PM_BACKLIGHT_PULSED,       BACKLIGHT_PULSE },
    { CS_PM_BACKLIGHT_FLASH,        BACKLIGHT_FLASH },
};

rom const ValueItem pm_backlight_constant_items[] =
{
    {
        CS_BACKLIGHT_LEVEL,
        CONFIG_UCHAR,
        0,
        63,
        (void*)&edit_config.backlight_constant_level
    },
};

rom const ValueItem pm_backlight_pulse_items[] =
{
    {
        CS_PULSE_BACKLIGHT_LEVEL_LOW,
        CONFIG_UCHAR,
        0,
        63,
        (void*)&edit_config.low_pulse_backlight
    },
    {
        CS_PULSE_BACKLIGHT_LEVEL_HIGH,
        CONFIG_UCHAR,
        0,
        63,
        (void*)&edit_config.hi_pulse_backlight
    },
    {
        CS_PULSE_BACKLIGHT_SPEED,
        CONFIG_USHORT,
        10,
        2000,
        (void*)&edit_config.backlight_pulse_speed
    },
};

rom const ValueItem pm_backlight_flash_items[] =
{
    {
        CS_FLASH_BACKLIGHT_LEVEL_LOW,
        CONFIG_UCHAR,
        0,
        63,
        (void*)&edit_config.low_flash_backlight
    },
    {
        CS_FLASH_BACKLIGHT_LEVEL_HIGH,
        CONFIG_UCHAR,
        0,
        63,
        (void*)&edit_config.hi_flash_backlight
    },
    {
        CS_FLASH_BACKLIGHT_ON_TIME,
        CONFIG_USHORT,
        10,
        20000,
        (void*)&edit_config.backlight_flash_ton
    },
    {
        CS_FLASH_BACKLIGHT_OFF_TIME,
        CONFIG_USHORT,
        10,
        20000,
        (void*)&edit_config.backlight_flash_toff
    },
};


rom const ConfigData pm_config_items[] =
{
    // default startup config
    {
      CONFIG_NAMEDSELECTION_UPDATE,
      CS_PM_POWERON_MODE,
      numentries(pm_startup_items, NamedSelection),
      (rom const void*)&pm_startup_items,
      (void*) &edit_config.startup_default,
      0,
      0
    },
    
    // heatup config
    {
      CONFIG_NAMEDSELECTION_MASKED,
      CS_PM_HEATUP_MODE,
      numentries(pm_heatup_parameter_items, NamedSelection),
      (rom const void*)&pm_heatup_parameter_items,
      (void*) &edit_config.heatup_config,
      (PM_CFG_HEATUP_NORMAL | PM_CFG_HEATUP_LIMIT | PM_CFG_HEATUP_BOOST),
      0
    },
    {
      CONFIG_NAMEDSELECTION_MASKED,
      CS_PM_HEATUP_END,
      numentries(pm_heatup_endcondition_items, NamedSelection),
      (rom const void*)&pm_heatup_endcondition_items,
      (void*) &edit_config.heatup_config,
      (PM_CFG_HEATUP_TIMED | PM_CFG_HEATUP_POWER),
      0
    },
    {
      CONFIG_VALUE_ITEM,
      CS_PM_HEATUP_END_PARAM,
      numentries(pm_heatup_endcondition_parameter_items, ValueItem),
      (rom const void*)&pm_heatup_endcondition_parameter_items,
      0,
      0,
      0
    },

    // idle mode config
    {
      CONFIG_VALUE_ITEM,
      CS_PM_IDLE_PARAMETERS,
      numentries(pm_idle_items, ValueItem),
      (rom const void*)&pm_idle_items,
      0,
      0,
      0
    },

    // sleep mode config
    {
      CONFIG_NAMEDRADIOSELECTION_UPDATE,
      CS_PM_SLEEP_OPTIONS,
      numentries(pm_sleep_options_items, NamedSelection),
      (rom const void*)&pm_sleep_options_items,
      (void*) &edit_config.sleep_config,
      0,
      0
    },
    {
      CONFIG_VALUE_ITEM,
      CS_PM_SLEEPMODE_PARAMETERS,
      numentries(pm_sleep_items, ValueItem),
      (rom const void*)&pm_sleep_items,
      0,
      0,
      0
    },

    // wakeup config
    {
      CONFIG_NAMEDSELECTION_MASKED,
      CS_PM_WAKEUP_MODE,
      numentries(pm_wakeup_parameter_items, NamedSelection),
      (rom const void*)&pm_wakeup_parameter_items,
      (void*) &edit_config.wakeup_config,
      (PM_CFG_WAKEUP_NORMAL | PM_CFG_WAKEUP_BOOST),
      0
    },
    {
      CONFIG_NAMEDSELECTION_MASKED,
      CS_PM_WAKEUP_END,
      numentries(pm_wakeup_endcondition_items, NamedSelection),
      (rom const void*)&pm_wakeup_endcondition_items,
      (void*) &edit_config.wakeup_config,
      (PM_CFG_WAKEUP_TIMED | PM_CFG_WAKEUP_POWER),
      0
    },
    {
      CONFIG_VALUE_ITEM,
      CS_PM_WAKEUP_END_PARAM,
      numentries(pm_wakeup_endcondition_parameter_items, ValueItem),
      (rom const void*)&pm_wakeup_endcondition_parameter_items,
      0,
      0,
      0
    },

    // modes backlight type selection
    {
      CONFIG_NAMEDSELECTION,
      CS_PM_NORMAL_BACKLIGHT,
      numentries(pm_backlight_modes, NamedSelection),
      (rom const void*)&pm_backlight_modes,
      (void*) &edit_config.normal_backlight,
      0,
      0
    },
    {
      CONFIG_NAMEDSELECTION,
      CS_PM_SLEEP_BACKLIGHT,
      numentries(pm_backlight_modes, NamedSelection),
      (rom const void*)&pm_backlight_modes,
      (void*) &edit_config.sleep_backlight,
      0,
      0
    },
    {
      CONFIG_NAMEDSELECTION,
      CS_PM_AUTO_OFF_BACKLIGHT,
      numentries(pm_backlight_modes, NamedSelection),
      (rom const void*)&pm_backlight_modes,
      (void*) &edit_config.auto_off_backlight,
      0,
      0
    },

    // backlight modes parameters
    {
      CONFIG_VALUE_ITEM,
      CS_CONSTANT_BACKLIGHT_PARAM,
      numentries(pm_backlight_constant_items, ValueItem),
      (rom const void*)&pm_backlight_constant_items,
      0,
      0,
      0
    },
    {
      CONFIG_VALUE_ITEM,
      CS_PULSE_BACKLIGHT_PARAM,
      numentries(pm_backlight_pulse_items, ValueItem),
      (rom const void*)&pm_backlight_pulse_items,
      0,
      0,
      0
    },
    {
      CONFIG_VALUE_ITEM,
      CS_FLASH_BACKLIGHT_PARAM,
      numentries(pm_backlight_flash_items, ValueItem),
      (rom const void*)&pm_backlight_flash_items,
      0,
      0,
      0
    },
    {
      CONFIG_STRING,
      CS_CONFIG_NAME,
      16,
      0,
      (void*) &edit_config.name,
      0,
      0
    },
};

rom const ConfigData pm_editconfig_data =
{
    CONFIG_SELECTABLECONFIG,
    CS_SELECT_EDITCONFIG,
    numentries(pm_config_items, ConfigData),
    (rom const void*)&pm_config_items,
    0,
    0,
    (rom const voidfunc)config_editor_editselected
};

rom const ConfigData pm_saveconfig_data =
{
    CONFIG_SELECTABLECONFIG,
    CS_SAVE_EDITCONFIG,
    0,
    0,
    0,
    1,
    (rom const voidfunc)config_editor_saveselected
};

rom const ConfigData pm_loadconfig_data =
{
    CONFIG_SELECTABLECONFIG,
    CS_LOAD_EDITCONFIG,
    0,
    0,
    0,
    2,
    (rom const voidfunc)config_editor_loadselected
};
