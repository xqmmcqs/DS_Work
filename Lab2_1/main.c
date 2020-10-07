//
// Created by xqmmcqs on 2020/10/7.
//

#include <stdio.h>
#include "stack.h"

int main()
{
    Stack s1, s2;
    initStack(&s1);
    initStack(&s2);
    while (true)
    {
        char t = getchar();
        if (t == '#')break;
        pushStack(&s1, t - '0');
    }
    while (!isStackEmpty(s1))
    {
        int num = 0;
        for (int i = 0; !isStackEmpty(s1) && i < 3; ++i)
            num = num + (1 << i) * popStack(&s1);
        pushStack(&s2, num);
    }
    while (!isStackEmpty(s2))
        printf("%d", popStack(&s2));
    puts("");
    destroyStack(&s1);
    destroyStack(&s2);
    return 0;
}
