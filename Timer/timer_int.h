/*
 * timer_int.h
 *
 *  Created on: Mar 22, 2025
 *      Author: User
 */

#ifndef TIMER_INT_H_
#define TIMER_INT_H_

typedef void(*pointer_fun)(void);


ES_ERROR timer0_init(timer_config* timer);
ES_ERROR timer0_stop(void);
ES_ERROR timer0_set_compare_val(u8 comVal);
ES_ERROR timer0_get_compare_val(u8* comPVal);
ES_ERROR timer0_set_counter_val(u8 countVal);
ES_ERROR timer0_get_counter_val(u8* countPVal);
ES_ERROR timer0_set_OV_F_val(u8 OV_FVal);
ES_ERROR timer0_get_OV_F_val(u8* OV_FPVal);
ES_ERROR timer0_call_back_OV_F_INT(pointer_fun func);
ES_ERROR timer0_call_back_compare_INT(pointer_fun func);

#endif /* TIMER_INT_H_ */
