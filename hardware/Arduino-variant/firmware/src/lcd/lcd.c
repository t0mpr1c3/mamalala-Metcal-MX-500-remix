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

#include "rfsupply.h"

static unsigned char res, lz;

void lcd_delay_short(void)
{
    static unsigned short cnt;

    for(cnt = 0; cnt < 100; cnt ++) // 250
    {
        _asm NOP _endasm;
    }
}

void lcd_delay_long(void)
{
    static unsigned short cnt;

    for(cnt = 0; cnt < 2500; cnt ++) // 2500
    {
        _asm NOP _endasm;
    }
}

void lcd_write_data_single(unsigned char dta)
{
    LCD_RS = LCD_DATA;
    LCD_RW = LCD_WRITE;
    SET_LCD_DIR_OUT();

    lcd_delay_short();

    LCD_DATA_OUT = (dta>>4);

    LCD_ENABLE = LCD_ENABLE_HI;
    LCD_ENABLE = LCD_ENABLE_LO;

    LCD_DATA_OUT = (dta & 0x0F);

    LCD_ENABLE = LCD_ENABLE_HI;
    LCD_ENABLE = LCD_ENABLE_LO;
}	

void lcd_write_command_single(unsigned char cmd)
{
    LCD_RS = LCD_CMD;
    LCD_RW = LCD_WRITE;
    SET_LCD_DIR_OUT();

    lcd_delay_short();

    LCD_DATA_OUT = (cmd >> 4);

    LCD_ENABLE = LCD_ENABLE_HI;
    LCD_ENABLE = LCD_ENABLE_LO;

    LCD_DATA_OUT = (cmd & 0x0F);

    LCD_ENABLE = LCD_ENABLE_HI;
    LCD_ENABLE = LCD_ENABLE_LO;
}	


void lcd_init(void)
{
    static unsigned long cnt1;
    static unsigned char cnt2;

    cnt1 = 100000;
    while(cnt1--) { _asm NOP _endasm; }

    // init display in 4-bit mode
    lcd_write_command_single(0x33);
    lcd_write_command_single(0x32);

    lcd_write_command_single(LCD_FUNC_SET | LCD_FUNC_4BIT | LCD_FUNC_5x8 | LCD_FUNC_2LINE);
    lcd_delay_long();

    lcd_write_command_single(LCD_CTRL | LCD_CTRL_DISP_OFF);
    lcd_delay_long();

    lcd_write_command_single(LCD_CLEAR);
    lcd_delay_long();

    lcd_write_command_single(LCD_MODE | LCD_MODE_INCREMENT | LCD_MODE_NOSHIFT);
    lcd_delay_long();

    lcd_write_command_single(LCD_CTRL | LCD_CTRL_DISP_ON | LCD_CTRL_CURSOR_OFF | LCD_CTRL_CURSOR_NOBLINK);
    lcd_delay_long();

    CCP2CON = 0b00001100;
    PR2 = 0xFF;
    TMR2 = 0;
    T2CON = 0b01111000;
    CCPR2L = 0x00;
    T2CONbits.TMR2ON = 1;

    lcd_write_string("----------------");

    for(cnt2 = 0x10; cnt2 < 0x18; cnt2++)
    {
        lcd_write_command_single(LCD_SET_CGRAM | cnt2);
        lcd_write_data_single(0xFF);
    }

    lcd_write_string_at(0, 0, "                ");
}

void lcd_write_string(const rom char *str)
{
    do
    {
        lcd_write_data_single(*str++);
    } while(*str);
}

void lcd_moveto(unsigned char col, unsigned char row)
{
    static unsigned char adr;
    
    adr = col;
    if(row)
    {
        adr |= 0x40;
    }

    lcd_write_command_single(LCD_SET_DDRAM | adr);
}

void lcd_write_string_at(unsigned char col, unsigned char row, const rom char *str)
{
    lcd_moveto(col, row);

    do
    {
            lcd_write_data_single(*str++);
    } while(*str);
}


void lcd_write_line_at(unsigned char col, unsigned char row, const rom char *str)
{
    static unsigned char nc;

    nc = 0;

    lcd_moveto(0, row);

    while(nc++ < col)
    {
        lcd_write_data_single(' ');
    }

    do
    {
        lcd_write_data_single(*str++);
        nc++;
    } while(*str);

    while(nc++ <= LCD_CHARS_PER_LINE)
    {
        lcd_write_data_single(' ');
    }
}

void lcd_write_tr_string_at(unsigned char col, unsigned char row, unsigned short tr_str)
{
    static const rom char *str;

    str = (const rom char*)tr(tr_str);

    lcd_moveto(col, row);

    do
    {
        lcd_write_data_single(*str++);
    } while(*str);
}

