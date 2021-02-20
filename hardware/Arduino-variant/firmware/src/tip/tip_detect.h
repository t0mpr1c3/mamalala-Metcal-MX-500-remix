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

#ifndef TIP_DETECT_H
#define TIP_DETECT_H

#define TIP_OK      1
#define TIP_MISSING 0

void tip_detect_init(void);
void tip_detect_process(void);
unsigned char tip_detect_get_status(void);

#endif
