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

#pragma udata access _TIP_DETECT_DATA
static near unsigned char tip_status;
#pragma udata

static unsigned char old_tip_status;

void tip_detect_init(void)
{
    logger_print_start_msg(S_TIP_DETECTOR);

    if(TIP_DET == 1)
    {
        tip_status = TIP_OK;
        old_tip_status = TIP_OK;
    }
    else
    {
        tip_status = TIP_MISSING;
        old_tip_status = TIP_MISSING;
    }
}

void tip_detect_process(void)
{
    if(RFG_EN)
    {
        if(TIP_DET == 0)
        {
            tip_status = TIP_MISSING;
        }
        else
        {
            tip_status = TIP_OK;
        }
    }
}

unsigned char tip_detect_get_status(void)
{
    if(old_tip_status != tip_status)
    {
        old_tip_status = tip_status;

        if(tip_status == TIP_OK)
        {
            logger_print_module_msg(S_TIP_DETECTOR, S_TIP_DETECTED);
        }
        else
        {
            logger_print_module_msg(S_TIP_DETECTOR, S_NO_TIP);
        }
    }
    return tip_status;
}
