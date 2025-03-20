//
// Created by user on 8/14/2024.
//
#include <stdio.h>
#include "stdTypes.h"
#include "stack.h"
#include "string.h"
void creatStack(stack*sp){
    sp->top=0;
}
void push(entry_type item, stack *sp){
    sp->entry[sp->top++]=item;
}
int stackFull(stack* s){
    return s->top==MAX_SIZE;
}

int stackEmpty(stack* sp){
    //  return sp->top==0;
    return !sp->top;
}

void pop(entry_type *item, stack*sp){
    //sp->top--;
    *item=sp->entry[--sp->top];
}

entry_type stackTop(stack*sp){
    return sp->entry[sp->top-1] ;
}

int stackSize(stack*sp){
    return sp->top;

}

void clearStack(stack*sp){
    sp->top=0;
}

void display(entry_type sItem){
    printf("%d\n",sItem);
}

void traverseStack(stack*sp,void (*ptr)(entry_type)){
    for(int i=sp->top; i > 0; i--)
        (*ptr)(sp->entry[i-1]);
}


void stackTopUser(entry_type * item, stack *sp){
    pop(item,sp);
    push(*item,sp);
}
void destroyStackUser(stack*sp){
    creatStack(sp);
}
////////////////////////////////////////////////////////////////////////////

