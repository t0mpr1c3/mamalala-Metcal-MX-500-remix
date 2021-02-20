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

static voidfunc config_editor_callback;

static const rom ConfigData         *config_stack[CONFIG_EDITOR_STACKSIZE];
static unsigned char                config_selection_stack[CONFIG_EDITOR_STACKSIZE];
static unsigned char                config_stackindex;

static const rom ConfigData         *config_data;
static const rom ConfigData         *config_items;
static const rom NamedSelection     *config_named_selection;
static const rom NamedSelectionEnum *config_named_selection_enum;
static const rom ValueItem          *config_value_item;
static unsigned short                config_selection;

static unsigned char *uchar_var;
static unsigned char dummychar;

static unsigned short *ushort_var;
static unsigned short dummyshort;

static signed short cur_encoder;
static unsigned char cur_encoder_button;

static signed long entry_val;

static unsigned char stringedit_state;
static unsigned char stringedit_pos;
static unsigned char stringedit_string[32];

static voidfunc config_editor_callback;
static voidfunc config_editor_caller;

void config_editor_start(const rom void *callerfunc, const rom void *ptr)
{
    config_stackindex = 0;

    config_data = (const rom ConfigData*) ptr;

    config_selection = 0;

    config_editor_set_current();
    
    config_show_name(0);

    if(callerfunc)
    {
        config_editor_caller = (voidfunc)callerfunc;
    }
    else
    {
        config_editor_caller = empty_callback;
    }

    if(config_data->onExit)
    {
        config_editor_callback = config_data->onExit;
    }
    else
    {
        config_editor_callback = empty_callback;
    }

    switch(config_data->type)
    {
        case CONFIG_SELECTABLECONFIG:
            set_ui_func(config_editor_configselector);
            config_selection = NUM_CONFIGS;
            config_show_configname(1);
            break;
            
        default:
            config_show_entry(1);
            set_ui_func(config_editor);
            break;
    }
}

void config_editor_editselected(void)
{
    if(config_selection == NUM_CONFIGS+1)
    {
        config_memory_default_config(9);
    }
    else if(config_selection == NUM_CONFIGS)
    {
        config_memory_swap(CONFIG_ACTIVE_TO_EDIT);
    }
    else if(config_selection < NUM_CONFIGS)
    {
        config_memory_load_config(config_selection);
    }

    set_ui_func(config_editor);
    config_selection = 0;

    config_show_name(0);
    config_show_entry(1);
    config_editor_callback = empty_callback;
}

void config_editor_saveselected(void)
{
    if(config_selection == NUM_CONFIGS)
    {
        config_memory_swap(CONFIG_EDIT_TO_ACTIVE);
        power_manager_reset();
    }
    else if(config_selection < NUM_CONFIGS)
    {
        config_memory_save_config(config_selection);
    }
    set_ui_func(config_editor_caller);
}

void config_editor_loadselected(void)
{
    if(config_selection == NUM_CONFIGS)
    {
        config_memory_swap(CONFIG_EDIT_TO_ACTIVE);
        power_manager_reset();
    }
    else if(config_selection < NUM_CONFIGS)
    {
        config_manager_load_config(config_selection);
        power_manager_reset();
    }
    set_ui_func(config_editor_caller);
}

void config_editor_editstring(void)
{
    stringedit_state = 0;
    uchar_var = (unsigned char*)config_data->var;
    
    for(stringedit_pos = 0; stringedit_pos < config_data->numItems; stringedit_pos++)
    {
        stringedit_string[stringedit_pos] = uchar_var[stringedit_pos];
    }

    while(stringedit_pos <= 32)
    {
        stringedit_string[stringedit_pos];
        stringedit_pos++;
    }

    stringedit_pos = 0;
    config_selection = 0;

    config_editor_show_editstring();

    set_ui_func(config_editor_stringeditor);
}

void config_editor_show_editstring(void)
{
    lcd_write_line_ram_at(0, 0, (char*)&stringedit_string);
    switch(stringedit_state)
    {
        case 0:
            lcd_write_line_at(stringedit_pos, 1, "-");
            break;
            
        case 1:
            lcd_write_line_at(stringedit_pos, 1, "^");
            break;
    }
}

