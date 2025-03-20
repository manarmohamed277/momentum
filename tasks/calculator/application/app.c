/*
 * app.c
 *
 *  Created on: Nov 26, 2024
 *      Author: User
 */
#include "../stdTypes.h"
#include<util/delay.h>
#include"../errorState.h"
#include"../MCAL/DIO_int.h"
#include"../HAL/KEYPAD_int.h"
#include"../HAL/LCD_int.h"
#include "../eval.h"

int size=0;
void arrToNum(u8*ptr1,u8 n1);
void app(){

DIO_enuInit();
LCD_enuInit();
 KEYPAD_Init();
/*enter pass*/
u8 kp_pass= KP_NO_PRESSED_KEY; u8 pass_nums=0;
u8 pass_nums_arr[16];
u8 pass_ch_nums_arr[16];
//LCD_enuDisplayStringPOS("enter password",1,2);

//STAY HERE UNTIL THE KET GET PRESSED
/* while(1){
do{
	 kp_pass=KEYPAD_enuGetpressedKey();
}while(kp_pass== KP_NO_PRESSED_KEY);
if(kp_pass=='$') break;
pass_nums_arr[pass_nums++]=kp_pass;
LCD_enuDisplayNumPOS(kp_pass,2,pass_nums);
_delay_ms(100);
LCD_enuDisplayCharPOS('*',2,pass_nums);
_delay_ms(100);

}
LCD_enuClear();
//take password again to check
u8 count=0;
LCD_enuDisplayStringPOS("ensure password",1,2);

while(1){
do{
	 kp_pass=KEYPAD_enuGetpressedKey();
}while(kp_pass== KP_NO_PRESSED_KEY);
if(kp_pass=='$') break;
pass_ch_nums_arr[count++]=kp_pass;
LCD_enuDisplayNumPOS(kp_pass,2,count);
_delay_ms(100);
LCD_enuDisplayCharPOS('*',2,count);
}
_delay_ms(100);
LCD_enuClear();
 //check if pass is correct

int flag=1;
for(u8 i=0;i<pass_nums;i++){
	if(pass_ch_nums_arr[i]!=pass_nums_arr[i]){
		flag=0;
		break;}
}

//display loading

	LCD_enuDisplayStringPOS("loading",1,2);
for(int i=0;i<3;i++){

	_delay_ms(350);
	LCD_enuDisplayCharPOS('.',1,(i+9));
}

//PASS correct  enter calculator

if(flag){
	_delay_ms(500);
	LCD_enuClear();
	_delay_ms(500);*/
	LCD_enuDisplayStringPOS("WELCOME",1,5);
	_delay_ms(600);
	LCD_enuClear();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//working
while(1){//flag


	// taking the first number
while(1){
	u8 kpVal;
		u8 infix[10];
		u8 i=0;

		u8 size=0;
		u8 *post;
		u8 res=9;
do{
	kpVal=KEYPAD_enuGetpressedKey();
}while(kpVal== KP_NO_PRESSED_KEY);

infix[i++]=kpVal;
size++;
if(kpVal=='+'||kpVal=='x'||kpVal=='-'||kpVal=='%')
	LCD_enuDisplayChar(kpVal);
else if(kpVal!='$'&&kpVal!='=')
LCD_enuDisplayNum(kpVal);
 if(kpVal=='$')
{
     LCD_enuClear();
     break ;
}

if(kpVal=='='){
	//LCD_enuDisplayCharPOS('m',2,6);
	infix[i] = '\0';
post=intoPost(infix,size);
res=evaluate(post);
LCD_enuDisplayNumPOS(res,2,11);
free(post);
break;
}


}






}




}

// taking the second number




/*void arrToNum(u8*ptr1,u8 n1)
{
	int num=ptr1[0];


	for(int i=1;i<n1;i++)
	{
		num=num * 10 + ptr1[i];
	}

	*infixExp=num;
    infixExp++;
    size++;
}
*/
/*void eval(u8*infix){

/*	u32 sum , sub , mul , div ;

	//LCD_enuDisplayNumPOS(num1,2,2);
	//LCD_enuDisplayNumPOS(num2,2,6);

	switch(operation)
	{
	    case '+':
	    	      {
	    	    	  sum=num1+num2;
	    	    	  LCD_enuDisplayNumPOS(sum,2,12);
	    	    	  break;
	    	      }
	    case '-':{   if(num1<num2){
                     sub=num2-num1;
                     LCD_enuDisplayCharPOS('-',2,11);
                     LCD_enuDisplayNumPOS(sub,2,12);
                     break;
	                                  }
	             	sub=num1-num2;
	    	        LCD_enuDisplayNumPOS(sub,2,12);
	    	        break;
	    }
	    case 'x': {
	            	mul=num1*num2;
	    	        LCD_enuDisplayNumPOS(mul,2,10);
	    	        break;
	    }
	    case '%': { if(num2==0)
	                   {
	    	                 LCD_enuClear();
	    	                 LCD_enuDisplayStringPOS("ERROR1",1,3);
	    	                 break;
	                   }

	               div=num1/num2;
	    	       LCD_enuDisplayNumPOS(div,2,10);
	    	       break;
	    }
	}*/



