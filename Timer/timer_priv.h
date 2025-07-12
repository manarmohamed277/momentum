/*
 * timer_priv.h
 *
 *  Created on: Mar 22, 2025
 *      Author: User
 */

#ifndef TIMER_PRIV_H_
#define TIMER_PRIV_H_


#define  TCCR0 *((volatile u8*)0x33)
#define  TCNT0 *((volatile u8*)0x32)
#define  OCR0 *((volatile u8*)0x3C)
#define  TIMSK *((volatile u8*)0x39)
#define  TIFR *((volatile u8*)0x3)











#endif /* TIMER_PRIV_H_ */
