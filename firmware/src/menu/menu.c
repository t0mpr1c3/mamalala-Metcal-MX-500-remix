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

static const rom Menu *menu_stack[MENU_STACKSIZE];
static unsigned char menu_selection_stack[MENU_STACKSIZE];
static unsigned char menu_stackindex;

static const rom Menu *current_menu;
static unsigned char current_menu_entry;

static voidfunc menufunc;
static voidfunc menu_caller;

void menu_start(const rom void *callerfunc)
{
    menu_stackindex = 0;

    if(callerfunc)
    {
        menu_caller = (voidfunc)callerfunc;
    }
    else
    {
        menu_caller = empty_callback;
    }

    current_menu = &main_menu;
    current_menu->prev_menu = 0;
    current_menu_entry = 0;

    menu_return();
}

void menu_return(void)
{
    menu_show_name(0);
    menu_show_entry(1);
    set_ui_func(menu_exec);
}

void menu_exit(void)
{
    if(current_menu->prev_menu)
    {
        current_menu_entry  = current_menu->prev_entry-1;
        current_menu        = current_menu->prev_menu;
        menu_show_name(0);
        menu_show_entry(1);
    }
}

void menu_show_name(unsigned char row)
{
    lcd_write_line_at(0, row, tr(current_menu->nameID));
}

void menu_show_entry(unsigned char row)
{
    lcd_write_line_at(0, row, tr(current_menu->entry[current_menu_entry].nameID));
}

void menu_exec(void)
{
    if(encoder_get_button() == BUTTON_LONGPUSH)
    {
        set_ui_func(menu_caller);
        return;
    }

    if(encoder_get_button() == BUTTON_CLICKED)
    {
        encoder_clear_button();

        switch(current_menu->entry[current_menu_entry].type)
        {
            case ENTRY_FUNCTION:
                menu_show_entry(0);
                ((voidfunc)(current_menu->entry[current_menu_entry].data))();
                break;
            case ENTRY_CONFIGFUNC:
                config_editor_start((const rom void*)&menu_return, current_menu->entry[current_menu_entry].data);
                break;
            case ENTRY_MENU:
            case ENTRY_SETUP_MENU:
                current_menu = (rom const Menu*)current_menu->entry[current_menu_entry].data;
                current_menu_entry = 0;
                menu_show_name(0);
                menu_show_entry(1);
                break;
            default:
                break;
        }
    }

    if(encoder_get() > 0)
    {
        encoder_reset();
        current_menu_entry++;
        if(current_menu_entry >= current_menu->num_entries)
        {
            current_menu_entry = 0;
        }
        menu_show_name(0);
        menu_show_entry(1);
    }

    if(encoder_get() < 0)
    {
        encoder_reset();
        current_menu_entry--;
        if(current_menu_entry == 255)
        {
            current_menu_entry = current_menu->num_entries-1;
        }
        menu_show_name(0);
        menu_show_entry(1);
    }
}
