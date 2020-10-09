//
// Created by xqmmcqs on 2020/9/30.
//

#include <stdio.h>
#include "list.h"

int main()
{
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    if (n <= 1 || x > n || y <= 0)
    {
        puts("Please check your input.");
        exit(1);
    }
    List list, now;
    initList(&list);
    now = list;
    for (int i = 1; i <= n; ++i) // 逐个添加元素
    {
        addNode(now, i);
        now = nextNode(now);
    }
    now = list;
    for (int i = 1; i < x; ++i) // 找到第x个元素的前驱
        now = nextNode(now);
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < y; ++j)
            now = nextNode(now);
        delNode(list, now);
    }
    printf("%d\n", now->item);
    destroyList(&list);
    return 0;
}
