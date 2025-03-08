/*
 * main.c
 *
 *  Created on: Feb 27, 2025
 *      Author: User
 */
#include "LIB/stdTypes.h"
#include "util/delay.h"
#include"MCAL/DIO/interface.h"
#include"HAL/LCD/LCD_config.h"
#include"HAL/LCD/LCD.h"
#include"HAL/KEYPAD/KP_config.h"
#include"HAL/KEYPAD/KP_init.h"

 int main(void){

	 pin_config RWpin ={DIO_PIN0,DIO_PORTA};
	 pin_config RSpin ={DIO_PIN1,DIO_PORTA};
	 pin_config ENpin ={DIO_PIN2,DIO_PORTA};

	 pin_config dataPins[4]={{DIO_PIN3,DIO_PORTA},{DIO_PIN4,DIO_PORTA},{DIO_PIN5,DIO_PORTA},{DIO_PIN6,DIO_PORTA}};

	 LCD_cofig lcd={RSpin,RWpin,ENpin,{dataPins[0], dataPins[1], dataPins[2], dataPins[3]}};
	 LCD_voidInit(&lcd);


	 LCD_sendChar(&lcd,'A');
	 LCD_sendString(&lcd,"manar");
	 LCD_sendNumber(&lcd,(u32)44);

	 pin_conf rowpins[4]={{DIO_PIN0,DIO_PORTC},{DIO_PIN1,DIO_PORTC},{DIO_PIN2,DIO_PORTC},{DIO_PIN3,DIO_PORTC}};
	 pin_conf colpins[4]={{DIO_PIN4,DIO_PORTC},{DIO_PIN5,DIO_PORTC},{DIO_PIN6,DIO_PORTC},{DIO_PIN7,DIO_PORTC}};

	 kp_conf KP={{rowpins[0],rowpins[1],rowpins[2],rowpins[3]},{colpins[0],colpins[1],colpins[2],colpins[3]}};
	  KP_u8KeyPadInit(&KP);
	 u8 key;

while(1){
	key= (u8)KP_u8GetPressedKey(&KP);
	if(key!=KEYPAD_NO_PRESSED_KEY)
	LCD_sendChar(&lcd,key);
}




	 return 1;
	 }



	/* DIO_SET_PORT_DIR(DIO_PORTA,DIO_PORT_OUTPUT);

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

	 }*/

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



