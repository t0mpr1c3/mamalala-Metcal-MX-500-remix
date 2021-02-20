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

#ifndef LCD_H
#define LCD_H

#define LCD_4BIT    1
// #define LCD_8BIT    1

#define LCD_CHARS_PER_LINE		16
#define LCD_NUM_LINES			2

#define LCD_RS			LATAbits.LATA5
#define LCD_DATA		1
#define LCD_CMD			0

#define LCD_RW			LATAbits.LATA7
#define LCD_READ		1
#define LCD_WRITE		0

#define LCD_ENABLE		LATAbits.LATA6
#define LCD_ENABLE_HI	1
#define LCD_ENABLE_LO	0

#define LCD_DATA_OUT	LATC
#define LCD_DATA_IN	PORTC
#define LCD_DATA_DIR	TRISC

#ifdef LCD_8BIT
#define LCD_DIR_OUT         0b00000000
#define LCD_DIR_IN          0b11111111
#endif

#ifdef LCD_4BIT
#define LCD_DIR_IN_MASK     0b00001111
#define LCD_DIR_OUT_MASK     0b11110000
#define SET_LCD_DIR_OUT()   (LCD_DATA_DIR &= LCD_DIR_OUT_MASK)
#define SET_LCD_DIR_IN()    (LCD_DATA_DIR |= LCD_DIR_IN_MASK)
#endif

#define LCD_CLEAR				0b00000001		// ?? time
#define LCD_RETURN				0b00000010		// 1.52 mS

#define LCD_MODE				0b00000100		// 37 µS
#define LCD_MODE_INCREMENT		0b00000010
#define LCD_MODE_DECREMENT		0b00000000
#define LCD_MODE_SHIFT			0b00000001
#define LCD_MODE_NOSHIFT		0b00000000

#define LCD_CTRL				0b00001000		// 37 µS
#define LCD_CTRL_DISP_ON		0b00000100
#define LCD_CTRL_DISP_OFF		0b00000000
#define LCD_CTRL_CURSOR_ON		0b00000010
#define LCD_CTRL_CURSOR_OFF		0b00000000
#define LCD_CTRL_CURSOR_BLINK	0b00000001
#define LCD_CTRL_CURSOR_NOBLINK	0b00000000

#define LCD_CURSOR_DISPLAY		0b00010000		// 37 µS
#define LCD_DISPLAY_SHIFT		0b00001000
#define LCD_CURSOR_MOVE			0b00000000
#define LCD_SHIFT_RIGHT			0b00000100
#define LCD_SHIFT_LEFT			0b00000000

#define LCD_FUNC_SET			0b00100000		// 37 µS
#define LCD_FUNC_8BIT			0b00010000
#define LCD_FUNC_4BIT			0b00000000
#define LCD_FUNC_2LINE			0b00001000
#define LCD_FUNC_1LINE			0b00000000
#define LCD_FUNC_5x10			0b00000100
#define LCD_FUNC_5x8			0b00000000

#define LCD_SET_CGRAM			0b01000000		// 37 µS
#define LCD_SET_DDRAM			0b10000000		// 37 µS

#ifdef LCD_8BIT
#define LCD_BUSY_FLAG			0b10000000
#endif

#ifdef LCD_4BIT
#define LCD_BUSY_FLAG			0b00001000
#endif

#define LCD_AC					0b01111111

void lcd_init(void);

void lcd_write_string(const rom char *str);
void lcd_write_string_at(unsigned char col, unsigned char row, const rom char *str);

void lcd_write_line_at(unsigned char col, unsigned char row, const rom char *str);
void lcd_write_tr_string_at(unsigned char col, unsigned char row, unsigned short tr_str);
void lcd_write_tr_line_at(unsigned char col, unsigned char row, unsigned short tr_str);
void lcd_write_line_ram_at(unsigned char col, unsigned char row, char *str);

void lcd_write_char_at(unsigned char col, unsigned char row, unsigned char chr);

void lcd_draw_bargraph(unsigned char col, unsigned char row, unsigned short val, unsigned char maxlen);

void lcd_write_num(unsigned char col, unsigned char row, signed short val);
void lcd_write_dnum(unsigned char col, unsigned char row, signed short val);
void lcd_write_vnum(unsigned char col, unsigned char row, unsigned char val);
void lcd_write_longnum_line(unsigned char col, unsigned char row, unsigned char digits, unsigned char decimal, unsigned char leadingzero, unsigned long val);

void lcd_upload_ramglyph(unsigned char chr, unsigned char *glyphdata);
void lcd_upload_ramglyph_line(unsigned char chr, unsigned char lin, unsigned char glyphdata);

void lcd_upload_infoicon_ticker(unsigned char chr, const rom unsigned char *glyphdata, unsigned char tbar);

void lcd_write_time_line(unsigned char col, unsigned char row, unsigned short seconds);

#endif
