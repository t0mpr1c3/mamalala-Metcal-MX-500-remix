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

#pragma udata access _TIME_DATA
near static unsigned short ticker_cnt;
near static unsigned long mticks;
near static unsigned long old_mticks;
#pragma udata

void time_init(void)
{
    ticker_cnt = 0;
    mticks = 0;
    old_mticks = 0;

    IPR1bits.TMR1IP = 1;
    PIR1bits.TMR1IF = 0;
    T1CON = 0b00110000;
    PIE1bits.TMR1IE = 1;
    T1CONbits.TMR1ON = 1;

}

void time_reset_ticks(void)
{
    PIE1bits.TMR1IE = 0;
    mticks = 0;
    old_mticks = 0;
    PIE1bits.TMR1IE = 1;
}

unsigned long time_get_seconds(void)
{
    unsigned long ret_seconds;

    PIE1bits.TMR1IE = 0;

    ret_seconds = mticks;

    PIE1bits.TMR1IE = 1;

    ret_seconds /= 10;

    return ret_seconds;
}

unsigned long time_get_delta_seconds(void)
{
    unsigned long ret_seconds;

    PIE1bits.TMR1IE = 0;

    ret_seconds = mticks;

    PIE1bits.TMR1IE = 1;

    ret_seconds -= old_mticks;
    ret_seconds /= 10;

    return ret_seconds;
}

unsigned long time_get_reset_delta_seconds(void)
{
    unsigned long ret_seconds, oticks;

    PIE1bits.TMR1IE = 0;

    ret_seconds = mticks;
    oticks = mticks;

    PIE1bits.TMR1IE = 1;

    ret_seconds -= old_mticks;
    ret_seconds /= 10;
    old_mticks = oticks;

    return ret_seconds;
}

unsigned long time_get_ticks(void)
{
    unsigned long ret_ticks;

    PIE1bits.TMR1IE = 0;

    ret_ticks = mticks;

    PIE1bits.TMR1IE = 1;

    return ret_ticks;
}

unsigned long time_get_delta_ticks(void)
{
    unsigned long ret_ticks;

    PIE1bits.TMR1IE = 0;

    ret_ticks = mticks;

    PIE1bits.TMR1IE = 1;

    ret_ticks -= old_mticks;
    
    return ret_ticks;
}

unsigned long time_get_reset_delta_ticks(void)
{
    unsigned long ret_ticks, oticks;

    PIE1bits.TMR1IE = 0;

    ret_ticks = mticks;
    oticks = mticks;

    PIE1bits.TMR1IE = 1;

    ret_ticks -= old_mticks;
    old_mticks = oticks;

    return ret_ticks;
}

#pragma interrupt time_interrupt
void time_interrupt(void)
{
    PIR1bits.TMR1IF = 0;

    ticker_cnt++;

    if(ticker_cnt >= 391)
    {
        ticker_cnt = 0;
        mticks++;
    }

    tip_detect_process();
}
#pragma code