void lcd_write_tr_line_at(unsigned char col, unsigned char row, unsigned short tr_str)
{
    static unsigned char nc;
    static const rom char *str;

    str = (const rom char*)tr(tr_str);

    nc = 0;

    lcd_moveto(0, row);

    while(nc++ < col)
    {
        lcd_write_data_single(' ');
    }

    do
    {
        lcd_write_data_single(*str++);
        nc++;
    } while(*str);

    while(nc++ <= LCD_CHARS_PER_LINE)
    {
        lcd_write_data_single(' ');
    }
}

void lcd_write_line_ram_at(unsigned char col, unsigned char row, char *str)
{
    static unsigned char nc;

    nc = 0;

    lcd_moveto(0, row);

    while(nc++ < col)
    {
        lcd_write_data_single(' ');
    }

    do
    {
        lcd_write_data_single(*str++);
        nc++;
    } while(*str);

    while(nc++ <= LCD_CHARS_PER_LINE)
    {
        lcd_write_data_single(' ');
    }
}

void lcd_write_char_at(unsigned char col, unsigned char row, unsigned char chr)
{
    lcd_moveto(col, row);

    lcd_write_data_single(chr);
}

// input range = 0-1000
void lcd_draw_bargraph(unsigned char col, unsigned char row, unsigned short val, unsigned char maxlen)
{
    static unsigned char pos, uchar;
    static unsigned char remainder;
    static unsigned char fval;
    static ULongType A;


    A.short1 = val;
    A.short0 = 0;
    A.ulong >>= 10;
    A.ulong *= maxlen;
    fval = A.byte2;

    lcd_moveto(col, row);

    pos = col;

    remainder = fval;

    while(remainder >= 5)
    {
        remainder -= 5;
        lcd_write_data_single(0x02);
        pos++;
    }

    if(remainder)
    {
        uchar = 0x1F;
        uchar <<= (5-remainder);


        if(row)
        {
            lcd_write_command_single(LCD_SET_CGRAM | 0x08);
        }
        else
        {
            lcd_write_command_single(LCD_SET_CGRAM | 0x00);
        }

        for(remainder = 0; remainder < 8; remainder++)
        {
            lcd_write_data_single(uchar);
        }

        lcd_write_command_single(LCD_SET_DDRAM | pos);

        if(row)
        {
            lcd_write_data_single(0x01);
        }
        else
        {
            lcd_write_data_single(0x00);
        }

        pos++;
    }

    while(pos < LCD_CHARS_PER_LINE)
    {
        lcd_write_data_single(' ');
        pos++;
    }
}

void lcd_write_num(unsigned char col, unsigned char row, signed short val)
{
    lcd_moveto(col, row);

    if(val < 0)
    {
        val = -val;
        lcd_write_data_single('-');
    }
    else
    {
        lcd_write_data_single(' ');
    }

    divmod_set(val, 1000);
    lcd_write_data_single('0'+divmod());

    divmod_set_divider(100);
    lcd_write_data_single('0'+divmod());

    divmod_set_divider(10);
    lcd_write_data_single('0'+divmod());

    lcd_write_data_single('0'+divmod_get_remainder());
}

void lcd_write_dnum(unsigned char col, unsigned char row, signed short val)
{
    static unsigned char res;

    lcd_moveto(col, row);

    divmod_set(val, 1000);

    res = divmod();

    if(res > 0)
    {
        lcd_write_data_single('0'+res);
    }
    else
    {
        lcd_write_data_single(' ');
    }

    divmod_set_divider(100);
    lcd_write_data_single('0'+divmod());

    lcd_write_data_single('.');

    divmod_set_divider(10);
    lcd_write_data_single('0'+divmod());

    lcd_write_data_single('0'+divmod_get_remainder());
}

void lcd_write_vnum(unsigned char col, unsigned char row, unsigned char val)
{
    lcd_moveto(col, row);

    if(val >= 100)
    {
        val = 99;
    }

    divmod_set(val, 10);
    lcd_write_data_single('0'+divmod());

    lcd_write_data_single('0'+divmod_get_remainder());
}



void lcd_put_digit(void)
{
    res = divmod();
    if(res == 0)
    {
        if(lz)
        {
            lcd_write_data_single('0');
        }
        else
        {
            lcd_write_data_single(' ');
        }
    }
    else
    {
        lz = 1;
        lcd_write_data_single('0'+res);
    }
}



