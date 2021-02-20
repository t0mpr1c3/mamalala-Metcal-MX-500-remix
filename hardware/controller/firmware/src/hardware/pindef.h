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

#ifndef PINDEF_H
#define PINDEF_H

#define PIN_IN		1
#define PIN_OUT		0

// 1 = in, 0 = out

#define CFG_TRISA	0b00001111;
#define CFG_LATA	0b00000000;

#define CFG_TRISB	0b00110111;
#define CFG_LATB	0b00000000;

#define CFG_TRISC	0b10000000;
#define CFG_LATC	0b00000000;

#define V_FORWARD_IN            PORTAbits.RA0
#define V_REFLECTED_IN          PORTAbits.RA1
#define V_REG_IN		PORTAbits.RA2

#define VLIM_OUT		LATAbits.LATA3
#define VLIM_DIR		TRISAbits.TRISA3

#define RFG_EN			LATAbits.LATA4

#define TIP_DET 		PORTBbits.RB0

#define ENC1_A			PORTBbits.RB1
#define ENC1_B			PORTBbits.RB2
#define ENC1_K			PORTBbits.RB4
#define ENC1_S			PORTBbits.RB5


#define BL			LATBbits.LATB3
#define BL_ON			1
#define BL_OFF			0

#define PGD				PORTBbits.RB7
#define PGC				PORTBbits.RB6

#define MCLR			PORTEbits.RE3

#endif
