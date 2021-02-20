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

#pragma udata access _RF_MAN_CALC
near static ULongType A, B;
near static unsigned short Rho;
near static unsigned short old_vf, old_vr, old_swr, old_pwr, old_supply;
near static signed short power_delta, old_power_delta;
near static unsigned char mode;
near static RFDataType rf_data;
#pragma udata

void rf_manager_init(void)
{
    logger_print_start_msg(S_RF_MANAGER);

    SET_MUTEX(MUTEX_ADC_DELTACALC);

    rf_data.vf = 0;
    rf_data.vr = 0;
    rf_data.iswr = 0;
    rf_data.ipwr = 0;

    old_vf = 0;
    old_vr = 0;
    old_swr = 0;
    old_pwr = 0;
    old_supply = 0;

    power_delta = 0;
    old_power_delta = 0;

    mode = 0;
    
    RELEASE_MUTEX(MUTEX_ADC_DELTACALC);
}

void rf_manager_set_mode(unsigned char val)
{
    if(val != mode)
    {
        mode = val;
        logger_print_module_msg_val(S_RF_MANAGER, S_CHANGE_POWERLEVEL, rf_manager_get_mode_string());

        if(val == RF_POWER_OFF)
        {
            RFG_EN = 0;
            VLIM_DIR = PIN_IN;
        }
        else if(val == RF_POWER_NORMAL)
        {
            VLIM_DIR = PIN_IN;
            RFG_EN = 1;
        }
        else if(val == RF_POWER_BOOST)
        {
            VLIM_OUT = 0;
            VLIM_DIR = PIN_OUT;
            RFG_EN = 1;
        }
        else if(val == RF_POWER_LIMIT)
        {
            VLIM_OUT = 1;
            VLIM_DIR = PIN_OUT;
            RFG_EN = 1;
        }
    }
}

unsigned char rf_manager_get_mode(void)
{
    return mode;
}

unsigned short rf_manager_get_mode_string(void)
{
    switch(mode)
    {
        case RF_POWER_OFF:
            return S_OFF;
            break;

        case RF_POWER_NORMAL:
            return S_NORMAL;
            break;

        case RF_POWER_BOOST:
            return S_BOOST;
            break;

        case RF_POWER_LIMIT:
            return S_LIMIT;
            break;

        default:
            return S_INVALID;
            break;
    }
}

/*
 * collect the changes in the readings, separately for power increase or decrease
 * The following applies:
 *
 * - Power output increases for the following changes in readings:
 *   - Forward RF increase
 *   - Reflected RF decrease
 *   - SWR decrease
 *   - Supply voltage increase
 *   - RF power level increase
 *
 * - Power output decreases for the following changes in readings:
 *   - Forward RF decrease
 *   - Reflected RF increase
 *   - SWR increase
 *   - Supply voltage decrease
 *   - RF power level decrease
 */

void rf_manager_add_delta(void)
{
    static unsigned short t;

    SET_MUTEX(MUTEX_ADC_DELTACALC);

    // VF, power drop = old > current
    t = rf_data.vf;
    if(old_vf > t)
    {
        power_delta -= (old_vf - t);
    }
    else
    {
        power_delta += (t - old_vf);
    }
    old_vf = t;

    // VR, power rise = old > current
    t = rf_data.vr;
    if(old_vr > t)
    {
        power_delta += (old_vr - t);
    }
    else
    {
        power_delta -= (t - old_vr);
    }
    old_vr = t;

    // SWR, power rise = old > current
    t = rf_data.iswr; // .swr
    if(old_swr > t)
    {
        power_delta += (old_swr - t);
    }
    else
    {
        power_delta -= (t - old_swr);
    }
    old_swr = t;

    // POWER, power drop = old > current
    t = rf_data.ipwr; //rf_manager_get_pwr(1000);
    if(old_pwr > t)
    {
        power_delta -= (old_pwr - t);
    }
    else
    {
        power_delta += (t - old_pwr);
    }
    old_pwr = t;

    // SUPPLY, power drop = old > current
    t = rf_data.supply;
    if(old_supply > t)
    {
        power_delta -= (old_supply - t);
    }
    else
    {
        power_delta += (t - old_supply);
    }
    old_supply = t;

    // hard-limit the results to 100 max.
    if(power_delta > 100)
    {
        power_delta = 100;
    }
    if(power_delta < -100)
    {
        power_delta = -100;
    }

    RELEASE_MUTEX(MUTEX_ADC_DELTACALC);
}

void rf_manager_store_delta(void)
{
    SET_MUTEX(MUTEX_ADC_DELTACALC);

    old_power_delta = power_delta;
    power_delta = 0;

    RELEASE_MUTEX(MUTEX_ADC_DELTACALC);
}

