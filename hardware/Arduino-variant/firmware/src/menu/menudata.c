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

const rom MenuEntry rom main_menu_entries[] =
{
    { ENTRY_CONFIGFUNC,     (const rom void*)&main_config_data,             MS_MAIN_CONFIG },
    { ENTRY_CONFIGFUNC,     (const rom void*)&pm_editconfig_data,           MS_EDIT_SETTINGS },
    { ENTRY_CONFIGFUNC,     (const rom void*)&pm_saveconfig_data,           MS_SAVE_SETTINGS },
    { ENTRY_CONFIGFUNC,     (const rom void*)&pm_loadconfig_data,           MS_LOAD_SETTINGS },
    { ENTRY_FUNCTION,       (const rom void*)&infodisplay_show_version,     MS_SHOW_VERSIONINFO },
    { ENTRY_FUNCTION,       (const rom void*)&reset_pic,                    MS_RESET },
};

const rom Menu main_menu =
{
    menusize(main_menu_entries), main_menu_entries, MS_MAINMENU, 0, 0
};
