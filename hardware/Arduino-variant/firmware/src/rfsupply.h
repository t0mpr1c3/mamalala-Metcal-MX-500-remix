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

#ifndef RFSUPPLY_H
#define RFSUPPLY_H

typedef void(*voidfunc)(void);

extern voidfunc uifunc;
void default_ui_func(void);
void main_return_func(void);

// compiler provided includes
#include <p18cxxx.h>

// project specific includes
#include "version.h"
#include "hardware.h"
#include "pindef.h"
#include "helpers.h"
#include "logger.h"
#include "crc.h"
#include "interrupt.h"
#include "uart_fifo.h"
#include "uart.h"
#include "languages.h"
#include "languages_strings.h"
#include "eeprom.h"
#include "config_manager.h"
#include "config_memory.h"
#include "config_editor.h"
#include "config_iteminfo.h"
#include "menu.h"
#include "menudata.h"
#include "lcd.h"
#include "infodisplay.h"
#include "infoicons.h"
#include "backlight.h"
#include "encoder.h"
#include "tip_detect.h"
#include "adc.h"
#include "rf_manager.h"
#include "power_manager.h"
#include "time.h"

#endif

