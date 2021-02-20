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

TimeDataType time_data;

void reset_pic(void)
{
    _asm reset _endasm
}

void empty_callback(void)
{
}

void seconds_to_time(unsigned short secs)
{
    unsigned short s;

    time_data.seconds = 0;
    time_data.minutes = 0;
    time_data.hours = 0;

    s = secs;

    while(s >= 3600)
    {
        time_data.hours++;
        s -= 3600;
    }

    while(s >= 60)
    {
        time_data.minutes++;
        s -= 60;
    }

    time_data.seconds = s;
}

static unsigned long rem, div;

void divmod_set(unsigned long remainder, unsigned long divider)
{
    rem = remainder;
    div = divider;
}

void divmod_set_remainder(unsigned long remainder)
{
    rem = remainder;
}

unsigned long divmod_get_remainder(void)
{
    return rem;
}

void divmod_set_divider(unsigned long divider)
{
    div = divider;
}

unsigned long divmod_get_divider(void)
{
    return div;
}

unsigned char divmod(void)
{
    static unsigned char res;

    res = 0;
    while(rem >= div)
    {
        rem -= div;
        res++;
    }

    return res;
}

void copy_romstring_to_ram(const rom char *src, char *dst, unsigned char len)
{
    while(len--)
    {
        *dst++ = *src++;
    }
}

unsigned short get_delta_ushort(unsigned short val1, unsigned short val2)
{
    if(val1 > val2)
    {
        return (val1 - val2);
    }
    else
    {
        return (val2 - val1);
    }
}
