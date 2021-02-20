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

#include "strings_EN"
#include "strings_DE"

rom const struct LANGUAGE_ENTRY rom language_entries[] =
{
	{ (rom const void*)strings_EN },
	{ (rom const void*)strings_DE }
};
