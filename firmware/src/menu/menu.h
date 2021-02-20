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

#ifndef MENU_H
#define MENU_H

#define MENU_STACKSIZE     16

void menu_start(const rom void *callerfunc);
void menu_return(void);
void menu_exit(void);
void menu_show_name(unsigned char row);
void menu_show_entry(unsigned char row);
void menu_exec(void);

#endif
