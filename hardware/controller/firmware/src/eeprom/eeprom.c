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

static unsigned char old_gie;
static unsigned short ee_cnt;
static UShortType addr_short;

unsigned char eeprom_read_byte(unsigned short addr)
{
    addr_short.ushort   = addr;
    EEADR               = addr_short.byte0;
    EEADRH              = addr_short.byte1;
    EECON1bits.CFGS     = 0;
    EECON1bits.EEPGD    = 0;
    EECON1bits.WREN     = 0;
    INTCONbits.GIE      = 1;
    EECON1bits.RD       = 1;
    return EEDATA;
}

void eeprom_read_block(unsigned short addr, unsigned short numbytes, unsigned char *data)
{
/*
    EEADR               = addr;
    EECON1bits.CFGS     = 0;
    EECON1bits.EEPGD    = 0;
    EECON1bits.WREN     = 0;
    INTCONbits.GIE      = 1;
*/
    addr_short.ushort   = addr;

    for(ee_cnt = 0; ee_cnt < numbytes; ee_cnt++)
    {
        EEADR               = addr_short.byte0;
        EEADRH              = addr_short.byte1;
        addr_short.ushort++;

        EECON1bits.CFGS     = 0;
        EECON1bits.EEPGD    = 0;
        EECON1bits.WREN     = 0;
        EECON1bits.RD   = 1;
        *data++         = EEDATA;
    }
}

void eeprom_write_byte(unsigned short addr,unsigned char data)
{
    if(INTCONbits.GIE == 1)
    {
        old_gie = 1;
    }
    else
    {
        old_gie = 0;
    }

    addr_short.ushort   = addr;
    EEADR               = addr_short.byte0;
    EEADRH              = addr_short.byte1;

    EEDATA = data;
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    EECON1bits.WREN = 1;
    INTCONbits.GIE = 0;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;

    if(old_gie == 1)
    {
        INTCONbits.GIE = 1;
    }
    
    EECON1bits.WREN = 0;
    while(EECON1bits.WR)
    {
        _asm NOP _endasm
    }
}

void eeprom_write_block(unsigned short addr, unsigned short numbytes, unsigned char *data)
{
    if(INTCONbits.GIE == 1)
    {
        old_gie = 1;
    }
    else
    {
        old_gie = 0;
    }

    addr_short.ushort   = addr;

    for(ee_cnt = 0; ee_cnt < numbytes; ee_cnt++)
    {
        EEADR               = addr_short.byte0;
        EEADRH              = addr_short.byte1;

        addr_short.ushort++;

        EEDATA = *data++;
        EECON1bits.EEPGD = 0;
        EECON1bits.CFGS = 0;
        EECON1bits.WREN = 1;
        INTCONbits.GIE = 0;
        EECON2 = 0x55;
        EECON2 = 0xAA;
        EECON1bits.WR = 1;

        if(old_gie == 1)
        {
            INTCONbits.GIE = 1;
        }

        EECON1bits.WREN = 0;
        while(EECON1bits.WR)
        {
            _asm NOP _endasm
        }
    }
}

