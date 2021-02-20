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

#ifndef ENCODER_H
#define ENCODER_H

#define ENCODER_SPEED_1000      30
#define ENCODER_SPEED_100       80
#define ENCODER_SPEED_10        150

#define BSTATE_IDLE             0
#define BSTATE_FIRSTPUSH        1
#define BSTATE_LONGPUSHED       2
#define BSTATE_FIRSTRELEASE     3
#define BSTATE_SECONDPUSH       4
#define BSTATE_SECONDRELEASE    5
#define BSTATE_DONE             6

#define BUTTON_IDLE             0
#define BUTTON_LONGPUSH         1
#define BUTTON_CLICKED          2
#define BUTTON_CLICKPUSH        3
#define BUTTON_DOUBLECLICKED    4
#define BUTTON_CLEARED          5

#define BUTTON_TIME_SHORT        4
#define BUTTON_TIME_LONG        20

void encoder_init(void);

signed short encoder_get(void);
void encoder_reset(void);

unsigned char encoder_get_button(void);
void encoder_reset_button(void);
void encoder_clear_button(void);

void encoder_reset_all(void);

void process_encoder(void);

#endif
