/*
 * LCD.c
 *
 *  Created on: Feb 22, 2025
 *      Author: User
 */

#include  "../../LIB/stdTypes.h"
#include  "../../LIB/BIT_SET.h"
#include  "../../LIB/errorState.h"
#include "LCD.h"
#include "LCD_config.h"
#include "LCD_int.h"
#include "../../MCAL/DIO/interface.h"
#include <util/delay.h>


u8 static count=0;

void LCD_voidInit(LCD_cofig *lcd){
	_delay_ms(40);
    //SET pins
	DIO_SET_PIN_DIR(lcd->EN.port,lcd->EN.pin,DIO_OUTPUT);
	DIO_SET_PIN_DIR(lcd->RS.port,lcd->RS.pin,DIO_OUTPUT);
	DIO_SET_PIN_DIR(lcd->RW.port,lcd->RW.pin,DIO_OUTPUT);
#if BIT_MODE==LCD_4BIT_MODE
	for(u8 i=4;i<=7;i++){
		DIO_SET_PIN_DIR(lcd->data[i].port,lcd->data[i].pin,DIO_OUTPUT);
	}

#elif 	BIT_MODE==LCD_8BIT_MODE
	for(u8 i=0;i<4;i++){
			DIO_SET_PIN_DIR(lcd->data[i].port,lcd->data[i].pin,DIO_OUTPUT);
		}

#endif

	//func set

#if BIT_MODE==LCD_4BIT_MODE
LCD_sendCommand(lcd,_LCD_4BIT_MODE);
#endif
LCD_sendCommand(lcd,lcd_Home);
_delay_ms(1);
LCD_sendCommand(lcd,lcd_Clear);
_delay_ms(1);
LCD_sendCommand(lcd,lcd_EntryMode);
_delay_ms(1);
}



void LCD_sendChar(LCD_cofig* lcd,u8 data){

	//RS,-> HIGH to write data
		DIO_SET_PIN_VAL(lcd->RS.port,lcd->RS.pin,DIO_HIGH);
		DIO_SET_PIN_VAL(lcd->RW.port,lcd->RW.pin,DIO_LOW);
		//enable ->low
		DIO_SET_PIN_VAL(lcd->EN.port,lcd->EN.pin,DIO_LOW);

	#if BIT_MODE==LCD_4BIT_MODE
		if(count==16){
						LCD_setCursor(lcd,ROW2,1);
					}
					else if(count==32){
						LCD_clear(lcd);
						LCD_setCursor(lcd,ROW1,0);
						count=0;
					}

		u8 temp;
		temp=( data>>4)&0x0f;
		for(int i=0;i<4;i++){

			DIO_SET_PIN_VAL(lcd->data[i].port,lcd->data[i].pin,(temp>>i)&0x01);

		}
		temp=data&0x0f;
		for(int i=0;i<4;i++){
				DIO_SET_PIN_VAL(lcd->data[i].port,lcd->data[i].pin,(temp>>i)&0x01);
			}
		count++;

	#elif  BIT_MODE==LCD_8BIT_MODE

					if(count==16){
									LCD_setCursor(lcd,ROW2,1);
								}
								else if(count==32){
									LCD_clear(lcd);
									LCD_setCursor(lcd,ROW1,0);
									count=0;
								}
					for(int i=0;i<8;i++){
					DIO_SET_PIN_VAL(lcd->data[i].port,lcd->data[i].pin,(data>>i)&0x01);
				}
					count++;
	#endif
	//enable ->HIGH
	DIO_SET_PIN_VAL(lcd->EN.port,lcd->EN.pin,DIO_HIGH);


}
void LCD_sendCommand(LCD_cofig* lcd,u8 command){
	//RS,RW -> LOW to write command
	DIO_SET_PIN_VAL(lcd->RS.port,lcd->RS.pin,DIO_LOW);
	DIO_SET_PIN_VAL(lcd->RW.port,lcd->RW.pin,DIO_LOW);
	//enable ->low
	DIO_SET_PIN_VAL(lcd->EN.port,lcd->EN.pin,DIO_LOW);

#if BIT_MODE==LCD_4BIT_MODE
	u8 temp;
	temp=(command>>4)&0x0f;
	for(int i=0;i<4;i++){
		DIO_SET_PIN_VAL(lcd->data[i].port,lcd->data[i].pin,(temp>>i)&0x01);
	}
	temp=command&0x0f;
	for(int i=0;i<4;i++){
			DIO_SET_PIN_VAL(lcd->data[i].port,lcd->data[i].pin,(temp>>i)&0x01);
		}

#elif  BIT_MODE==LCD_8BIT_MODE

			for(int i=0;i<8;i++){
				DIO_SET_PIN_VAL(lcd->data[i].port,lcd->data[i].pin,(commmand>>i)&0x01);
			}
#endif
//enable ->HIGH
DIO_SET_PIN_VAL(lcd->EN.port,lcd->EN.pin,DIO_HIGH);

}
void LCD_sendNumber(LCD_cofig* lcd,u32 num){
	 u8 numArr[10],i=0,j=0;
			   if(num == 0)
			   {
				    LCD_sendChar(lcd,'0');
			   }
			   else
			   {
				   while(num)
				   {
					   numArr[i]= num%10+'0';
					   num/=10;
						i++;
				   }
				   for(j=i;j>0;j--)
				   {
					   LCD_sendChar(lcd,numArr[j-1]);
				   }
			   }

}
void LCD_sendString(LCD_cofig* lcd,u8* string ){

	while(string!=NULL){
		LCD_sendChar(lcd,*string++);
	}
}
void LCD_clear(LCD_cofig* lcd){
	LCD_sendCommand(lcd,lcd_Clear);
}
void LCD_setCursor(LCD_cofig* lcd,u8 row,u8 column){

	  column--;

			switch(row){
			            case ROW1:  LCD_sendCommand(lcd,(0x80 + column)); break;
			            case ROW2:  LCD_sendCommand(lcd,(0xc0 + column)); break;
			            default:;
			        }
}