void config_editor_set_current(void)
{
    static unsigned char tmpvar;
    
    switch(config_data->type)
    {
        case CONFIG_ITEMS:
        case CONFIG_ITEMS_SAVEABLE:
        case CONFIG_SELECTABLECONFIG:
            config_items = (const rom ConfigData*) config_data->items;
            break;

        case CONFIG_NAMEDSELECTION:
        case CONFIG_NAMEDSELECTION_UPDATE:
        case CONFIG_NAMEDRADIOSELECTION:
        case CONFIG_NAMEDRADIOSELECTION_UPDATE:
        case CONFIG_NAMEDSELECTION_MASKED:
            config_named_selection = (const rom NamedSelection*) config_data->items;
            break;

        case CONFIG_NAMEDSELECTION_ENUM:
        case CONFIG_NAMEDSELECTION_ENUM_UPDATE:
            config_named_selection_enum = (const rom NamedSelectionEnum*) config_data->items;
            break;

        case CONFIG_VALUE_ITEM:
            config_value_item = (const rom ValueItem*) config_data->items;
            break;

        case CONFIG_STRING:
            config_editor_editstring();
            return;
            break;

        default:
            break;

    }
    
    if(config_data->var)
    {
        uchar_var = (unsigned char*)config_data->var;
        config_selection = 0;
        
        switch(config_data->type)
        {
            case CONFIG_NAMEDSELECTION:
            case CONFIG_NAMEDSELECTION_UPDATE:
                for(config_selection = 0; config_selection < 255; config_selection++)
                {
                    if(config_named_selection[config_selection].value == *uchar_var)
                        goto FOUND_VAR;
                }
                config_selection = 0;
                break;

            case CONFIG_NAMEDSELECTION_MASKED:
                tmpvar = *uchar_var;
                tmpvar &= config_data->mask;
                for(config_selection = 0; config_selection < config_data->numItems; config_selection++)
                {
                    if(config_named_selection[config_selection].value == tmpvar)
                        goto FOUND_VAR;
                }
                config_selection = 0;
                break;

            case CONFIG_NAMEDSELECTION_ENUM:
            case CONFIG_NAMEDSELECTION_ENUM_UPDATE:
            case CONFIG_STARTUP_SETTINGS:
                config_selection = *uchar_var;
                break;
        }
    }
    else
    {
        uchar_var = &dummychar;
        config_selection = 0;
    }

FOUND_VAR:
    switch(config_data->type)
    {
        case CONFIG_SELECTABLECONFIG:
            break;

        default:
            if(config_data->onExit)
            {
                config_editor_callback = config_data->onExit;
            }
            else
            {
                config_editor_callback = empty_callback;
            }
            break;
    }

}

void config_editor_push(void)
{
    if(config_stackindex < CONFIG_EDITOR_STACKSIZE)
    {
        config_stack[config_stackindex] = config_data;
        config_selection_stack[config_stackindex] = config_selection;

        config_stackindex++;

        config_data = (const rom ConfigData*) config_items+config_selection;

        config_editor_set_current();

        config_show_name(0);
        config_show_entry(1);
    }
}

void config_editor_pop(void)
{
    if(config_stackindex)
    {
        config_stackindex--;

        config_data = config_stack[config_stackindex];
        config_editor_set_current();
        config_selection = config_selection_stack[config_stackindex];
        
        config_show_name(0);
        config_show_entry(1);
    }
    else
    {
        set_ui_func(config_editor_caller);
    }
}

void config_editor_exit(void)
{
    config_editor_callback();
    config_editor_pop();
}

