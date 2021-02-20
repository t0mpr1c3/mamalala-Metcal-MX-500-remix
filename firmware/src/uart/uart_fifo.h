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

#ifndef UART_FIFO_H
#define UART_FIFO_H

#define FIFO_SIZE	128

extern unsigned char rx_fifo[FIFO_SIZE];
extern unsigned char tx_fifo[FIFO_SIZE];

extern volatile near unsigned char rx_fifo_write_pos;
extern volatile near unsigned char rx_fifo_read_pos;
extern volatile near unsigned char rx_fifo_fill;

extern volatile near unsigned char tx_fifo_write_pos;
extern volatile near unsigned char tx_fifo_read_pos;
extern volatile near unsigned char tx_fifo_fill;

void uart_fifo_init(void);
void uart_fifo_putchar(unsigned char c);
void uart_fifo_put_ramstring(char *str);
void uart_fifo_put_romstring(const rom char *str);
unsigned char uart_fifo_getchar(void);
unsigned char uart_fifo_num_rx_bytes(void);
unsigned char uart_fifo_get_rx_buffer(unsigned char *buffer, unsigned char bytes_wanted);
void uart_fifo_put_tx_buffer(unsigned char *buffer, unsigned char num_bytes);

#endif

