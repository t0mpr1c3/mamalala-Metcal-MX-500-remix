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

#pragma udata access _RENCODER_DATA 
static near signed short encoder_val;
static near unsigned char state_encoder;
static near unsigned char old_state_encoder;
static near unsigned char temp_encoder;
static near unsigned char encoder_cnt;

static near unsigned char button_cnt;
static near unsigned char old_k, cur_k;
static near unsigned char button_sample;
static near unsigned char button_state;
static near unsigned char button;
#pragma udata

static unsigned short enctab[8] =
{
    1000,
     100,
      10,
       5,
       5,
       1,
       1,
       1
};

void encoder_init(void)
{
    logger_print_start_msg(S_ROTARY_ENCODER);

    state_encoder = 0;
    old_state_encoder = state_encoder;
    encoder_val = 0;
    process_encoder();
    encoder_val = 0;
    encoder_cnt = 0;

    button_state = 0;
    button = 0;
    button_sample = 100;
    old_k = 0;

    T0CON = 0b01000010;
    TMR0H = 0xFF;
    TMR0L = 0x00;
    INTCON2bits.TMR0IP = 0;
    INTCONbits.TMR0IF = 0;
    INTCONbits.TMR0IE = 1;
    T0CONbits.TMR0ON = 1;
}

signed short encoder_get(void)
{
    static signed short res;

    INTCONbits.TMR0IE = 0;
    res = encoder_val;
    INTCONbits.TMR0IE = 1;

    return(res);
}

void encoder_reset(void)
{
    INTCONbits.TMR0IE = 0;
    encoder_val = 0;
    INTCONbits.TMR0IE = 1;
}

unsigned char encoder_get_button(void)
{
    static unsigned char tval;

    INTCONbits.TMR0IE = 0;
    if((button_state == BSTATE_DONE) || (button_state == BSTATE_LONGPUSHED))
    {
        tval = button;
    }
    else
    {
        tval = BUTTON_IDLE;
    }
    INTCONbits.TMR0IE = 1;

    return(tval);
}

void encoder_reset_button(void)
{
    INTCONbits.TMR0IE = 0;
    if((button_state == BSTATE_DONE) && (ENC1_K == 1))
    {
        button = 0;
        button_state = 0;
        button_sample = 0;
        button_cnt = 0;
    }
    INTCONbits.TMR0IE = 1;
}

void encoder_clear_button(void)
{
    INTCONbits.TMR0IE = 0;

    button = BUTTON_CLEARED;
    button_sample = 0;
    button_cnt = 0;

    INTCONbits.TMR0IE = 1;
}

void encoder_reset_all(void)
{
    INTCONbits.TMR0IE = 0;

    encoder_val = 0;

    if((button_state == BSTATE_DONE) && (ENC1_K == 1))
    {
        button = 0;
        button_state = 0;
        button_sample = 0;
        button_cnt = 0;
    }

    INTCONbits.TMR0IE = 1;
}

void process_encoder(void)
{
    // handle the rotary encoder

    state_encoder = 0;
    if(ENC1_A)
        state_encoder |= 0x02;
    if(ENC1_B)
        state_encoder |= 0x01;

    if(state_encoder != old_state_encoder)
    {
        temp_encoder = old_state_encoder;
        temp_encoder <<= 2;
        temp_encoder |= state_encoder;

        switch(temp_encoder)
        {
            case 0x01:
            case 0x0E:
                encoder_cnt >>= 5;
                encoder_val += enctab[encoder_cnt];
                if(encoder_val > 9999)
                {
                    encoder_val = 9999;
                }

                encoder_cnt = 0;

                break;

            case 0x04:
            case 0x0B:
                encoder_cnt >>= 5;
                encoder_val -= enctab[encoder_cnt];

                if(encoder_val < -9999)
                {
                    encoder_val = -9999;
                }

                encoder_cnt = 0;
                
                break;

            default:
                break;
        }

        old_state_encoder = state_encoder;
    }

    if(encoder_cnt < 0xFF)
    {
        encoder_cnt++;
    }

    
    // handle the button

    cur_k = ENC1_K;

    if(cur_k != old_k)
    {
        button_sample = 0;
        old_k = cur_k;
    }
    else
    {
    
        button_sample++;

        if(button_sample == 150)
        {
            button_sample = 0;
            switch(button_state)
            {
                case BSTATE_IDLE:
                    if(cur_k == 0)
                    {
                        button_state = BSTATE_FIRSTPUSH;
                        button_cnt = 0;
                    }
                    break;

                case BSTATE_FIRSTPUSH:
                    if(cur_k == 0)
                    {
                        if(button_cnt >= BUTTON_TIME_LONG)
                        {
                            button_state = BSTATE_LONGPUSHED;
                            button = BUTTON_LONGPUSH;
                        }
                    }
                    else
                    {
                        button_state = BSTATE_FIRSTRELEASE;
                        button_cnt = 0;
                    }
                    break;
                case BSTATE_LONGPUSHED:
                    if(cur_k == 1)
                    {
                        button_state = BSTATE_DONE;
                    }
                    break;

                case BSTATE_FIRSTRELEASE:
                    if(cur_k == 1)
                    {
                        if(button_cnt >= BUTTON_TIME_SHORT)
                        {
                            button_state = BSTATE_DONE;
                            button = BUTTON_CLICKED;
                        }
                    }
                    else
                    {
                        button_state = BSTATE_SECONDPUSH;
                        button_cnt = 0;
                    }
                    break;

                case BSTATE_SECONDPUSH:
                    if(cur_k == 0)
                    {
                        if(button_cnt >= BUTTON_TIME_LONG)
                        {
                            button_state = BSTATE_DONE;
                            button = BUTTON_CLICKPUSH;
                        }
                    }
                    else
                    {
                        button_state = BSTATE_SECONDRELEASE;
                        button_cnt = 0;
                    }
                    break;

                case BSTATE_SECONDRELEASE:
                    if(cur_k == 1)
                    {
                        button_state = BSTATE_DONE;
                        button = BUTTON_DOUBLECLICKED;
                    }
                    break;

                case BSTATE_DONE:
                    button_cnt = 0;
                    button_sample = 0;
                    old_k = 0xA5;
                    break;
            }

            if(button_cnt <= BUTTON_TIME_LONG)
            {
                button_cnt++;
            }
        }
    }
}