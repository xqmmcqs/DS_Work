//
// Created by xqmmcqs on 2020/10/18.
//

#include <stdio.h>
#include "matrix.h"

int val[5010 * 5010];

int main()
{
    int n, m, cnt = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &val[++cnt]);
    Matrix a = array2Matrix(n, m, val);
    cnt = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &val[++cnt]);
    Matrix b = array2Matrix(n, m, val);
    if (a.n == b.n && a.m == b.m)
    {
        Matrix c = addMatrix(a, b);
        matrix2Array(c, val);
        cnt = 0;
        for (int i = 1; i <= c.n; ++i)
        {
            for (int j = 1; j <= c.m; ++j)
                printf("%d ", val[++cnt]);
            putchar('\n');
        }
        destroyMatrix(&c);
    }
    else
    {
        printf("Cannot add matrix A and B");
        if(a.n != b.n)
            printf(", An != Bn");
        if(a.m != b.m)
            printf(", Am != Bm");
        puts(".");
    }
    if (a.m == b.n)
    {
        Matrix c = mulMatrix(a, b);
        matrix2Array(c, val);
        cnt = 0;
        for (int i = 1; i <= c.n; ++i)
        {
            for (int j = 1; j <= c.m; ++j)
                printf("%d ", val[++cnt]);
            putchar('\n');
        }
        destroyMatrix(&c);
    }
    else
        puts("Cannot multiply matrix A and B, Am != Bn.");
    destroyMatrix(&a);
    destroyMatrix(&b);
    return 0;
}