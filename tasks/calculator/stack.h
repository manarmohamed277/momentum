//
// Created by user on 8/14/2024.
//

#ifndef INFIX_STACK_H
#define INFIX_STACK_H
typedef char entry_type;
#define MAX_SIZE 20
typedef struct {
    entry_type entry[20];
    int top;
}stack;

void creatStack(stack*sp);
void push(entry_type item,stack *sp);
int stackFull(stack* s);
int stackEmpty(stack* sp);
void pop(entry_type *item,stack*sp);
entry_type stackTop(stack*sp);
int stackSize(stack*sp);
void clearStack(stack*sp);
void display(entry_type sItem);
void traverseStack(stack*sp,void (*ptr)(entry_type));
void stackTopUser(entry_type * item,stack *sp);
void destroyStackUser(stack*sp);

#endif //INFIX_STACK_H
