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

#ifndef INTERRUPT_H
#define INTERRUPT_H

#define SET_MUTEX(_X_)              irq_mutex |= _X_;
#define RELEASE_MUTEX(_X_)          irq_mutex &= ~_X_;

#define MUTEX_IS_SET(_X_)           (irq_mutex & _X_)
#define MUTEX_IS_NOT_SET(_X_)       (!(irq_mutex & _X_))

#define MUTEX_ADC_RESULTS       0b00000001
#define MUTEX_ADC_DELTACALC     0b00000010

extern near volatile unsigned char irq_mutex;

void interrupt_init(void);

#endif
