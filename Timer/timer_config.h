/*
 * timer_config.h
 *
 *  Created on: Mar 22, 2025
 *      Author: User
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_
#define SREG			*((volatile u8*) 0X5F)
typedef enum{
	normal,
	ctc=0x08
}timer_mode;

/////////////////////////////

typedef enum{
	 No_clock_source,
	 No_prescaling,
	 prescaler_8,
	 prescaler_64,
	 prescaler_256,
	 prescaler_1024,
	 External_clock_source_T0_falling_edge,
	 External_clock_source_T0_rising_edge,
}prescaler_modes;

/////////////////////////////
typedef enum{
	disconnected,
	toggle,
	set,
	clear
}compare_match_action;

/////////////////////

typedef enum{
	normal_INT_disable,
	normal_INT_enable
}normal_INT;
/////////////////////
typedef enum{
	ctc_INT_disable,
	ctc_INT_enable=2
}ctc_INT;

/////////////////////////

typedef struct{
	timer_mode mode;
	prescaler_modes clk;
	normal_INT nor_int;
	ctc_INT ctc_int;
}timer_config;
#endif /* TIMER_CONFIG_H_ */
