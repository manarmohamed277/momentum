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
}pin_conf;


typedef struct{
	pin_conf rowsPins[4];
	pin_conf columnsPins[4];
}kp_conf;

u8 KP_u8GetPressedKey(kp_conf* keypad);
void KP_u8KeyPadInit(kp_conf* keypad);

#endif /* HAL_KEYPAD_KP_INIT_H_ */
