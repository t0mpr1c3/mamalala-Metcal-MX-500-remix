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

#pragma udata uart_fifo_data = 0x0100
unsigned char rx_fifo[FIFO_SIZE];
unsigned char tx_fifo[FIFO_SIZE];

#pragma udata access _FIFO_DATA
volatile near unsigned char rx_fifo_write_pos;
volatile near unsigned char rx_fifo_read_pos;
volatile near unsigned char rx_fifo_fill;

volatile near unsigned char tx_fifo_write_pos;
volatile near unsigned char tx_fifo_read_pos;
volatile near unsigned char tx_fifo_fill;
#pragma udata

static unsigned char cnt;
#pragma udata

void uart_fifo_init(void)
{
    for(cnt = 0; cnt < FIFO_SIZE; cnt++)
    {
        rx_fifo[cnt] = 0x00;
        tx_fifo[cnt] = 0x00;
    }

    rx_fifo_write_pos = 0;
    rx_fifo_read_pos = 0;
    rx_fifo_fill = 0;

    tx_fifo_write_pos = 0;
    tx_fifo_read_pos = 0;
    tx_fifo_fill = 0;

}

void uart_fifo_putchar(unsigned char c)
{
    while(tx_fifo_fill == FIFO_SIZE)
    {
        _asm NOP _endasm
    }

    tx_fifo[tx_fifo_write_pos++] = c;
    tx_fifo_write_pos &= (FIFO_SIZE-1);
    tx_fifo_fill++;

    PIE1bits.TXIE = 1;
}

void uart_fifo_put_ramstring(char *str)
{
    while(*str)
    {
        while(tx_fifo_fill == FIFO_SIZE)
        {
            _asm NOP _endasm
        }

        tx_fifo[tx_fifo_write_pos++] = *str++;
        tx_fifo_write_pos &= (FIFO_SIZE-1);
        tx_fifo_fill++;

        PIE1bits.TXIE = 1;
    }
}

void uart_fifo_put_romstring(const rom char *str)
{
    while(*str)
    {
        while(tx_fifo_fill == FIFO_SIZE)
        {
            _asm NOP _endasm
        }

        tx_fifo[tx_fifo_write_pos++] = *str++;
        tx_fifo_write_pos &= (FIFO_SIZE-1);
        tx_fifo_fill++;

        PIE1bits.TXIE = 1;
    }
}

unsigned char uart_fifo_getchar(void)
{
    static unsigned char rxbyte;

    if(rx_fifo_fill = 0) { return 0; }

    rxbyte = rx_fifo[rx_fifo_read_pos++];
    rx_fifo_read_pos &= (FIFO_SIZE-1);
    rx_fifo_fill--;

    return rxbyte;
}

unsigned char uart_fifo_num_rx_bytes(void)
{
    return rx_fifo_fill;
}

unsigned char uart_fifo_get_rx_buffer(unsigned char *buffer, unsigned char bytes_wanted)
{
    static unsigned char num_bytes;
    static unsigned char read_num_bytes;

    num_bytes = uart_fifo_num_rx_bytes();

    if(num_bytes >= bytes_wanted)
    {
        for(cnt = 0; cnt < bytes_wanted; cnt++)
        {
            buffer[cnt] = uart_fifo_getchar();
        }
        return bytes_wanted;
    }
    else
    {
        for(cnt = 0; cnt < num_bytes; cnt++)
        {
            buffer[cnt] = uart_fifo_getchar();
        }
        return num_bytes;
    }
}

void uart_fifo_put_tx_buffer(unsigned char *buffer, unsigned char num_bytes)
{
    for(cnt = 0; cnt < num_bytes; cnt++)
    {
        while(tx_fifo_fill == FIFO_SIZE)
        {
            _asm NOP _endasm
        }

        tx_fifo[tx_fifo_write_pos++] = *buffer++;
        tx_fifo_write_pos &= (FIFO_SIZE-1);
        tx_fifo_fill++;

        PIE1bits.TXIE = 1;
    }
}

