/*
 * main.c
 *
 *  Created on: Mar 22, 2025
 *      Author: User
 */
#include "BIT_SET.h"
#include "stdTypes.h"
#include "errorState.h"
#include "MCAL/DIO_cofig.h"
#include "MCAL/DIO_int.h"
#include "errorState.h"
#include "timer_config.h"
#include "timer_int.h"

void ISR_func(void){
	DIO_enutogport(DIO_u8PORTA);
}




int main(void){
	 DIO_enuSetportdir(DIO_u8PORTA,0xff);

	 DIO_enuSetportval(DIO_u8PORTA,0xff);
	 DIO_enuSetpinval(DIO_u8PORTA,DIO_u8PIN0,1);
	 DIO_enuSetportdir(DIO_u8PORTC,0xff);

	 DIO_enuSetportval(DIO_u8PORTC,0xff);
	 SET_BIT(SREG,7);
	timer_config timer={ctc,prescaler_256,normal_INT_disable,ctc_INT_enable};
	timer0_call_back_compare_INT(ISR_func);
	timer0_set_compare_val(0xfB);
	timer0_init(&timer);

	while(1){
		 DIO_enuSetpinval(DIO_u8PORTA,DIO_u8PIN0,1);
	}
	return 1;
}

