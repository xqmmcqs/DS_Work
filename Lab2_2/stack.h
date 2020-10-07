//
// Created by xqmmcqs on 2020/10/7.
//

#ifndef LAB2_2_STACK_H
#define LAB2_2_STACK_H

#endif //LAB2_2_STACK_H

#include <stdbool.h>

#define STACKINCREASESIZE 100

typedef char ElemType;

typedef struct stack
{
    ElemType * top;
    ElemType * base;
    int stacksize;
} Stack;

void initStack(Stack * s);

bool isStackEmpty(Stack s);

void pushStack(Stack * s, ElemType item);

ElemType popStack(Stack * s);

void destroyStack(Stack * s);
