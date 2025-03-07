/*
 * KP_init.h
 *
 *  Created on: Mar 7, 2025
 *      Author: User
 */

#ifndef HAL_KEYPAD_KP_INIT_H_
#define HAL_KEYPAD_KP_INIT_H_


typedef struct{
u8 pin;
u8 port;
}pin_cofig;


typedef struct{
	pin_cofig rowsPins[4];
	pin_cofig columnsPins[4];
}kp_cofig;

u8 KP_u8GetPressedKey(kp_cofig* keypad);

#endif /* HAL_KEYPAD_KP_INIT_H_ */
