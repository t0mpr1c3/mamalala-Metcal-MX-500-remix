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

rom const unsigned char rom powerinfoicons[4][8] =
{
    {   // off
        0b00011111,
        0b00011011,
        0b00010001,
        0b00010101,
        0b00010001,
        0b00011011,
        0b00011111,
        0b00000000
    },

    {   // normal power
        0b00011111,
        0b00001110,
        0b00000100,
        0b00011111,
        0b00000100,
        0b00001110,
        0b00011111,
        0b00000000
    },

    {   // boost power
        0b00000100,
        0b00001110,
        0b00011111,
        0b00000000,
        0b00000100,
        0b00001110,
        0b00011111,
        0b00000000
    },

    {   // limit power
        0b00011111,
        0b00001110,
        0b00000100,
        0b00000000,
        0b00011111,
        0b00001110,
        0b00000100,
        0b00000000
    }
};

rom const unsigned char rom tickerbar[10] =
{
    0b00000000,
    0b00010000,
    0b00011000,
    0b00011100,
    0b00011110,
    0b00011111,
    0b00001111,
    0b00000111,
    0b00000011,
    0b00000001
};