void config_editor_update_var(void)
{
    static unsigned char tmpvar;
    
    switch(config_data->type)
    {
        case CONFIG_NAMEDSELECTION:
        case CONFIG_NAMEDSELECTION_UPDATE:
            *uchar_var = config_named_selection[config_selection].value;
            config_editor_callback();
            break;

        case CONFIG_NAMEDSELECTION_MASKED:
            tmpvar = *uchar_var;
            tmpvar &= ~config_data->mask;
            *uchar_var = (tmpvar | config_named_selection[config_selection].value);
            config_editor_callback();
            break;

        case CONFIG_NAMEDSELECTION_ENUM:
        case CONFIG_NAMEDSELECTION_ENUM_UPDATE:
            *uchar_var = config_selection;
            config_editor_callback();
            break;
            
        case CONFIG_NAMEDRADIOSELECTION:
        case CONFIG_NAMEDRADIOSELECTION_UPDATE:
            if(cur_encoder == 0)
            {
                *uchar_var ^= config_named_selection[config_selection].value;
                config_editor_callback();
            }
            break;

        case CONFIG_STARTUP_SETTINGS:
            *uchar_var = config_selection;
            break;
    }

    config_show_name(0);
    config_show_entry(1);
}

void config_editor_set_current_valitem(void)
{
    if(config_value_item[config_selection].var)
    {
        switch(config_value_item[config_selection].type)
        {
            case CONFIG_UCHAR:
            case CONFIG_UCHAR_1D:
            case CONFIG_UCHAR_2D:
                uchar_var = (unsigned char*)config_value_item[config_selection].var;
                entry_val = *uchar_var;
                break;

            case CONFIG_USHORT:
            case CONFIG_USHORT_1D:
            case CONFIG_USHORT_2D:
            case CONFIG_TIME:
                ushort_var = (unsigned short*)config_value_item[config_selection].var;
                entry_val = *ushort_var;
                break;
        }
    }
    else
    {
        uchar_var = &dummychar;
        ushort_var = &dummyshort;
    }
}

void config_editor(void)
{
    cur_encoder = encoder_get();
    cur_encoder_button = encoder_get_button();
    if(cur_encoder_button != BUTTON_IDLE)
    {
        encoder_clear_button();
    }
    encoder_reset();

    switch(cur_encoder_button)
    {
        case BUTTON_LONGPUSH:
            config_editor_exit();
            break;
        
        case BUTTON_CLICKPUSH:
            config_editor_pop();
            break;

        case BUTTON_CLICKED:
            switch(config_data->type)
            {
                case CONFIG_ITEMS:
                case CONFIG_ITEMS_SAVEABLE:
                case CONFIG_SELECTABLECONFIG:
                    config_editor_push();
                    break;
                    
                case CONFIG_NAMEDSELECTION:
                case CONFIG_NAMEDSELECTION_UPDATE:
                case CONFIG_NAMEDSELECTION_ENUM:
                case CONFIG_NAMEDSELECTION_ENUM_UPDATE:
                case CONFIG_STARTUP_SETTINGS:
                case CONFIG_NAMEDSELECTION_MASKED:
                    config_editor_update_var();
                    config_editor_exit();
                    break;

                case CONFIG_NAMEDRADIOSELECTION:
                case CONFIG_NAMEDRADIOSELECTION_UPDATE:
                    config_editor_update_var();
                    break;

                case CONFIG_VALUE_ITEM:
                    config_show_entry(0);
                    config_editor_set_current_valitem();
                    config_show_value(1);
                    set_ui_func(config_editor_val);
                    break;
            }
            break;
    }
    
    if(cur_encoder > 0)
    {
        config_selection++;
        if(config_selection >= config_data->numItems)
        {
            config_selection = 0;
        }
        config_editor_update_var();
    }
    else if(cur_encoder < 0)
    {
        config_selection--;
        if(config_selection >= config_data->numItems)
        {
            config_selection = config_data->numItems-1;
        }
        config_editor_update_var();
    }
}