void rf_manager_clear_delta(void)
{
    power_delta = 0;
    old_power_delta = 0;
}

unsigned short rf_manager_get_reading(unsigned char which)
{
    static unsigned short res;

    res = 0;

    SET_MUTEX(MUTEX_ADC_DELTACALC);

    switch(which)
    {
        case RF_POWER_RISE:
            if(power_delta > 0)
            {
                res = power_delta;
            }
            else
            {
                res = 0;
            }
            break;

        case RF_POWER_DROP:
            if(power_delta < 0)
            {
                res = -power_delta;
            }
            else
            {
                res = 0;
            }
            break;

        case RF_POWER_COMBINED:
            if(power_delta > 0)
            {
                res = power_delta;
            }
            else if(power_delta < 0)
            {
                res = (-power_delta);
            }
            else
            {
                res = 0;
            }

            if(old_power_delta > 0)
            {
                res += power_delta;
            }
            else if(old_power_delta < 0)
            {
                res += (-power_delta);
            }
            break;

        case RF_VSWR:
            res = rf_data.iswr;
            break;

        case RF_VFORWARD:
            res = rf_data.vf;
            break;

        case RF_VREFLECTED:
            res = rf_data.vr;
            break;

        case RF_POWER:
            res = rf_data.ipwr;
            break;

        case RF_SUPPLY:
            res = rf_data.supply;
            break;
    }

    RELEASE_MUTEX(MUTEX_ADC_DELTACALC);

    return res;
}

void rf_manager_calc_data(void)
{

    if(mode == RF_POWER_OFF)
    {
        rf_data.vf = 0;
        rf_data.vr = 0;
        rf_data.supply = 0;
        rf_data.iswr = 0;
        rf_data.ipwr = 0;
        return;
    }

    SET_MUTEX(MUTEX_ADC_RESULTS);

    rf_data.vf = adc_average_0;
    rf_data.vr = adc_average_1;
    rf_data.supply = adc_get_reading(SUPPLY);

    RELEASE_MUTEX(MUTEX_ADC_RESULTS);

    // all calculations are integer based to avoid using slower FP math
    
    if((rf_data.vf < rf_data.vr) || (rf_data.vf == 0))
    {
        rf_data.iswr = 0;
        rf_data.ipwr = 0;
    }
    else
    {
        B.ulong = rf_data.vf;
        A.short1 = rf_data.vr;
        A.short0 = 0;

        A.ulong /= B.short0;

        if(A.short1)
        {
            Rho = 0xFFFF;
        }
        else
        {
            Rho = A.short0;
        }

        B.short0 = Rho;
        B.short0 >>= 1;
        B.short0 = ~B.short0;
        B.short0++;
        B.short0 ^= 0x8000;
        B.short1 = 0;

        A.short1 = Rho;
        A.short1 >>= 1;
        A.short1 |= 0x8000;
        A.short0 = 0;

        A.ulong /= B.short0;

        B.byte0 = A.byte1;
        B.byte1 = A.byte2;
        B.short1 = 0;

        B.ulong *= 100;

        B.byte0 = B.byte1;
        B.byte1 = B.byte2;
        rf_data.iswr = B.short0;

        // caluclate bogus power value
        Rho = (rf_data.vf + rf_data.vr);
        A.ulong = (rf_data.vf - rf_data.vr);

        B.ulong = 0xFFFF0000;
        B.ulong /= Rho;
        B.ulong *= A.short0;

        B.short0 = B.short1;
        B.short1 = 0;

        B.ulong *= 1025; // 1001

        rf_data.ipwr = B.short1;


        // tweak the power reading depending on the supply voltage
        // just to make the reading look nice as bargraph

        if(rf_data.supply <= 2048)
        {
            B.ulong = rf_data.supply;
        }
        else
        {
            B.ulong = 2048;
        }

        B.ulong *= B.ulong;

        if(rf_data.ipwr <= 1024)
        {
            B.ulong *= rf_data.ipwr;
        }
        else
        {
            B.ulong *= 1024;
        }

        B.byte0 = B.byte1;
        B.byte1 = B.byte2;
        B.byte2 = B.byte3;
        B.byte3 = 0;

        if(mode == RF_POWER_LIMIT)
        {
            B.ulong <<= 1;
        }
        else
        {
            B.ulong <<= 2;
        }

        if(B.short1 <= 1024)
        {
            rf_data.ipwr = B.short1;
        }
        else
        {
            rf_data.ipwr = 1024;
        }
    }

    rf_data.vf >>= 2;
    rf_data.vr >>= 2;
}


