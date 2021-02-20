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

#ifndef UART_H
#define UART_H


#define BAUD_2400        0
#define BAUD_4800        1
#define BAUD_7200        2
#define BAUD_9600        3
#define BAUD_14400       4
#define BAUD_19200       5
#define BAUD_28800       6
#define BAUD_31520       7
#define BAUD_38400       8
#define BAUD_57600       9
#define BAUD_115200     10

#define uart_print_romstring(_X_) uart_fifo_put_romstring(_X_)
#define uart_print_ramstring(_X_) uart_fifo_put_ramstring(_X_)

void uart_init(void);
void uart_set_baudrate(void);

/*
void uart_print_romstring(const rom char *str);
void uart_print_ramstring(char *str);
*/

void uart_print_longnum(unsigned long num, unsigned char digits, unsigned char decimal);
void uart_print_seconds_as_time(unsigned short seconds);

#endif