void config_editor_val(void)
{
    cur_encoder = encoder_get();
    cur_encoder_button = encoder_get_button();
    if(cur_encoder_button != BUTTON_IDLE)
    {
        encoder_clear_button();
    }
    encoder_reset();

    switch(cur_encoder_button)
    {
        case BUTTON_LONGPUSH:
            config_show_name(0);
            config_show_entry(1);
            set_ui_func(config_editor);
            break;
            
        case BUTTON_CLICKED:
            switch(config_value_item[config_selection].type)
            {
                case CONFIG_UCHAR:
                case CONFIG_UCHAR_1D:
                case CONFIG_UCHAR_2D:
                    *uchar_var = entry_val;
                    break;

                case CONFIG_USHORT:
                case CONFIG_USHORT_1D:
                case CONFIG_USHORT_2D:
                case CONFIG_TIME:
                    *ushort_var = entry_val;
                    break;
            }
            config_show_name(0);
            config_show_entry(1);
            set_ui_func(config_editor);
            break;
    }



    if(cur_encoder != 0)
    {
        entry_val += cur_encoder;
        if(entry_val < config_value_item[config_selection].min)
        {
            entry_val = config_value_item[config_selection].min;
        }
        else if(entry_val > config_value_item[config_selection].max)
        {
            entry_val = config_value_item[config_selection].max;
        }

        config_show_value(1);
    }
}

void config_editor_configselector(void)
{
    cur_encoder = encoder_get();
    cur_encoder_button = encoder_get_button();
    if(cur_encoder_button != BUTTON_IDLE)
    {
        encoder_clear_button();
    }
    encoder_reset();

    switch(cur_encoder_button)
    {
        case BUTTON_LONGPUSH:
            config_editor_pop();
            break;

        case BUTTON_CLICKPUSH:
            config_selection = 0xFFFF;
            config_editor_callback();
            break;

        case BUTTON_CLICKED:
            config_editor_callback();
            break;
    }

    if(cur_encoder > 0)
    {
        config_selection++;
        if(config_data->mask == 0)
        {
            if(config_selection > NUM_CONFIGS+1)
            {
                config_selection = 0;
            }
        }
        else
        {
            if(config_selection > NUM_CONFIGS)
            {
                config_selection = 0;
            }
        }
        config_show_configname(1);
    }
    else if(cur_encoder < 0)
    {
        config_selection--;
        if(config_data->mask == 0)
        {
            if(config_selection > NUM_CONFIGS+1)
            {
                config_selection = NUM_CONFIGS+1;
            }
        }
        else
        {
            if(config_selection > NUM_CONFIGS)
            {
                config_selection = NUM_CONFIGS;
            }
        }
        config_show_configname(1);
    }
}






void config_editor_stringeditor(void)
{
    cur_encoder = encoder_get();
    cur_encoder_button = encoder_get_button();
    if(cur_encoder_button != BUTTON_IDLE)
    {
        encoder_clear_button();
    }
    encoder_reset();

    switch(cur_encoder_button)
    {
        case BUTTON_LONGPUSH:
            set_ui_func(config_editor);
            config_editor_pop();
            break;

        case BUTTON_CLICKPUSH:
            for(stringedit_pos = 0; stringedit_pos < config_data->numItems; stringedit_pos++)
            {
                uchar_var[stringedit_pos] = stringedit_string[stringedit_pos];
            }
            set_ui_func(config_editor);
            config_editor_pop();
            break;

        case BUTTON_CLICKED:
            stringedit_state ^= 0x01;
            if(stringedit_state & 0x01)
            {
                config_selection = stringedit_string[stringedit_pos];
            }
            config_editor_show_editstring();
            break;
    }



    if(cur_encoder > 0)
    {
        switch(stringedit_state)
        {
            case 0:
                stringedit_pos++;
                if(stringedit_pos >= config_data->numItems)
                {
                    stringedit_pos = 0;
                }
                break;

            case 1:
                config_selection += cur_encoder;
                config_selection &= 0x7F;
                if(config_selection < 32)
                {
                    config_selection = 32;
                }
                stringedit_string[stringedit_pos] = config_selection;
                break;
        }
        config_editor_show_editstring();
    }
    else if(cur_encoder < 0)
    {
        switch(stringedit_state)
        {
            case 0:
                stringedit_pos--;
                if(stringedit_pos >= config_data->numItems)
                {
                    stringedit_pos = config_data->numItems-1;
                }
                break;

            case 1:
                config_selection += cur_encoder;
                config_selection &= 0x7F;
                if(config_selection < 32)
                {
                    config_selection = 127;
                }
                stringedit_string[stringedit_pos] = config_selection;
                break;
        }
        config_editor_show_editstring();
    }
}


