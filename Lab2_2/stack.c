//
// Created by xqmmcqs on 2020/10/7.
//

#include <string.h>
#include <stdlib.h>
#include "stack.h"

void initStack(Stack * s)
{
    s->base = (ElemType *) malloc(STACKINCREASESIZE * sizeof(ElemType));
    if (!s->base)exit(1);
    s->top = s->base;
    s->stacksize = STACKINCREASESIZE;
}

bool isStackEmpty(Stack s)
{
    return s.base == s.top;
}

void pushStack(Stack * s, ElemType item)
{
    if (s->top - s->base >= s->stacksize)
    {
        s->base = (ElemType *) realloc(s->base, (s->stacksize + STACKINCREASESIZE) * sizeof(ElemType));
        if (!s->base)exit(1);
        s->stacksize += STACKINCREASESIZE;
    }
    *(s->top++) = item;
}

ElemType popStack(Stack * s)
{
    if (s->base == s->top)exit(1);
    return *(--s->top);
}

void destroyStack(Stack * s)
{
    free(s->base);
    s->base = s->top = NULL;
    s->stacksize = 0;
}

