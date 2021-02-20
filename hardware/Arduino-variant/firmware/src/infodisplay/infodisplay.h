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

#ifndef INFODISPLAY_H
#define	INFODISPLAY_H

void infodisplay_init(void);
void infodisplay_reset(void);
void infodisplay_show_version(void);
void infodisplay_show_powericon(unsigned char col, unsigned char row, unsigned char ico);
void infodisplay_update_powericon(unsigned char ico);
void infodisplay_update_powericon_tick(void);
void infodisplay_show(void);

#endif

