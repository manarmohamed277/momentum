/*
 * BIT_SET.h
 *
 *  Created on: Feb 25, 2025
 *      Author: User
 */

#ifndef BIT_SET_H_
#define BIT_SET_H_



#define SET_BIT(PORT,BITNUM,BITVAL) (PORT|=(BITVAL<<BITNUM))
#define RESET_BIT(PORT,BITNUM) (PORT&=~(1<<BITNUM))
#define TOGGLE_BIT(PORT,BITNUM) (PORT^=(1<<BITNUM))
#define GET_BIT(PORT,BITNUM) ((PORT>>BITNUM)&1)


#endif /* BIT_SET_H_ */
