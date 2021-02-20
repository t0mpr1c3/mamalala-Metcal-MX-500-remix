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

#pragma udata access _IRQ_DATA
static near unsigned char cur_rx_char;
static near unsigned char skipper;
static near UShortType adc;
near volatile unsigned char irq_mutex;
#pragma udata

void interrupt_init(void)
{
    RCONbits.IPEN = 1;
    INTCON = 0b11000000;
    skipper = 0;
    irq_mutex = 0;
}

void high_isr(void);

#pragma code high_isr = 0x08
//#pragma interrupt high_isr
void high_isr(void)
{
    _asm
        SETF    TMR1H, ACCESS
        CLRF    TMR1L, ACCESS
        goto    time_interrupt
    _endasm
}

#pragma code low_isr = 0x18
#pragma interruptlow low_isr
void low_isr(void)
{
    if(PIR1bits.TMR2IF == 1)
    {
        PIR1bits.TMR2IF = 0;

        if(ADCON0bits.GO == 0)
        {
            if(MUTEX_IS_NOT_SET(MUTEX_ADC_RESULTS))
            {
                adc.byte0 = ADRESL;
                adc.byte1 = ADRESH;

                if(adc_chn == 0)
                {
                    ADCON0 = 0b00000101;

                    adc_average_0 -= adc_results_0[adc_idx];
                    adc_results_0[adc_idx] = adc.ushort;
                    adc_average_0 += adc.ushort;

                    adc_chn = 1;
                }
                else if (adc_chn == 1)
                {
                    ADCON0 = 0b00001001;

                    adc_average_1 -= adc_results_1[adc_idx];
                    adc_results_1[adc_idx] = adc.ushort;
                    adc_average_1 += adc.ushort;

                    adc_chn = 2;
                }
                else if (adc_chn == 2)
                {
                    //if(!(adc_access_mutex & ADC_MUTEX_DELTACALC))
                    if(MUTEX_IS_NOT_SET(MUTEX_ADC_DELTACALC))
                    {
                        ADCON0 = 0b00000001;

                        adc_average_2 -= adc_results_2[adc_idx];
                        adc_results_2[adc_idx] = adc.ushort;
                        adc_average_2 += adc.ushort;

                        adc_chn = 0;

                        adc_idx++;
                        adc_idx &= 0x0F;

                        skipper++;
                        if(skipper & 0x08)
                        {
                            skipper = 0;
                            rf_manager_calc_data();
                            rf_manager_add_delta();
                        }
                    }
                }
                
                ADCON0bits.GO = 1;
            }
        }
    }

    if(INTCONbits.TMR0IF == 1)
    {
        backlight_process();
        process_encoder();
        INTCONbits.TMR0IF = 0;
    }

    if(PIE1bits.TXIE && TXSTAbits.TRMT)
    {
        if(tx_fifo_write_pos != tx_fifo_read_pos)
        {
            if(tx_fifo_fill > 0)
            {
                TXREG = tx_fifo[tx_fifo_read_pos++];
                tx_fifo_read_pos &= (FIFO_SIZE-1);
                tx_fifo_fill--;
            }
        }
        else
        {
            PIE1bits.TXIE = 0;
        }
    }

    if(PIR1bits.RCIF)
    {
        cur_rx_char = RCREG;

        if(RCSTAbits.OERR)
        {
            RCSTAbits.CREN = 0;
            RCSTAbits.CREN = 1;
        }

        if(rx_fifo_fill < FIFO_SIZE)
        {
            rx_fifo[rx_fifo_write_pos++] = cur_rx_char;
            rx_fifo_write_pos &= (FIFO_SIZE-1);
            rx_fifo_fill++;
        }
    }
}

#pragma code
