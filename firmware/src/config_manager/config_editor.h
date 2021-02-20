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

#ifndef CONFIG_EDITOR_H
#define CONFIG_EDITOR_H

#define CONFIG_EDITOR_STACKSIZE     16

void config_editor_start(const rom void *callerfunc, const rom void *ptr);
void config_editor_editselected(void);
void config_editor_saveselected(void);
void config_editor_loadselected(void);
void config_editor_editstring(void);

void config_editor_set_current(void);
void config_editor(void);
void config_editor_val(void);
void config_editor_configselector(void);
void config_editor_stringeditor(void);

void config_show_name(unsigned char row);
void config_show_entry(unsigned char row);
void config_show_item(unsigned char row);
void config_show_value(unsigned char row);
void config_show_configname(unsigned char row);
void config_editor_show_editstring(void);

void config_namedselection(void);

#endif

