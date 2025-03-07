/*
 * LCD.h
 *
 *  Created on: Feb 22, 2025
 *      Author: User
 */

#ifndef LCD_H_
#define LCD_H_



#if BIT_MODE==LCD_4BIT_MODE

typedef struct{
	u8 pin;
	u8 port;
}pin_config;

typedef struct{
	pin_config RS;
	pin_config RW;
	pin_config EN;
	pin_config data[4];
}LCD_cofig ;




#elif BIT_MODE==LCD_8BIT_MODE
typedef struct{
	u8 pin;
	u8 port;
}pin_config;

typedef struct{
	pin_config RS;
	pin_config RW;
	pin_config EN;
	pin_config data[8];
}LCD_cofig ;


#endif

#define ROW1 1
#define ROW2 2

#endif /* LCD_H_ */
