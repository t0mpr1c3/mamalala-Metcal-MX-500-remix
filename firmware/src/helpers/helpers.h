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

#ifndef HELPERS_H
#define HELPERS_H

typedef union UShortUnion
{
	unsigned short ushort; //raw;
	struct
	{
		unsigned char byte0; //low;
		unsigned char byte1; //hi;
	};
} UShortType;

typedef union ULongUnion
{
	unsigned long ulong;

        struct
        {
            UShortType  UShortType0;
            UShortType  UShortType1;
        };

        struct
        {       unsigned short short0;
                unsigned short short1;
        };
        
	struct
	{
		unsigned char byte0;
		unsigned char byte1;
		unsigned char byte2;
		unsigned char byte3;
	};
} ULongType;

typedef struct TimeDataStruct
{
    unsigned short in_seconds;
    unsigned char hours;
    unsigned char minutes;
    unsigned char seconds;

} TimeDataType;


#define set_ui_func(_X_)    { uifunc = _X_; }

extern TimeDataType time_data;

void reset_pic(void);
void empty_callback(void);
void seconds_to_time(unsigned short secs);
void divmod_set(unsigned long remainder, unsigned long divider);
void divmod_set_remainder(unsigned long remainder);
unsigned long divmod_get_remainder(void);
void divmod_set_divider(unsigned long divider);
unsigned long divmod_get_divider(void);
unsigned char divmod(void);
void copy_romstring_to_ram(const rom char *src, char *dst, unsigned char len);
unsigned short get_delta_ushort(unsigned short val1, unsigned short val2);

#endif
