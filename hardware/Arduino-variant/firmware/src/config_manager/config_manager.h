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

#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

void config_manager_init(void);
unsigned char config_manager_load_main_config(void);
unsigned char config_manager_load_config(unsigned char config_num);
void config_manager_activate_config(void);

#endif

