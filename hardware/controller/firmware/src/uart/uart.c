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

const rom unsigned short baudrates[11] =
{
    3332, //   2400 baud wanted,   2400.24 actual rate
    1666, //   4800 baud wanted,   4799.04 actual rate
    1110, //   7200 baud wanted,   7200.72 actual rate
     832, //   9600 baud wanted,   9603.84 actual rate
     555, //  14400 baud wanted,  14388.49 actual rate
     416, //  19200 baud wanted,  19184.65 actual rate
     277, //  28800 baud wanted,  28776.98 actual rate
     255, //  31250 baud wanted,  31250.00 actual rate
     207, //  38400 baud wanted,  38461.54 actual rate
     138, //  57600 baud wanted,  57553.96 actual rate
      68, // 115200 baud wanted, 115942.03 actual rate
};

rom const char *rom baudnames[] =
{
    "2400",
    "4800",
    "7200",
    "9600",
    "14400",
    "19200",
    "28800",
    "31520",
    "38400",
    "57600",
    "115200"
};

void uart_init(void)
{
    unsigned long delay;
    
    uart_fifo_init();

    BAUDCONbits.BRG16 = 0;
    uart_set_baudrate();
    
    for(delay = 0; delay < 20000; delay++)
    {
        _asm NOP _endasm
    }

    logger_print_version();
}

void uart_set_baudrate(void)
{
    static UShortType baudrate;

    if(BAUDCONbits.BRG16)
    {
        logger_print_module_msg_stringval(S_UART, S_SET_BAUDRATE, baudnames[main_config.baudrate]);
    }

    TXSTA = 0b00100100; // BRGH = 1
    RCSTA = 0b10010000;

    BAUDCONbits.BRG16 = 1;

    baudrate.ushort = baudrates[main_config.baudrate];

    SPBRG = baudrate.byte0;
    SPBRGH = baudrate.byte1;

    IPR1bits.RCIP = 0;
    PIR1bits.RCIF = 0;
    RCSTAbits.CREN = 0;
    RCSTAbits.CREN = 1;
    PIE1bits.RCIE = 1;
    IPR1bits.TXIP = 0;
    PIE1bits.TXIE = 0;
}

void uart_print_longnum(unsigned long num, unsigned char digits, unsigned char decimal)
{
    divmod_set_remainder(num);

    if (digits == 10)
    {
        goto TEN_DIGITS;
    }
    else if (digits == 9)
    {
        goto NINE_DIGITS;
    }
    else if (digits == 8)
    {
        goto EIGHT_DIGITS;
    }
    else if (digits == 7)
    {
        goto SEVEN_DIGITS;
    }
    else if (digits == 6)
    {
        goto SIX_DIGITS;
    }
    else if (digits == 5)
    {
        goto FIVE_DIGITS;
    }
    else if(digits == 4)
    {
        goto FOUR_DIGITS;
    }
    else if(digits == 3)
    {
        if(decimal == 3)
        {
            uart_fifo_putchar('0');
        }
        goto THREE_DIGITS;
    }
    else if(digits == 2)
    {
        if(decimal == 2)
        {
            uart_fifo_putchar('0');
        }
        goto TWO_DIGITS;
    }
    else if(digits == 1)
    {
        if(decimal == 1)
        {
            uart_fifo_putchar('0');
        }
        goto ONE_DIGIT;
    }

TEN_DIGITS:
    divmod_set_divider(1000000000);
    uart_fifo_putchar('0'+divmod());

NINE_DIGITS:
    divmod_set_divider(100000000);
    uart_fifo_putchar('0'+divmod());

EIGHT_DIGITS:
    divmod_set_divider(10000000);
    uart_fifo_putchar('0'+divmod());

SEVEN_DIGITS:
    divmod_set_divider(1000000);
    uart_fifo_putchar('0'+divmod());

SIX_DIGITS:
    divmod_set_divider(100000);
    uart_fifo_putchar('0'+divmod());

FIVE_DIGITS:
    divmod_set_divider(10000);
    uart_fifo_putchar('0'+divmod());

FOUR_DIGITS:
    divmod_set_divider(1000);
    uart_fifo_putchar('0'+divmod());

THREE_DIGITS:
    divmod_set_divider(100);
    if(decimal == 3)
    {
        uart_fifo_putchar('.');
    }
    uart_fifo_putchar('0'+divmod());

TWO_DIGITS:
    divmod_set_divider(10);
    if(decimal == 2)
    {
        uart_fifo_putchar('.');
    }
    uart_fifo_putchar('0'+divmod());

ONE_DIGIT:
    if(decimal == 1)
    {
        uart_fifo_putchar('.');
    }
    uart_fifo_putchar('0'+divmod_get_remainder());
}

void uart_print_seconds_as_time(unsigned short seconds)
{
    seconds_to_time(seconds);
    uart_print_longnum(time_data.hours, 3, 0);
    uart_fifo_putchar(':');
    uart_print_longnum(time_data.minutes, 2, 0);
    uart_fifo_putchar(':');
    uart_print_longnum(time_data.seconds, 2, 0);
}
