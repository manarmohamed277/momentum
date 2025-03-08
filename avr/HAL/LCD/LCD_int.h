/*
 * LCD_int.h
 *
 *  Created on: Mar 7, 2025
 *      Author: User
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

/*#define lcd_DisplayOn_CursorOff       0x0c          // display on, cursor off, don't blink character
#define lcd_DisplayOn_CursorOn        0x0e          // display on, cursor on, don't blink character
#define lcd_DisplayOff_CursorOff      0x08          // turn display off
#define lcd_Clear                     0x01          //replace all characters with ASCII 'space'
#define lcd_EntryMode                 0x06          // shift cursor from left to right on read/write
#define lcd_Home                      0x02          // return cursor to first position on first line
#define lcd_CGRAM                     0x40          // the first Place/Address at CGRAM
#define lcd_SetCursor                 0x80          // set cursor position
#define lcd_FunctionReset             0x30          // reset the LCD
#define _LCD_8BIT_MODE				  0x30
#define _LCD_4BIT_MODE	              0x20*/

#define _LCD_CLEAR						0x01					//The LCD Will clear and DDRAM Will clear

#define _LCD_RETURN_HOME				0x02					//Cursor return row 0 column 0
#define _LCD_DEC_CURSOR_SHIFT_OFF		0x04					//when write character the cursor will shift to left
#define _LCD_DEC_CURSOR_SHIFT_ON		0x05					//when write character the display will shift to right
#define _LCD_INC_CURSOR_SHIFT_OFF		0x06					//when write character the cursor will shift to right
#define _LCD_INC_CURSOR_SHIFT_ON		0x07					//when write character the display will shift to left

//
#define _LCD_CURSOR_DISPLAY_OFF			0x08					//The cursor will off and lcd will clear without clearing DDRAM
#define _LCD_CURSOR_OFF					_LCD_CURSOR_DISPLAY_OFF | _LCD_DISPLAY_ON
#define _LCD_CURSOR_ON					0x09 | _LCD_DISPLAY_ON	//Cursor will ON
#define _LCD_UNDERLINE_CURSOR_OFF		_LCD_CURSOR_DISPLAY_OFF | _LCD_DISPLAY_ON
#define _LCD_UNDERLINE_CURSOR_ON		0x0A | _LCD_DISPLAY_ON	//UnderLined Cursor will on
#define _LCD_DISPLAY_OFF				_LCD_CURSOR_DISPLAY_OFF
#define _LCD_DISPLAY_ON					0x0C					//Display char will on

//
#define _LCD_MOVE_CURSOR_SHIFT_LEFT		0x10					//Cursor will point to last pos
#define _LCD_MOVE_CURSOR_SHIFT_RIGHT	0x14					//Cursor will point to next pos
#define _LCD_MOVE_DISPLAY_SHIFT_LEFT	0x18					//LCD Will shift to left
#define _LCD_MOVE_DISPLAY_SHIFT_RIGHT	0x1C					//LCD Will shift to right

//
#define _LCD_CGRAM_START				0x40					//Start Address of CGRAM
#define _LCD_DDRAM_START				0x80					//Start Address of DDRAM

#define _LCD_ROW1_START					_LCD_DDRAM_START		//Start Address of Row 1 in LCD 2*16
#define _LCD_ROW2_START					0xC0					//Start Address of Row 2 in LCD 2*16

//Function Set
// Here You must use | operator with either Feature you need to init it (4bit or 8bit) with (2line or 1line) with (5*7 or 5*10) (Recommended)
#define _LCD_4BIT_1LINE_7				0x20
#define _LCD_4BIT_MODE					_LCD_4BIT_1LINE_7	//LCD 4 Data width				  	(Recommended)
//#define _LCD_8BIT_MODE					0x30					//LCD 8 Data width
#define _LCD_1LINE						_LCD_4BIT_1LINE_7		//One line
#define _LCD_2LINE						0x28					//Two lines        				  	(Recommended)
#define _LCD_DOT_MATRIX_7				_LCD_4BIT_1LINE_7		//Custom char will be 5*7	CGRAM 	(Recommended)
#define _LCD_DOT_MATRIX_10				0X24					//Custom char will be 5*10  CGRAM


void LCD_voidInit(LCD_cofig *lcd);
void LCD_sendChar(LCD_cofig* lcd,u8 Data);
void LCD_sendCommand(LCD_cofig* lcd,u8 command);
void LCD_sendNumber(LCD_cofig* lcd,u32 num);
void LCD_sendString(LCD_cofig* lcd,u8* string );
void LCD_clear(LCD_cofig* lcd);
void LCD_setCursor(LCD_cofig* lcd,u8 row,u8 column);
#endif /* LCD_INT_H_ */
