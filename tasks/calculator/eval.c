/*
 * eval.c
 *
 *  Created on: Mar 19, 2025
 *      Author: User
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"
#include"string.h"
#include "stdTypes.h"
int pre(u8 i){
    if (i=='+'|| i=='-' )
        return 1;
    else if (i=='*'||i=='/')
        return 2;
    else
        return 0;
}

int isOperand (u8 i){
    if(i=='+'||i=='-'||i=='*'||i=='/')
        return 0;
        else
        return 1;

}

u8 * intoPost(u8 infix[],u8 size) {

    u8 *postfix = (u8 *) malloc(size*sizeof(u8)+9);

    u8 i = 0, j = 0;
    stack st;
    creatStack(&st);
 //   push('\0',&st);
    while (infix[i]!='\0') {
        if (isOperand(infix[i])){
        	while(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        	 postfix[j++] =' ';
        	 //i++;
        }
        else
        	while(!stackEmpty(&st)&&pre(infix[i]) <= pre(stackTop(&st)))
        		pop(&postfix[j++], &st);


        	 push(infix[i++], &st);

    }


    while (!stackEmpty(&st)) {
        pop(&postfix[j++], &st);
    }
    postfix[j]='\0';

    return postfix;
}



u8 evaluate(u8* postfix) {  //
    stack eval;
    creatStack(&eval);
    u8 sum=0;
    u8 num=0;
   // LCD_enuDisplayStringPOS("evtfix:",2,1);
    while(*postfix) {
        if (*postfix == '*' || *postfix == '%' || *postfix == '+' || *postfix == '-') {
            int op1, op2;
            pop(&op2, &eval);
            pop(&op1, &eval);

            switch (*postfix) {
                case '+': sum = op1 + op2; break;
                case '-': sum = op1 - op2; break;
                case '*': sum = op1 * op2; break;
                case '%': sum = op1 / op2; break;
            }
            push(sum, &eval);
            postfix++;
        }
        else if (*postfix >= '0' && *postfix <= '9') {
            num = 0;
        	while(*postfix>='0'&&*postfix<='9'){

           num=num*10+*(postfix)-'0';
           postfix++;
        }
            push(num, &eval);
        }
        else //=' '
        postfix++;
    }
    return stackTop(&eval);
}

/*int precedence(u8 op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '%')
        return 2;
    return 0;
}

int isOperand(u8 ch) {
    return (ch >= '0' && ch <= '9');
}

u8* intoPost(u8 infix[], u8 size) {
    u8* postfix = (u8*) malloc(size * sizeof(u8) + 20);
    u8 i = 0, j = 0;
    stack st;
    creatStack(&st);

    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            while (isOperand(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
        }
        else {
            while (!stackEmpty(&st) && precedence(infix[i]) <= precedence(stackTop(&st))) {
                pop(&postfix[j++], &st);
            }
            push(infix[i++], &st);
        }
    }
    while (!stackEmpty(&st)) {
        pop(&postfix[j++], &st);
    }
    postfix[j] = '\0';

    return postfix;
}

u8 evaluate(u8* postfix) {
    stack eval;
    creatStack(&eval);
    u8 sum = 0;
    u8 num = 0;

    while (*postfix) {
        if (*postfix == '+' || *postfix == '-' || *postfix == '*' || *postfix == '%') {
            int op1, op2;
            pop(&op2, &eval);
            pop(&op1, &eval);

            LCD_enuDisplayStringPOS("Op1:", 2, 1);
           // LCD_enuDisplayNumPOS(op1, 2, 5);
           // LCD_enuDisplayStringPOS("Op2:", 2, 3);
            //LCD_enuDisplayNumPOS(op2, 2, 6);

            switch (*postfix) {
                case '+': sum = op1 + op2; break;
                case '-': sum = op1 - op2; break;
                case '*': sum = op1 * op2; break;
                case '%':
                    if (op2 == 0) {
                        printf("ERROR: Division by zero\n");
                        return 0;
                    }
                    sum = op1 / op2;
                    break;
            }
            push(sum, &eval);
            postfix++;
        } else if (isOperand(*postfix)) {
            num = 0;
            while (isOperand(*postfix)) {
                num = num * 10 + *postfix - '0';
                postfix++;
            }
            push(num, &eval);
        }
        postfix++;
    }

   // LCD_enuDisplayNumPOS(num,2,3);
    return stackTop(&eval);
}*/
/*int precedence(u8 op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '%') return 2;
    return 0;
}

int isOperand(u8 ch) {
    return (ch >= '0' && ch <= '9');
}

u8* intoPost(u8 infix[], u8 size) {
    u8* postfix = (u8*) malloc(size * sizeof(u8) + 1);
    u8 i = 0, j = 0;
    stack st;
    creatStack(&st);

    while (i < size) {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '%') {
            while (!stackEmpty(&st) && precedence(stackTop(&st)) >= precedence(infix[i])) {
                pop(&postfix[j++], &st);
            }
            push(infix[i], &st);
        }
        i++;
    }
    while (!stackEmpty(&st)) {
        pop(&postfix[j++], &st);
    }
    postfix[j] = '\0';
    return postfix;
}

u8 evaluate(u8* postfix) {
    stack eval;
    creatStack(&eval);
    u8 sum = 0;

    while (*postfix) {
        if (isOperand(*postfix)) {
            push(*postfix - '0', &eval);
        } else {
            int op2, op1;
            pop(&op2, &eval);
            pop(&op1, &eval);

            switch (*postfix) {
                case '+': sum = op1 + op2; break;
                case '-': sum = op1 - op2; break;
                case '*': sum = op1 * op2; break;
                case '%': sum = op1 / op2; break;
            }
            push(sum, &eval);
        }
        postfix++;
    }
    return stackTop(&eval);
}

*/


