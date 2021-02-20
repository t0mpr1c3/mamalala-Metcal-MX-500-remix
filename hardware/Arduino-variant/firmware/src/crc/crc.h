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

#ifndef CRC_H
#define CRC_H

#define MAIN_CONFIG_SEED    0x1F7C
#define CONFIG_SEED         0x8AE3

void crc_set_seed(unsigned short seed);
unsigned short crc_calc_block(unsigned short seed, unsigned char numbytes, unsigned char *data);
unsigned short crc_calc_byte(unsigned char data);

#endif
