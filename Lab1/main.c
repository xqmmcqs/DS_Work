//
// Created by xqmmcqs on 2020/9/30.
//

#include <stdio.h>
#include "list.h"

int main()
{
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    List list, now;
    initList(&list);
    now = list;
    for (int i = 1; i <= n; ++i) // 逐个添加元素
    {
        AddItem(now, i);
        now = nextItem(now);
    }
    now = list;
    for (int i = 1; i < x; ++i) // 找到第x个元素
        now = nextItem(now);
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < y; ++j)
            now = nextItem(now);
        delItem(list, now);
    }
    printf("%d\n", now->item);
    destroyList(&list);
    return 0;
}
