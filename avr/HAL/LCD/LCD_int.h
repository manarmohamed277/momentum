/*
 * LCD_int.h
 *
 *  Created on: Mar 7, 2025
 *      Author: User
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

#define lcd_DisplayOn_CursorOff       0x0c          // display on, cursor off, don't blink character
#define lcd_DisplayOn_CursorOn        0x0e          // display on, cursor on, don't blink character
#define lcd_DisplayOff_CursorOff      0x08          // turn display off
#define lcd_Clear                     0x01          //replace all characters with ASCII 'space'
#define lcd_EntryMode                 0x06          // shift cursor from left to right on read/write
#define lcd_Home                      0x02          // return cursor to first position on first line
#define lcd_CGRAM                     0x40          // the first Place/Address at CGRAM
#define lcd_SetCursor                 0x80          // set cursor position
#define lcd_FunctionReset             0x30          // reset the LCD
#define _LCD_8BIT_MODE				  0x30
#define _LCD_4BIT_MODE	              0x20


void LCD_voidInit(LCD_cofig *lcd);
void LCD_sendChar(LCD_cofig* lcd,u8 Data);
void LCD_sendCommand(LCD_cofig* lcd,u8 command);
void LCD_sendNumber(LCD_cofig* lcd,u32 num);
void LCD_sendString(LCD_cofig* lcd,u8* string );
void LCD_clear(LCD_cofig* lcd);
void LCD_setCursor(LCD_cofig* lcd,u8 row,u8 column);
#endif /* LCD_INT_H_ */
