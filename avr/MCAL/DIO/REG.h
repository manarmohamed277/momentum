/*
 * REG.h
 *
 *  Created on: Feb 25, 2025
 *      Author: User
 */

#ifndef MCAL_DIO_REG_H_
#define MCAL_DIO_REG_H_

#define DDRA  		*((u8*)0x3A)
#define PORTA		*((u8*)0x3B)
#define PINA		*((volatile u8*)0x39)

#define DDRB  		*((u8*)0x37)
#define PORTB		*((u8*)0x38)
#define PINB		*((volatile u8*)0x36)

#define DDRC  		*((u8*)0x34)
#define PORTC		*((u8*)0x35)
#define PINC		*((volatile u8*)0x33)

#define DDRD  		*((u8*)0x31)
#define PORTD		*((u8*)0x32)
#define PIND		*((volatile u8*)0x30)


#endif /* MCAL_DIO_REG_H_ */
