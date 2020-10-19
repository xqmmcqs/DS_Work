#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a[5010][5010], b[5010][5010], na, ma, nb, mb;

int main()
{
    scanf("%d%d", &na, &ma);
    for (int i = 1; i <= na; ++i)
        for (int j = 1; j <= ma; ++j)
            scanf("%d", &a[i][j]);
    scanf("%d%d", &nb, &mb);
    for (int i = 1; i <= nb; ++i)
        for (int j = 1; j <= mb; ++j)
            scanf("%d", &b[i][j]);
    if (na == nb && ma == mb)
    {
        for (int i = 1; i <= na; ++i)
        {
            for (int j = 1; j <= ma; ++j)
                printf("%d ", a[i][j] + b[i][j]);
            puts("");
        }
    }
    else
        puts("Cannot add matrix A and B");
    if (ma == nb)
    {
        for (int i = 1; i <= na; ++i)
        {
            for (int j = 1; j <= mb; ++j)
            {
                int c = 0;
                for (int k = 1; k <= nb; ++k)
                {
                    c += a[i][k] * b[k][j];
                }
                printf("%d ", c);
            }
            puts("");
        }
    }
    else
        puts("Cannot multiply matrix A and B");
    return 0;
}