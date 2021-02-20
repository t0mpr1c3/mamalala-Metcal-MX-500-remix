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

#ifndef TIME_H
#define	TIME_H

void time_init(void);
void time_reset_ticks(void);

unsigned long time_get_seconds(void);
unsigned long time_get_delta_seconds(void);
unsigned long time_get_reset_delta_seconds(void);

unsigned long time_get_ticks(void);
unsigned long time_get_delta_ticks(void);
unsigned long time_get_reset_delta_ticks(void);

void time_interrupt(void);

#endif


