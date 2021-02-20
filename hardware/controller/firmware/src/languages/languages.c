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

rom char *rom *current_strings;
rom char *rom *current_menu_strings;
rom char *rom *current_config_strings;

static unsigned char current_lang;

void languages_init(void)
{
	current_lang = 0xFF;
	languages_set_lang(main_config.language);
}

void languages_reload(void)
{
	languages_set_lang(main_config.language);
}


void languages_set_lang(unsigned char lang_id)
{
    if(lang_id == current_lang)
    {
        return;
    }
    
    if(lang_id < NUM_LANGUAGES)
    {
        current_strings = (rom char *rom *)language_entries[lang_id].data;
        current_lang = lang_id;
        main_config.language = lang_id;
        logger_print_module_msg_val(S_LANGUAGE_MANAGER, S_SELECT_LANGUAGE, S_LANGUAGE_NAME);
    }
    else
    {
        uart_print_romstring("Languages: Invalid language selected");
    }
}

unsigned char languages_get_lang(void)
{
    return current_lang;
}