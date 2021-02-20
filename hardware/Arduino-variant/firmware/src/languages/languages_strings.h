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

#ifndef MAINSTRINGS_H
#define MAINSTRINGS_H

#define tr(_X_)		current_strings[_X_]

typedef struct LANGUAGE_ENTRY {
    rom const void *data;
} LANGUAGE_ENTRY;

extern rom const struct LANGUAGE_ENTRY rom language_entries[];

#define NUM_LANGUAGES               2
#define LANG_ENGLISH                0
#define LANG_GERMAN                 1

#define S_RESET                     0
#define S_LANGUAGE_NAME             ( S_RESET                   + 1 )
#define S_INIT_MODULES              ( S_LANGUAGE_NAME           + 1 )
#define S_LANGUAGE_MANAGER          ( S_INIT_MODULES            + 1 )
#define S_SELECT_LANGUAGE           ( S_LANGUAGE_MANAGER        + 1 )
#define S_INVALID_LANGUAGE          ( S_SELECT_LANGUAGE         + 1 )
#define S_STARTING                  ( S_INVALID_LANGUAGE        + 1 )
#define S_LCD_DRIVER                ( S_STARTING                + 1 )
#define S_LCD_BACKLIGHT             ( S_LCD_DRIVER              + 1 )
#define S_CONFIG_MANAGER            ( S_LCD_BACKLIGHT           + 1 )
#define S_INVALID_MAINCFG           ( S_CONFIG_MANAGER          + 1 )
#define S_INVALID_CFG               ( S_INVALID_MAINCFG         + 1 )
#define S_CONFIG_MEMORY             ( S_INVALID_CFG             + 1 )
#define S_USING_INTMAINCFG          ( S_CONFIG_MEMORY           + 1 )
#define S_USING_INTCFG              ( S_USING_INTMAINCFG        + 1 )
#define S_USING_SAVEDMAINCFG        ( S_USING_INTCFG            + 1 )
#define S_USING_SAVEDCFG            ( S_USING_SAVEDMAINCFG      + 1 )
#define S_LOADED_CFG                ( S_USING_SAVEDCFG          + 1 )
#define S_SAVING_MAINCFG            ( S_LOADED_CFG              + 1 )
#define S_SAVING_CFG                ( S_SAVING_MAINCFG          + 1 )
#define S_CHECKSUM_OK               ( S_SAVING_CFG              + 1 )
#define S_CHECKSUM_WRONG            ( S_CHECKSUM_OK             + 1 )
#define S_UART                      ( S_CHECKSUM_WRONG          + 1 )
#define S_SET_BAUDRATE              ( S_UART                    + 1 )
#define S_TIP_DETECTOR              ( S_SET_BAUDRATE            + 1 )
#define S_ADC                       ( S_TIP_DETECTOR            + 1 )
#define S_RF_MANAGER                ( S_ADC                     + 1 )

#define S_POWER_MANAGER             ( S_RF_MANAGER              + 1 )
#define S_ROTARY_ENCODER            ( S_POWER_MANAGER           + 1 )
#define S_TIP_DETECTED              ( S_ROTARY_ENCODER          + 1 )
#define S_NO_TIP                    ( S_TIP_DETECTED            + 1 )
#define S_CHANGE_STATE              ( S_NO_TIP                  + 1 )
#define S_CHANGE_POWERLEVEL         ( S_CHANGE_STATE            + 1 )
#define S_OFF                       ( S_CHANGE_POWERLEVEL       + 1 )
#define S_NORMAL                    ( S_OFF                     + 1 )
#define S_LIMIT                     ( S_NORMAL                  + 1 )
#define S_BOOST                     ( S_LIMIT                   + 1 )
#define S_INVALID                   ( S_BOOST                   + 1 )
#define S_AFTER                     ( S_INVALID                 + 1 )
#define S_PM_HEATUP                 ( S_AFTER                   + 1 )
#define S_PM_HEATUP_TIMED_LIMIT     ( S_PM_HEATUP               + 1 )
#define S_PM_HEATUP_POWER_LIMIT     ( S_PM_HEATUP_TIMED_LIMIT   + 1 )
#define S_PM_HEATUP_TIMED_BOOST     ( S_PM_HEATUP_POWER_LIMIT   + 1 )
#define S_PM_HEATUP_POWER_BOOST     ( S_PM_HEATUP_TIMED_BOOST   + 1 )
#define S_PM_HEATING                ( S_PM_HEATUP_POWER_BOOST   + 1 )
#define S_PM_HEATED                 ( S_PM_HEATING              + 1 )
#define S_PM_ENTER_IDLE             ( S_PM_HEATED               + 1 )
#define S_PM_IDLE                   ( S_PM_ENTER_IDLE           + 1 )
#define S_PM_ENTER_SLEEP            ( S_PM_IDLE                 + 1 )
#define S_PM_SLEEP                  ( S_PM_ENTER_SLEEP          + 1 )
#define S_PM_WAKEUP                 ( S_PM_SLEEP                + 1 )
#define S_PM_WAKEUP_TIMED_BOOST     ( S_PM_WAKEUP               + 1 )
#define S_PM_WAKEUP_POWER_BOOST     ( S_PM_WAKEUP_TIMED_BOOST   + 1 )
#define S_PM_ENTER_POWERDOWN        ( S_PM_WAKEUP_POWER_BOOST   + 1 )
#define S_PM_POWERDOWN              ( S_PM_ENTER_POWERDOWN      + 1 )
#define S_PM_MANUAL_OFF             ( S_PM_POWERDOWN            + 1 )
#define S_PM_MANUAL_LIMIT           ( S_PM_MANUAL_OFF           + 1 )
#define S_PM_MANUAL_NORMAL          ( S_PM_MANUAL_LIMIT         + 1 )
#define S_PM_MANUAL_BOOST           ( S_PM_MANUAL_NORMAL        + 1 )
#define S_PM_OFF                    ( S_PM_MANUAL_BOOST         + 1 )

