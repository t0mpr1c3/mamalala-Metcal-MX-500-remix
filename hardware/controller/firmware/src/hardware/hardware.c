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

static unsigned long cnt1;

void hardware_init(void)
{
	// configure oscillator, internal 8MHz, x4 PLL
	OSCCON = 0b11110000;

        while(OSCCONbits.IOFS == 0)
        {
            _asm NOP _endasm;
        }

	OSCTUNE = 0b01000000;
/*
        while(OSCCONbits.OSTS == 0)
        {
            _asm NOP _endasm;
        }
*/
        ADCON0	= 0b00000000;
	ADCON1	= 0b00001100;
//	ADCON2	= 0b00001001;

	SSPCON1 = 0b00000000;
	CMCON	= 0b00000111;
	CVRCON	= 0x00000000;
	T0CON	= 0b00000000;

	INTCON2bits.RBPU = 0;

	LATA = CFG_LATA;
	LATC = CFG_LATC;
	LATB = CFG_LATB;

        TRISA = CFG_TRISA;
	TRISB = CFG_TRISB;
	TRISC = CFG_TRISC;

        CCPR2L = 0;
}


