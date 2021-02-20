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

#ifndef LOGGER_H
#define LOGGER_H

#define LOG_VERSION     0b00000001
#define LOG_STARTUPS    0b00000010
#define LOG_MODULES     0b00000100
#define LOG_PARAMETERS  0b00001000
#define LOG_TIME        0b00010000
#define LOG_NEWLINE     0b00100000

void logger_init(void);
void logger_set_config(void);
void logger_print_version(void);

void logger_print_start_msg(unsigned short stringnum);
void logger_print_module_msg(unsigned short mod_stringnum, unsigned short msg_stringnum);
void logger_print_module_msg_val(unsigned short mod_stringnum, unsigned short msg_stringnum, unsigned short val_stringnum);
void logger_print_module_msg_stringval(unsigned short mod_stringnum, unsigned short msg_stringnum, const rom char *val_str);
void logger_print_module_msg_ramval(unsigned short mod_stringnum, unsigned short msg_stringnum, char *val_str);
void logger_print_timed_change_msg(unsigned short mod_stringnum, unsigned short msg_stringnum, unsigned short state_stringnum, unsigned long secs);
void logger_print_elapsed_seconds(unsigned long seconds);
void logger_print_header(void);
void logger_print_params(void);

#endif

