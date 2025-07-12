/*
 * timer_prog.c
 *
 *  Created on: Mar 22, 2025
 *      Author: User
 */
#include"stdTypes.h"
#include "BIT_SET.h"
#include "errorState.h"
#include "timer_priv.h"
#include "timer_config.h"
#include "timer_int.h"



/********global vars**********/
u8 counter;
pointer_fun call_back_OV_F;
pointer_fun call_back_compare;
/****************************/
ES_ERROR timer0_init(timer_config* timer){
	ES_ERROR errorState=ES_NOK;
if(NULL==timer)
	errorState=ES_NULL_POINTER;
else{
	TCCR0|=timer->mode;
	TCCR0|=timer->clk;
	TIMSK|=timer->ctc_int;
	TIMSK|=timer->nor_int;
	errorState=ES_NOK;
}
	return errorState;
}

ES_ERROR timer0_stop(void){
	ES_ERROR errorState=ES_OK;
	TCCR0&=~(0x07);
	return errorState;
}

ES_ERROR timer0_set_compare_val(u8 comVal){
	ES_ERROR errorState=ES_OK;
OCR0=comVal;
		return errorState;
}

ES_ERROR timer0_get_compare_val(u8* comPVal){
	ES_ERROR errorState=ES_OK;
*comPVal=OCR0;
			return errorState;
}

ES_ERROR timer0_set_counter_val(u8 countVal){
	ES_ERROR errorState=ES_OK;
TCNT0=countVal;
			return errorState;
}

ES_ERROR timer0_get_counter_val(u8* countPVal){
	ES_ERROR errorState=ES_OK;
*countPVal=TCNT0;
			return errorState;
}

ES_ERROR timer0_set_OV_F_val(u8 OV_FVal){
	ES_ERROR errorState=ES_OK;
counter=OV_FVal;
			return errorState;
}

ES_ERROR timer0_get_OV_F_val(u8* OV_FPVal){
	ES_ERROR errorState=ES_OK;
	* OV_FPVal=counter;
			return errorState;
}
////////////////////////////////

ES_ERROR timer0_call_back_OV_F_INT(pointer_fun func){
	ES_ERROR errorState=ES_OK;
	call_back_OV_F=func;
			return errorState;
}

ES_ERROR timer0_call_back_compare_INT(pointer_fun func){
	ES_ERROR errorState=ES_OK;
	call_back_compare=func;
			return errorState;
}

//////////////////////////////


/*TIMER0 Normal Mode ISR*/
void __vector_11 (void)		__attribute__((signal)) ;
void __vector_11 (void)
{

	    counter++;
		call_back_OV_F() ;

}

/*TIMER0 CTC Mode ISR*/
void __vector_10 (void)		__attribute__((signal)) ;
void __vector_10 (void)
{
	call_back_compare();
}














