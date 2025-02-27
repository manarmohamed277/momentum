/*
 * PROG.c
 *
 *  Created on: Feb 25, 2025
 *      Author: User
 */

#include  "../../LIB/stdTypes.h"
#include  "../../LIB/BIT_SET.h"
#include  "../../LIB/errorState.h"
#include "priv.h"
#include "config.h"
#include "interface.h"
#include "REG.h"
u8 DIO_SET_PIN_DIR(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8val){
	u8 LOCAL_ERROR =DIO_NOK;
	if(copy_u8pin<=7){
		if(copy_u8port<=3){
			switch(copy_u8port){
			case DIO_PORTA:
				RESET_BIT(DDRA,copy_u8pin);
				SET_BIT(DDRA,copy_u8pin,copy_u8val);
				break;

			case DIO_PORTB:
				RESET_BIT(DDRB,copy_u8pin);
				SET_BIT(DDRB,copy_u8pin,copy_u8val);
							break;
			case DIO_PORTC:
				RESET_BIT(DDRC,copy_u8pin);
				SET_BIT(DDRC,copy_u8pin,copy_u8val);
							break;

			case DIO_PORTD:
				RESET_BIT(DDRD,copy_u8pin);
				SET_BIT(DDRD,copy_u8pin,copy_u8val);
							break;
			}
			LOCAL_ERROR =OK;
		}

	}
  return LOCAL_ERROR;
}


u8 DIO_SET_PIN_VAL(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8val){

	u8 LOCAL_ERROR=DIO_NOK;
	if((copy_u8port<=3)&&(copy_u8pin<=7)&&(copy_u8val<=1)){
		switch(copy_u8port){
		case DIO_PORTA:
			RESET_BIT(PORTA,copy_u8pin);
			SET_BIT(PORTA,copy_u8pin,copy_u8val);
			break;
		case DIO_PORTB:
					RESET_BIT(PORTB,copy_u8pin);
					SET_BIT(PORTB,copy_u8pin,copy_u8val);
			break;
		case DIO_PORTC:
					RESET_BIT(PORTC,copy_u8pin);
					SET_BIT(PORTC,copy_u8pin,copy_u8val);
					break;
		case DIO_PORTD:
					RESET_BIT(PORTD,copy_u8pin);
					SET_BIT(PORTD,copy_u8pin,copy_u8val);
					break;

		}
		LOCAL_ERROR=OK;
	}
return LOCAL_ERROR;
}


u8 DIO_SET_PORT_VAL(u8 copy_u8port,u8 copy_u8val){
	u8 LOKAL_ERROR=DIO_NOK;
	if(copy_u8port<=3){
		switch(copy_u8port){
		case DIO_PORTA:
					PORTA=copy_u8val;
					break;
				case DIO_PORTB:
							PORTB=copy_u8val;
					break;
				case DIO_PORTC:
									PORTC=copy_u8val;
							break;
				case DIO_PORTD:
									PORTD=copy_u8val;
							break;
		}
		LOKAL_ERROR=OK;
	}
	return LOKAL_ERROR;
}
u8 DIO_SET_PORT_DIR(u8 copy_u8port,u8 copy_u8val){
	u8 LOKAL_ERROR=DIO_NOK;
	if(copy_u8port<=3){
		switch(copy_u8port){
		case DIO_PORTA:
					DDRA=copy_u8val;
					break;
				case DIO_PORTB:
							DDRB=copy_u8val;
					break;
				case DIO_PORTC:
									DDRC=copy_u8val;
							break;
				case DIO_PORTD:
									DDRD=copy_u8val;
							break;
		}
		LOKAL_ERROR=OK;
	}
	return LOKAL_ERROR;
}

u8 DIO_GET_PIN_VAL(u8 copy_u8port,u8 copy_u8pin,u8 *copy_u8val){
	u8 LOCAL_ERROR=DIO_NOK;
	if((copy_u8port<=3)&&(copy_u8pin<=7)){
		switch(copy_u8port){
		case DIO_PORTA:
			*copy_u8val=GET_BIT(PINA,copy_u8pin);
			break;
		case DIO_PORTB:
					*copy_u8val=GET_BIT(PINB,copy_u8pin);
					break;
		case DIO_PORTC:
					*copy_u8val=GET_BIT(PINC,copy_u8pin);
					break;
		case DIO_PORTD:
					*copy_u8val=GET_BIT(PIND,copy_u8pin);
					break;

		}
		LOCAL_ERROR=OK;
	}
	return LOCAL_ERROR;
}

u8 DIO_GET_PORT_VAL(u8 copy_u8port,u8* copy_u8val){
	u8 LOCAL_ERROR=DIO_NOK;
	if((copy_u8port<=3)){
		switch(copy_u8port){
		case DIO_PORTA:
			* copy_u8val=PINA; break;
		case DIO_PORTB:
					* copy_u8val=PINB; break;
		case DIO_PORTC:
					* copy_u8val=PINC; break;
		case DIO_PORTD:
					* copy_u8val=PINC; break;

		}
		LOCAL_ERROR=OK;
		}
return LOCAL_ERROR;
}

u8 DIO_TOGGLE_PIN(u8 copy_u8port,u8 copy_u8pin){

	u8 LOCAL_ERROR=DIO_NOK;
		if((copy_u8port<=3)&&(copy_u8pin<=7)){
			switch(copy_u8port){
			case DIO_PORTA:
				TOGGLE_BIT(PORTA,copy_u8pin);
				break;
			case DIO_PORTB:
				TOGGLE_BIT(PORTB,copy_u8pin);;
				break;
			case DIO_PORTC:
				TOGGLE_BIT(PORTC,copy_u8pin);
						break;
			case DIO_PORTD:
				TOGGLE_BIT(PORTD,copy_u8pin);
						break;

			}
			LOCAL_ERROR=OK;
		}
	return LOCAL_ERROR;
	}


















