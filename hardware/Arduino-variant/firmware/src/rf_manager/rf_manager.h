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

#ifndef RF_MANAGER_H
#define RF_MANAGER_H

typedef struct RFDataStruct
{
    unsigned short supply;
    unsigned short vf;
    unsigned short vr;
    // iswr is an integer representation of the SWR * 100
    unsigned short iswr;
    // ipwr is an integer representation of the bogus power value, range 0..1000
    unsigned short ipwr;
} RFDataType;

#define RF_POWER_OFF                 0
#define RF_POWER_NORMAL              1
#define RF_POWER_BOOST               2
#define RF_POWER_LIMIT               3

#define RF_POWER_RISE                0
#define RF_POWER_DROP                1
#define RF_POWER_COMBINED            2
#define RF_VSWR                      3
#define RF_VFORWARD                  4
#define RF_VREFLECTED                5
#define RF_POWER                     6
#define RF_SUPPLY                    7

void rf_manager_init(void);

void rf_manager_add_delta(void);
void rf_manager_store_delta(void);
void rf_manager_clear_delta(void);

void rf_manager_set_mode(unsigned char val);
unsigned char rf_manager_get_mode(void);
unsigned short rf_manager_get_mode_string(void);

unsigned short rf_manager_get_reading(unsigned char which);

void rf_manager_calc_data(void);

#endif

