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

#ifndef MENUDATA_H
#define MENUDATA_H

#define ENTRY_NOP               0
#define ENTRY_FUNCTION          1
#define ENTRY_CONFIGFUNC        2
#define ENTRY_MENU              3
#define ENTRY_SETUP_MENU        4

typedef void(*func)(void);
typedef void(*voidptrfunc)(rom const void *ptr);

typedef struct MenuEntryStruct
{
    rom unsigned char       type;
    rom const void          *data;
    rom const unsigned char nameID;
} MenuEntry;

typedef struct MenuStruct
{
    rom const unsigned char                 num_entries;
    rom const struct MenuEntryStruct rom    *entry;
    rom const unsigned char                 nameID;
    rom const struct MenuStruct rom         *prev_menu;
    rom const unsigned char                 prev_entry;
} Menu;

extern const rom MenuEntry rom main_menu_entries[];
extern rom const Menu main_menu;

#define menusize(_X_) (sizeof(_X_) / sizeof(MenuEntry))

#endif