void config_show_name(unsigned char row)
{
    switch(config_data->type)
    {
        case CONFIG_STRING:
            return;
            break;
            
        default:
            lcd_write_line_at(0, row, tr(config_data->nameID));
            break;
    }
}

void config_show_entry(unsigned char row)
{
    switch(config_data->type)
    {
        case CONFIG_ITEMS:
        case CONFIG_SELECTABLECONFIG:
            lcd_write_line_at(0, row, tr(config_items[config_selection].nameID));
            break;

        case CONFIG_NAMEDSELECTION:
        case CONFIG_NAMEDSELECTION_UPDATE:
        case CONFIG_NAMEDSELECTION_MASKED:
            lcd_write_line_at(0, row, tr(config_named_selection[config_selection].nameID));
            break;

        case CONFIG_NAMEDRADIOSELECTION:
        case CONFIG_NAMEDRADIOSELECTION_UPDATE:
            lcd_write_line_at(1, row, tr(config_named_selection[config_selection].nameID));
            if(config_named_selection[config_selection].value & *uchar_var)
            {
                 lcd_write_char_at(0, row, '*');
            }
            break;

        case CONFIG_NAMEDSELECTION_ENUM:
        case CONFIG_NAMEDSELECTION_ENUM_UPDATE:
            lcd_write_line_at(0, row, tr(config_named_selection_enum[config_selection].nameID));
            break;

        case CONFIG_STARTUP_SETTINGS:
            lcd_write_line_ram_at(0, row, config_memory_get_name(config_selection));
            break;

        case CONFIG_VALUE_ITEM:
            lcd_write_line_at(0, row, tr(config_value_item[config_selection].nameID));
            break;

    }
}

void config_show_configname(unsigned char row)
{
    if(config_selection == NUM_CONFIGS+1)
    {
        lcd_write_line_at(0, row, tr(CS_DEFAULT_CONFIG));
        lcd_write_string_at(14, 0, "  ");
    }
    else if(config_selection == NUM_CONFIGS)
    {
        if(config_data->mask == 0)
        {
            lcd_write_line_at(0, row, tr(CS_CURRENT_CONFIG));
        }
        else if(config_data->mask == 1)
        {
            lcd_write_line_at(0, row, tr(CS_TO_CURRENT_CONFIG));
        }
        else if(config_data->mask == 2)
        {
            lcd_write_line_at(0, row, tr(CS_FROM_EDIT_CONFIG));
        }
        lcd_write_string_at(14, 0, "  ");
    }
    else
    {
        lcd_write_line_ram_at(0, row, config_memory_get_name(config_selection));
        lcd_write_char_at(14, 0, '#');
        lcd_write_char_at(15, 0, '0'+config_selection);
    }
}

void config_show_value(unsigned char row)
{
    switch(config_value_item[config_selection].type)
    {
        case CONFIG_UCHAR:
            lcd_write_longnum_line(0, row, 3, 0, 0, entry_val);
            break;

        case CONFIG_UCHAR_1D:
            lcd_write_longnum_line(0, row, 3, 1, 0, entry_val);
            break;

        case CONFIG_UCHAR_2D:
            lcd_write_longnum_line(0, row, 3, 2, 0, entry_val);
            break;

        case CONFIG_USHORT:
            lcd_write_longnum_line(0, row, 5, 0, 0, entry_val);
            break;

        case CONFIG_USHORT_1D:
            lcd_write_longnum_line(0, row, 5, 1, 0, entry_val);
            break;

        case CONFIG_USHORT_2D:
            lcd_write_longnum_line(0, row, 5, 2, 0, entry_val);
            break;

        case CONFIG_TIME:
            lcd_write_time_line(0, row, entry_val);
            break;
    }
}
