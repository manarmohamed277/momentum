/*
 * interface.h
 *
 *  Created on: Feb 25, 2025
 *      Author: User
 */

#ifndef MCAL_DIO_INTERFACE_H_
#define MCAL_DIO_INTERFACE_H_

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3


//PINS
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7



#define DIO_OUTPUT 1
#define DIO_INPUT 0
#define DIO_HIGH 1
#define DIO_LOW 0

#define DIO_PORT_OUTPUT 0xff
#define DIO_INTPUT 0
#define DIO_PORT_HIGH 0xff
#define DIO_LOW 0

u8 DIO_SET_PIN_DIR(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8val);
u8 DIO_SET_PIN_VAL(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8val);
u8 DIO_GET_PIN_VAL(u8 copy_u8port,u8 copy_u8pin,u8 *copy_u8val);
u8 DIO_TOGGLE_PIN(u8 copy_u8port,u8 copy_u8pin);

u8 DIO_SET_PORT_DIR(u8 copy_u8port,u8 copy_u8val);
u8 DIO_SET_PORT_VAL(u8 copy_u8port,u8 copy_u8val);
u8 DIO_GET_PORT_VAL(u8 copy_u8port,u8 *copy_u8val);
#endif /* MCAL_DIO_INTERFACE_H_ */
