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

unsigned short adc_results_0[16], adc_results_1[16], adc_results_2[16];
unsigned char adc_idx;
unsigned char adc_chn;
unsigned short adc_average_0, adc_average_1, adc_average_2;

void adc_init(void)
{
    logger_print_start_msg(S_ADC);

    ADCON1	= 0b00001100;
    ADCON0	= 0b00000001;
    ADCON2	= 0b10111110;
    PIE1bits.ADIE = 0;

    for(adc_chn = 0; adc_chn < 16; adc_chn++)
    {
        adc_results_0[adc_chn] = 0;
        adc_results_1[adc_chn] = 0;
        adc_results_2[adc_chn] = 0;
    }

    adc_average_0 = 0;
    adc_average_1 = 0;
    adc_average_2 = 0;
    adc_idx = 0;

    adc_chn = 0;

    IPR1bits.TMR2IP = 0;
    PIE1bits.TMR2IE = 1;

    ADCON0bits.GO = 1;
}

unsigned short adc_get_reading(unsigned char which)
{
    static unsigned short res;
    static ULongType ul;

    SET_MUTEX(MUTEX_ADC_RESULTS);

    switch(which)
    {
        case FORWARD:
            res = adc_average_0;
            break;

        case REFLECTED :
            res = adc_average_1;
            break;

        case SUPPLY:
            ul.ulong = adc_average_2;
            ul.ulong *= ADC_SUPPLY_FACTOR;
            res = ul.UShortType1.ushort;
            break;
    }

    RELEASE_MUTEX(MUTEX_ADC_RESULTS);

    return res;
}