void lcd_write_longnum_line(unsigned char col, unsigned char row, unsigned char digits, unsigned char decimal, unsigned char leadingzero, unsigned long val)
// unsigned char col
// unsigned char row
// unsigned char digits
// unsigned char decimal
// unsigned char leadingzero
// unsigned long val
{
    static unsigned char pos;

    pos = 0;
    lz = leadingzero;
    
    lcd_moveto(0, row);

    while(pos < col)
    {
        pos++;
        lcd_write_data_single(' ');
    }

    divmod_set_remainder(val);

    if (digits == 10)
    {
        goto TEN_DIGITS;
    }
    else if (digits == 9)
    {
        goto NINE_DIGITS;
    }
    else if (digits == 8)
    {
        goto EIGHT_DIGITS;
    }
    else if (digits == 7)
    {
        goto SEVEN_DIGITS;
    }
    else if (digits == 6)
    {
        goto SIX_DIGITS;
    }
    else if (digits == 5)
    {
        goto FIVE_DIGITS;
    }
    else if(digits == 4)
    {
        goto FOUR_DIGITS;
    }
    else if(digits == 3)
    {
        if(decimal == 3)
        {
            lcd_write_data_single('0');
            pos++;
            lz = 1;
        }
        goto THREE_DIGITS;
    }
    else if(digits == 2)
    {
        if(decimal == 2)
        {
            lcd_write_data_single('0');
            pos++;
            lz = 1;
        }
        goto TWO_DIGITS;
    }
    else if(digits == 1)
    {
        if(decimal == 1)
        {
            lcd_write_data_single('0');
            pos++;
        }
        goto ONE_DIGIT;
    }

TEN_DIGITS:
    divmod_set_divider(1000000000);
    lcd_put_digit();
    pos++;

NINE_DIGITS:
    divmod_set_divider(100000000);
    lcd_put_digit();
    pos++;

EIGHT_DIGITS:
    divmod_set_divider(10000000);
    lcd_put_digit();
    pos++;

SEVEN_DIGITS:
    divmod_set_divider(1000000);
    lcd_put_digit();
    pos++;

SIX_DIGITS:
    divmod_set_divider(100000);
    lcd_put_digit();
    pos++;

FIVE_DIGITS:
    divmod_set_divider(10000);
    lcd_put_digit();
    pos++;

FOUR_DIGITS:
    divmod_set_divider(1000);
    lcd_put_digit();
    pos++;

THREE_DIGITS:
    divmod_set_divider(100);
    if(decimal == 3)
    {
        lcd_write_data_single('.');
        pos++;
    }
    lcd_put_digit();
    pos++;

TWO_DIGITS:
    divmod_set_divider(10);
    if(decimal == 2)
    {
        lcd_write_data_single('.');
        pos++;
    }
    lcd_put_digit();
    pos++;

ONE_DIGIT:
    divmod_set_divider(1);
    if(decimal == 1)
    {
        lcd_write_data_single('.');
        pos++;
    }
    lz = 1;
    lcd_put_digit();
    pos++;

    while(pos < LCD_CHARS_PER_LINE)
    {
        lcd_write_data_single(' ');
        pos++;
    }
}





void lcd_upload_ramglyph(unsigned char chr, unsigned char *glyphdata)
{
    lcd_write_command_single(LCD_SET_CGRAM | (chr * 8));

    lcd_write_data_single(*glyphdata++);
    lcd_write_data_single(*glyphdata++);
    lcd_write_data_single(*glyphdata++);
    lcd_write_data_single(*glyphdata++);
    lcd_write_data_single(*glyphdata++);
    lcd_write_data_single(*glyphdata++);
    lcd_write_data_single(*glyphdata++);
    lcd_write_data_single(*glyphdata++);
}

void lcd_upload_ramglyph_line(unsigned char chr, unsigned char lin, unsigned char glyphdata)
{
    lcd_write_command_single(LCD_SET_CGRAM | ((chr * 8) + lin) );

    lcd_write_data_single(glyphdata);
}

void lcd_upload_infoicon_ticker(unsigned char chr, const rom unsigned char *glyphdata, unsigned char tbar)
{
    lcd_write_command_single(LCD_SET_CGRAM | (chr * 8));

    lcd_write_data_single(*glyphdata++);
    lcd_write_data_single(*glyphdata++);
    lcd_write_data_single(*glyphdata++);
    lcd_write_data_single(*glyphdata++);
    lcd_write_data_single(*glyphdata++);
    lcd_write_data_single(*glyphdata++);
    lcd_write_data_single(*glyphdata++);
    lcd_write_data_single(tbar);
}

void lcd_write_time_line(unsigned char col, unsigned char row, unsigned short seconds)
{
    seconds_to_time(seconds);

    lcd_write_vnum(col, row, time_data.hours);

    lcd_write_char_at(col+2, row, ':');

    lcd_write_vnum(col+3, row, time_data.minutes);

    lcd_write_char_at(col+5, row, ':');
    
    lcd_write_vnum(col+6, row, time_data.seconds);

    lcd_write_string_at(col+8, row, "        ");
}
