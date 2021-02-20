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

#ifndef BACKLIGHT_H
#define BACKLIGHT_H

#define LCD_BACKLIGHT	LATBbits.LATB3

#define BACKLIGHT_CONSTANT      0b00000001
#define BACKLIGHT_FADE          0b00000010
#define BACKLIGHT_PULSE         0b00000100
#define BACKLIGHT_FLASH         0b00001000
#define BACKLIGHT_UP            0b00010000
#define BACKLIGHT_DOWN          0b00100000
#define BACKLIGHT_FLASHOFF      0b01000000
#define BACKLIGHT_FLASHON       0b10000000
#define BACKLIGHT_LEVEL_MASK    0b00111111

void backlight_init(void);
void backlight_enter_temp(void);
void backlight_leave_temp(void);
void backlight_set(unsigned char bval);
void backlight_mode(unsigned char mval);
void backlight_process(void);

void backlight_fade(unsigned char target, unsigned short speed);

void backlight_set_pulse(unsigned char low, unsigned char hi, unsigned short speed);
void backlight_start_pulse(void);

void backlight_set_flash(unsigned char low, unsigned char hi, unsigned short ton, unsigned short toff);
void backlight_start_flash(void);

#endif

