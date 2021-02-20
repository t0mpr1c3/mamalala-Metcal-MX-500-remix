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

#ifndef ADC_H
#define ADC_H

#define FORWARD     0
#define REFLECTED   1
#define SUPPLY      2


#define ADC_VOLTS_FACTOR            ((float) 0.06207233626588)
#define ADC_SUPPLY_FACTOR           11595

extern unsigned short adc_results_0[16], adc_results_1[16], adc_results_2[16];
extern unsigned char adc_idx;
extern unsigned char adc_chn;
extern unsigned short adc_average_0, adc_average_1, adc_average_2;

void adc_init(void);
unsigned short adc_get_reading(unsigned char which);
void adc_store_vfvr(void);

#endif
