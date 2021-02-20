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

#pragma udata access _CRCDATA
static near unsigned char CRCD;
static near unsigned short CRC;
#pragma udata

// initialize the CRC16
void crc_set_seed(unsigned short seed)
{
    CRC = seed;
}

void crc_core(void)
{
    _asm
    MOVF	CRCD, W, ACCESS
    XORWF	CRC+1, F, ACCESS
    MOVLW	0
    BTFSC	CRC+1, 0, ACCESS
    XORLW	33
    BTFSC	CRC+1, 1, ACCESS
    XORLW	66
    BTFSC	CRC+1, 2, ACCESS
    XORLW	132
    BTFSC	CRC+1, 3, ACCESS
    XORLW	8
    BTFSC 	CRC+1, 4, ACCESS
    XORLW	49
    BTFSC	CRC+1, 5, ACCESS
    XORLW	98
    BTFSC	CRC+1, 6, ACCESS
    XORLW	196
    BTFSC	CRC+1, 7, ACCESS
    XORLW	136
    XORWF	CRC, F, ACCESS
    XORWF	CRC, W, ACCESS
    XORWF	CRC, F, ACCESS
    BTFSC	CRC+1, 0, ACCESS
    XORLW	16
    BTFSC	CRC+1, 1, ACCESS
    XORLW	32
    BTFSC	CRC+1, 2, ACCESS
    XORLW	64
    BTFSC	CRC+1, 3, ACCESS
    XORLW	129
    BTFSC	CRC+1, 4, ACCESS
    XORLW	18
    BTFSC	CRC+1, 5, ACCESS
    XORLW	36
    BTFSC	CRC+1, 6, ACCESS
    XORLW	72
    BTFSC	CRC+1, 7, ACCESS
    XORLW	145
    MOVWF	CRC+1, ACCESS
    _endasm;
}

unsigned short crc_calc_block(unsigned short seed, unsigned char numbytes, unsigned char *data)
{
    CRC = seed;
    while(numbytes--)
    {
	CRCD = *data++;
        crc_core();
    }
    return CRC;
}

unsigned short crc_calc_byte(unsigned char data)
{
    CRCD = data;
    crc_core();
    return CRC;
}
