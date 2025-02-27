/*
 * main.c
 *
 *  Created on: Feb 27, 2025
 *      Author: User
 */
#include "LIB/stdTypes.h"
#include "util/delay.h"
#include"MCAL/DIO/interface.h"
//////////////////snack effect////////////////
 int main(void){

	 DIO_SET_PORT_DIR(DIO_PORTA,DIO_PORT_OUTPUT);

	 int i;
	 while(1){
       i=0;
		 while(i<=7){
			 DIO_SET_PIN_VAL(DIO_PORTA,i,DIO_HIGH);
			 i++;
			 _delay_ms(400);
		 }

		 while(i>=0){
					 DIO_SET_PIN_VAL(DIO_PORTA,i,DIO_LOW);
					 i--;
					 _delay_ms(400);
				 }

	 }

	/* DIO_SET_PIN_DIR(DIO_PORTD,DIO_PIN3,DIO_INPUT);
	 DIO_SET_PIN_VAL(DIO_PORTD,DIO_PIN3,DIO_HIGH);
	 DIO_SET_PIN_DIR(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);
	 DIO_SET_PIN_VAL(DIO_PORTD,DIO_PIN5,DIO_LOW);
	 u8 PIN_VAL;
	 while(1){

		 DIO_GET_PIN_VAL(DIO_PORTD,DIO_PIN3,&PIN_VAL);
		 if(PIN_VAL==0){
			 DIO_SET_PIN_VAL(DIO_PORTD,DIO_PIN5,DIO_HIGH);
			 while(PIN_VAL==0){
				 DIO_GET_PIN_VAL(DIO_PORTD,DIO_PIN3,&PIN_VAL);
			 }
		 }

			 DIO_SET_PIN_VAL(DIO_PORTD,DIO_PIN5,DIO_LOW);
	 }*/


	 return 1;
 }
