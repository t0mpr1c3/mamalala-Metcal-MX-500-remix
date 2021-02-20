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

#ifndef EEPROM_H
#define EEPROM_H

#include "config_manager.h"

unsigned char eeprom_read_byte(unsigned short addr);
void eeprom_read_block(unsigned short addr, unsigned short numbytes, unsigned char *data);

void eeprom_write_byte(unsigned short addr, unsigned char data);
void eeprom_write_block(unsigned short addr, unsigned short numbytes, unsigned char *data);

#endif