#define SI_HEATUP                   ( S_PM_OFF                  + 1 )
#define SI_HEATUP_LIMIT_TIMED       ( SI_HEATUP                 + 1 )
#define SI_HEATUP_LIMIT_POWER       ( SI_HEATUP_LIMIT_TIMED     + 1 )
#define SI_HEATUP_BOOST_TIMED       ( SI_HEATUP_LIMIT_POWER     + 1 )
#define SI_HEATUP_BOOST_POWER       ( SI_HEATUP_BOOST_TIMED     + 1 )
#define SI_HEATING                  ( SI_HEATUP_BOOST_POWER     + 1 )
#define SI_HEATED                   ( SI_HEATING                + 1 )
#define SI_IDLE                     ( SI_HEATED                 + 1 )
#define SI_SLEEP                    ( SI_IDLE                   + 1 )
#define SI_WAKEUP                   ( SI_SLEEP                  + 1 )
#define SI_WAKEUP_BOOST_TIMED       ( SI_WAKEUP                 + 1 )
#define SI_WAKEUP_BOOST_POWER       ( SI_WAKEUP_BOOST_TIMED     + 1 )
#define SI_POWERDOWN                ( SI_WAKEUP_BOOST_POWER     + 1 )
#define SI_MANUAL_OFF               ( SI_POWERDOWN              + 1 )
#define SI_MANUAL_LIMIT             ( SI_MANUAL_OFF             + 1 )
#define SI_MANUAL_NORMAL            ( SI_MANUAL_LIMIT           + 1 )
#define SI_MANUAL_BOOST             ( SI_MANUAL_NORMAL          + 1 )
#define SI_OFF                      ( SI_MANUAL_BOOST           + 1 )
#define SI_NO_TIP                   ( SI_OFF                    + 1 )

// menu strings
#define MS_MAINMENU                 ( SI_NO_TIP                 + 1 )
#define MS_MAIN_CONFIG              ( MS_MAINMENU               + 1 )
#define MS_LOAD_SETTINGS            ( MS_MAIN_CONFIG            + 1 )
#define MS_SAVE_SETTINGS            ( MS_LOAD_SETTINGS          + 1 )
#define MS_EDIT_SETTINGS            ( MS_SAVE_SETTINGS          + 1 )
#define MS_SHOW_VERSIONINFO         ( MS_EDIT_SETTINGS          + 1 )
#define MS_RESET                    ( MS_SHOW_VERSIONINFO       + 1 )

// config strings
#define CS_SAVE                         ( MS_RESET                          + 1 )
#define CS_NOSAVE                       ( CS_SAVE                           + 1 )
#define CS_DISCARD                      ( CS_NOSAVE                         + 1 )

#define CS_MAIN_CONFIG                  ( CS_DISCARD                        + 1 )

#define CS_LANGUAGE                     ( CS_MAIN_CONFIG                    + 1 )
#define CS_ENGLISH                      ( CS_LANGUAGE                       + 1 )
#define CS_GERMAN                       ( CS_ENGLISH                        + 1 )

