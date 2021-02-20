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

#ifndef CONFIG_MEMORY_H
#define CONFIG_MEMORY_H

#include "version.h"

typedef struct ConfigDataStructDef
{
    char            name[17];                   //   Name of this configuration

    // default startup config
    unsigned char   startup_default;            //   Start in auto- or manu-mode, either on or off

    // heatup config
    unsigned char   heatup_config;             //   Initial auto-mode
    unsigned char   heatup_limit_time;         //   1
    unsigned short  heatup_limit_power;        //   2
    unsigned char   heatup_boost_time;         //   1
    unsigned short  heatup_boost_power;        //   2

    // idle mode config
    unsigned char   idle_threshold;             //   max. power change allowed for idle mode

    // sleep mode config
    unsigned char   sleep_config;                  //   General power manager config
    unsigned short  enter_sleep_time;           //   idle time in seconds to enter sleep mode
    unsigned char   light_sleep_time;           //   time spent in initial sleep mode in seconds
    unsigned char   light_sleep_threshold;      //   max. power change allowed for initial mode
    unsigned char   sleep_threshold;            //   max. power change allowed for sleep mode
    unsigned short  enter_off_time;                   //   2

    // wakeup config
    unsigned char   wakeup_config;              //   Mode when waking up
    unsigned char   wakeup_boost_time;          //   1
    unsigned short  wakeup_boost_power;         //   2

    // backlight mode used to indicate different main states
    unsigned char   normal_backlight;           //   1
    unsigned char   sleep_backlight;            //   1
    unsigned char   auto_off_backlight;         //   1

    // backlight constant mode level
    unsigned char   backlight_constant_level;   //   1

    // backlight pulsing mode parameters
    unsigned char   low_pulse_backlight;        //   1
    unsigned char   hi_pulse_backlight;         //   1
    unsigned short  backlight_pulse_speed;      //   2

    // backlight flashing mode parameters
    unsigned char   low_flash_backlight;        //   1
    unsigned char   hi_flash_backlight;         //   1
    unsigned short  backlight_flash_ton;        //   2
    unsigned short  backlight_flash_toff;       //   2

} ConfigDataStruct;

typedef union ConfigDataTypeDef
{
    unsigned char       raw[sizeof(ConfigDataStruct)+4];
    struct
    {
        unsigned char   data[sizeof(ConfigDataStruct)];
        unsigned short  config_ok;
        unsigned short  crc;
    };
    struct              ConfigDataStructDef;
} ConfigDataType;

typedef struct MainConfigDataStructDef
{
    unsigned char   version_major;
    unsigned char   version_minor;
    unsigned char   language;
    unsigned char   baudrate;
    unsigned char   logger_config;
    unsigned char   config_num;

} MainConfigDataStruct;

typedef union MainConfigDataTypeDef
{
    unsigned char       raw[sizeof(MainConfigDataStruct)+2];
    struct
    {
        unsigned char   data[sizeof(MainConfigDataStruct)];
        unsigned short  crc;
    };
    struct              MainConfigDataStructDef;
} MainConfigDataType;

#define MAIN_CONFIG_SIZE            sizeof(MainConfigDataType)
#define MAIN_CONFIG_PAYLOAD_SIZE    sizeof(MainConfigDataStruct)

#define CONFIG_SIZE                 sizeof(ConfigDataType)
#define CONFIG_PAYLOAD_SIZE         sizeof(ConfigDataStruct)

#define MAIN_CONFIG_START       0

#define CONFIG_1_START          ( 0 + MAIN_CONFIG_SIZE )
#define CONFIG_2_START          ( CONFIG_1_START + CONFIG_SIZE )
#define CONFIG_3_START          ( CONFIG_2_START + CONFIG_SIZE )
#define CONFIG_4_START          ( CONFIG_3_START + CONFIG_SIZE )
#define CONFIG_5_START          ( CONFIG_4_START + CONFIG_SIZE )
#define CONFIG_6_START          ( CONFIG_5_START + CONFIG_SIZE )
#define CONFIG_7_START          ( CONFIG_6_START + CONFIG_SIZE )
#define CONFIG_8_START          ( CONFIG_7_START + CONFIG_SIZE )

#define CONFIG_END              ( CONFIG_8_START + CONFIG_SIZE )

#define NUM_CONFIGS             8

#define CONFIG_OK_SIGNATURE     0xA55A


#define CONFIG_EDIT_TO_ACTIVE       0
#define CONFIG_ACTIVE_TO_EDIT       1


extern MainConfigDataType main_config;

//extern ConfigDataType config;
extern ConfigDataType edit_config;
extern ConfigDataType active_config;


void config_memory_init(void);

void config_memory_default_main_config(void);
unsigned char config_memory_load_main_config(void);
void config_memory_save_main_config(void);

void config_memory_default_config(unsigned char cfg_num);
unsigned char config_memory_load_config(unsigned char cfg_num);
void config_memory_save_config(unsigned char cfg_num);


unsigned char config_memory_check_config(unsigned char cfg_num);
char* config_memory_get_name(unsigned char cfg_num);
void config_memory_swap(unsigned char swp);

#endif

