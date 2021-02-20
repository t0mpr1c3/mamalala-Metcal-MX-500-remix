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

#ifndef POWER_MANAGER_H
#define	POWER_MANAGER_H

#define PM_HEATUP                    0
#define PM_HEATUP_TIMED_LIMIT        1
#define PM_HEATUP_POWER_LIMIT        2
#define PM_HEATUP_TIMED_BOOST        3
#define PM_HEATUP_POWER_BOOST        4
#define PM_HEATING                   5
#define PM_HEATED                    6
#define PM_IDLE                      7
#define PM_ENTER_SLEEP               8
#define PM_SLEEP                     9
#define PM_WAKEUP                   10
#define PM_WAKEUP_TIMED_BOOST       11
#define PM_WAKEUP_POWER_BOOST       12
#define PM_ENTER_POWERDOWN          13
#define PM_POWERDOWN                14
#define PM_MANUAL_OFF               15
#define PM_MANUAL_LIMIT             16
#define PM_MANUAL_NORMAL            17
#define PM_MANUAL_BOOST             18
#define PM_OFF                      19

#define PM_CFG_NONE                 0b00000000
#define PM_CFG_ENABLE_SLEEP         0b00000001
#define PM_CFG_ENABLE_POWERDOWN     0b00000010

#define PM_CFG_HEATUP_NORMAL        0b00000000
#define PM_CFG_HEATUP_LIMIT         0b00000001
#define PM_CFG_HEATUP_BOOST         0b00000010
#define PM_CFG_HEATUP_TIMED         0b00000100
#define PM_CFG_HEATUP_POWER         0b00001000

#define PM_CFG_WAKEUP_NORMAL        0b00000000
#define PM_CFG_WAKEUP_BOOST         0b00000001
#define PM_CFG_WAKEUP_TIMED         0b00000010
#define PM_CFG_WAKEUP_POWER         0b00000100

#define STARTUP_OFF             0b00000000
#define STARTUP_ON              0b00000001
#define STARTUP_MANUAL          0b00000010

extern unsigned short max_rise, max_drop, max_combined;

void power_manager_init(void);
void power_manager_init_state(void);
void power_manager_reset(void);
void power_manager_process(void);

void power_manager_set_state(unsigned char new_state);
unsigned char power_manager_get_state(void);
unsigned short power_manager_get_state_string(void);

void power_manager_set_config(unsigned char cfg);
void power_manager_set_sleeptime(unsigned short stime);

unsigned long power_manager_get_state_seconds(void);

#endif