#define CS_BAUDRATE                     ( CS_GERMAN                         + 1 )
#define CS_BAUD_2400                    ( CS_BAUDRATE                       + 1 )
#define CS_BAUD_4800                    ( CS_BAUD_2400                      + 1 )
#define CS_BAUD_7200                    ( CS_BAUD_4800                      + 1 )
#define CS_BAUD_9600                    ( CS_BAUD_7200                      + 1 )
#define CS_BAUD_14400                   ( CS_BAUD_9600                      + 1 )
#define CS_BAUD_19200                   ( CS_BAUD_14400                     + 1 )
#define CS_BAUD_28800                   ( CS_BAUD_19200                     + 1 )
#define CS_BAUD_31520                   ( CS_BAUD_28800                     + 1 )
#define CS_BAUD_38400                   ( CS_BAUD_31520                     + 1 )
#define CS_BAUD_57600                   ( CS_BAUD_38400                     + 1 )
#define CS_BAUD_115200                  ( CS_BAUD_57600                     + 1 )

#define CS_LOGGER                       ( CS_BAUD_115200                    + 1 )
#define CS_LOG_VERSION                  ( CS_LOGGER                         + 1 )
#define CS_LOG_STARTUPS                 ( CS_LOG_VERSION                    + 1 )
#define CS_LOG_MODULES                  ( CS_LOG_STARTUPS                   + 1 )
#define CS_LOG_PARAMETERS               ( CS_LOG_MODULES                    + 1 )
#define CS_LOG_TIME                     ( CS_LOG_PARAMETERS                 + 1 )
#define CS_LOG_NEWLINE                  ( CS_LOG_TIME                       + 1 )

#define CS_STARTUP_SETTINGS             ( CS_LOG_NEWLINE                    + 1 )

// power manager config
#define CS_SELECT_EDITCONFIG            ( CS_STARTUP_SETTINGS               + 1 )
#define CS_SAVE_EDITCONFIG              ( CS_SELECT_EDITCONFIG              + 1 )
#define CS_LOAD_EDITCONFIG              ( CS_SAVE_EDITCONFIG                + 1 )
#define CS_CURRENT_CONFIG               ( CS_LOAD_EDITCONFIG                + 1 )
#define CS_TO_CURRENT_CONFIG            ( CS_CURRENT_CONFIG                 + 1 )
#define CS_FROM_EDIT_CONFIG             ( CS_TO_CURRENT_CONFIG              + 1 )
#define CS_DEFAULT_CONFIG               ( CS_FROM_EDIT_CONFIG               + 1 )
#define CS_CONFIG_NAME                  ( CS_DEFAULT_CONFIG                 + 1 )

#define CS_PM_POWERON_MODE              ( CS_CONFIG_NAME                    + 1 )
#define CS_PM_AUTO_ON                   ( CS_PM_POWERON_MODE                + 1 )
#define CS_PM_AUTO_OFF                  ( CS_PM_AUTO_ON                     + 1 )
#define CS_PM_MANUAL_ON                 ( CS_PM_AUTO_OFF                    + 1 )
#define CS_PM_MANUAL_OFF                ( CS_PM_MANUAL_ON                   + 1 )

#define CS_PM_HEATUP_MODE               ( CS_PM_MANUAL_OFF                    + 1 )
#define CS_PM_HEATUP_NORMAL             ( CS_PM_HEATUP_MODE                 + 1 )
#define CS_PM_HEATUP_LIMIT              ( CS_PM_HEATUP_NORMAL               + 1 )
#define CS_PM_HEATUP_BOOST              ( CS_PM_HEATUP_LIMIT                + 1 )

#define CS_PM_HEATUP_END                ( CS_PM_HEATUP_BOOST                + 1 )
#define CS_PM_HEATUP_END_TIMED          ( CS_PM_HEATUP_END                  + 1 )
#define CS_PM_HEATUP_END_POWERLEVEL     ( CS_PM_HEATUP_END_TIMED            + 1 )

#define CS_PM_HEATUP_END_PARAM          ( CS_PM_HEATUP_END_POWERLEVEL       + 1 )
#define CS_PM_HEATUP_END_LIMIT_TIME     ( CS_PM_HEATUP_END_PARAM            + 1 )
#define CS_PM_HEATUP_END_LIMIT_POWER    ( CS_PM_HEATUP_END_LIMIT_TIME       + 1 )
#define CS_PM_HEATUP_END_BOOST_TIME     ( CS_PM_HEATUP_END_LIMIT_POWER      + 1 )
#define CS_PM_HEATUP_END_BOOST_POWER    ( CS_PM_HEATUP_END_BOOST_TIME       + 1 )

#define CS_PM_IDLE_PARAMETERS           ( CS_PM_HEATUP_END_BOOST_POWER      + 1 )
#define CS_PM_IDLE_THREHOLD             ( CS_PM_IDLE_PARAMETERS             + 1 )
#define CS_PM_ENTER_SLEEP_TIME          ( CS_PM_IDLE_THREHOLD               + 1 )

