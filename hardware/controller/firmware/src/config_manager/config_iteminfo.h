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

#ifndef CONFIG_ITEMINFO_H
#define CONFIG_ITEMINFO_H

#define CONFIG_ITEMS                         0
#define CONFIG_ITEMS_SAVEABLE                1
#define CONFIG_NAMEDSELECTION                2
#define CONFIG_NAMEDSELECTION_UPDATE         3
#define CONFIG_NAMEDSELECTION_ENUM           4
#define CONFIG_NAMEDSELECTION_MASKED         5
#define CONFIG_NAMEDSELECTION_ENUM_UPDATE    6
#define CONFIG_NAMEDRADIOSELECTION           7
#define CONFIG_NAMEDRADIOSELECTION_UPDATE    8
#define CONFIG_STARTUP_SETTINGS              9
#define CONFIG_FUNCTIONSELECTION            10
#define CONFIG_SELECTABLECONFIG             11
#define CONFIG_VALUE_ITEM                   12
#define CONFIG_STRING                       13
#define CONFIG_UCHAR                        14
#define CONFIG_UCHAR_1D                     15
#define CONFIG_UCHAR_2D                     16
#define CONFIG_USHORT                       17
#define CONFIG_USHORT_1D                    18
#define CONFIG_USHORT_2D                    19
#define CONFIG_TIME                         20

typedef struct ValueItemDef
{
    rom const unsigned char         nameID;
    rom const unsigned char         type;
    rom const unsigned short        min;
    rom const unsigned short        max;
    void                            *var;
} ValueItem;

typedef struct NamedSelectionEnumDef
{
    rom const unsigned char         nameID;
} NamedSelectionEnum;

typedef struct NamedSelectionMaskedDef
{
    rom const unsigned char         nameID;
    rom const unsigned char         value;
    rom const unsigned char         mask;
} NamedSelectionMasked;

typedef struct NamedSelectionDef
{
    rom const unsigned char         nameID;
    rom const unsigned char         value;
} NamedSelection;

typedef struct ConfigDataDef
{
    rom const unsigned char         type;
    rom const unsigned char         nameID;
    rom const unsigned char         numItems;
    rom const void                  *items;
    void                            *var;
    rom const unsigned char         mask;
    rom const voidfunc              onExit;
} ConfigData;

#define numentries(_X_, _Y_) (sizeof(_X_) / sizeof(_Y_))

extern rom const ConfigData main_config_data;

extern rom const ConfigData pm_editconfig_data;
extern rom const ConfigData pm_saveconfig_data;
extern rom const ConfigData pm_loadconfig_data;

#endif

