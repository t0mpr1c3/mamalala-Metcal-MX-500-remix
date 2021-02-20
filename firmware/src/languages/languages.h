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

#ifndef LANGUAGES_H
#define LANGUAGES_H

extern rom char *rom *current_strings;
extern rom char *rom *current_menu_strings;
extern rom char *rom *current_config_strings;

void languages_init(void);
void languages_set_lang(unsigned char lang);
void languages_reload(void);
unsigned char languages_get_lang(void);

#endif