#define CS_PM_SLEEP_OPTIONS             ( CS_PM_ENTER_SLEEP_TIME            + 1 )
#define CS_PM_ENABLE_SLEEP              ( CS_PM_SLEEP_OPTIONS               + 1 )
#define CS_PM_ENABLE_POWERDOWN          ( CS_PM_ENABLE_SLEEP                + 1 )

#define CS_PM_SLEEPMODE_PARAMETERS      ( CS_PM_ENABLE_POWERDOWN            + 1 )
#define CS_PM_LIGHT_SLEEP_TIME          ( CS_PM_SLEEPMODE_PARAMETERS        + 1 )
#define CS_PM_LIGHT_SLEEP_THRESHOLD     ( CS_PM_LIGHT_SLEEP_TIME            + 1 )
#define CS_PM_SLEEP_THRESHOLD           ( CS_PM_LIGHT_SLEEP_THRESHOLD       + 1 )
#define CS_PM_AUTO_OFF_TIME             ( CS_PM_SLEEP_THRESHOLD             + 1 )

#define CS_PM_WAKEUP_MODE               ( CS_PM_AUTO_OFF_TIME               + 1 )
#define CS_PM_WAKEUP_NORMAL             ( CS_PM_WAKEUP_MODE                 + 1 )
#define CS_PM_WAKEUP_BOOST              ( CS_PM_WAKEUP_NORMAL               + 1 )

#define CS_PM_WAKEUP_END                ( CS_PM_WAKEUP_BOOST                + 1 )
#define CS_PM_WAKEUP_END_TIMED          ( CS_PM_WAKEUP_END                  + 1 )
#define CS_PM_WAKEUP_END_POWERLEVEL     ( CS_PM_WAKEUP_END_TIMED            + 1 )

#define CS_PM_WAKEUP_END_PARAM          ( CS_PM_WAKEUP_END_POWERLEVEL       + 1 )
#define CS_PM_WAKEUP_END_BOOST_TIME     ( CS_PM_WAKEUP_END_PARAM            + 1 )
#define CS_PM_WAKEUP_END_BOOST_POWER    ( CS_PM_WAKEUP_END_BOOST_TIME       + 1 )

#define CS_PM_NORMAL_BACKLIGHT          ( CS_PM_WAKEUP_END_BOOST_POWER      + 1 )
#define CS_PM_SLEEP_BACKLIGHT           ( CS_PM_NORMAL_BACKLIGHT            + 1 )
#define CS_PM_AUTO_OFF_BACKLIGHT        ( CS_PM_SLEEP_BACKLIGHT             + 1 )
#define CS_PM_BACKLIGHT_CONSTANT        ( CS_PM_AUTO_OFF_BACKLIGHT          + 1 )
#define CS_PM_BACKLIGHT_PULSED          ( CS_PM_BACKLIGHT_CONSTANT          + 1 )
#define CS_PM_BACKLIGHT_FLASH           ( CS_PM_BACKLIGHT_PULSED            + 1 )

#define CS_CONSTANT_BACKLIGHT_PARAM     ( CS_PM_BACKLIGHT_FLASH             + 1 )
#define CS_BACKLIGHT_LEVEL              ( CS_CONSTANT_BACKLIGHT_PARAM       + 1 )

#define CS_PULSE_BACKLIGHT_PARAM        ( CS_BACKLIGHT_LEVEL                + 1 )
#define CS_PULSE_BACKLIGHT_LEVEL_LOW    ( CS_PULSE_BACKLIGHT_PARAM          + 1 )
#define CS_PULSE_BACKLIGHT_LEVEL_HIGH   ( CS_PULSE_BACKLIGHT_LEVEL_LOW      + 1 )
#define CS_PULSE_BACKLIGHT_SPEED        ( CS_PULSE_BACKLIGHT_LEVEL_HIGH     + 1 )

#define CS_FLASH_BACKLIGHT_PARAM        ( CS_PULSE_BACKLIGHT_SPEED          + 1 )
#define CS_FLASH_BACKLIGHT_LEVEL_LOW    ( CS_FLASH_BACKLIGHT_PARAM          + 1 )
#define CS_FLASH_BACKLIGHT_LEVEL_HIGH   ( CS_FLASH_BACKLIGHT_LEVEL_LOW      + 1 )
#define CS_FLASH_BACKLIGHT_ON_TIME      ( CS_FLASH_BACKLIGHT_LEVEL_HIGH     + 1 )
#define CS_FLASH_BACKLIGHT_OFF_TIME     ( CS_FLASH_BACKLIGHT_ON_TIME        + 1 )

#endif
