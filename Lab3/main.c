//
// Created by xqmmcqs on 2020/10/18.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MATRIXINCREASESIZE = 1000;

typedef struct
{
    int i, j, val;
} Tuple;

typedef struct
{
    Tuple *data;
    int *pos;
    int n, m, tot;
    int sizeOfMatrix;
} Matrix;

void initMatrix(Matrix *a, int n, int m)
{
    a->n = n;
    a->m = m;
    a->tot = 0;
    if (!(a->pos = (int *)calloc(n + 2, sizeof(int))))
        exit(1);
    a->sizeOfMatrix = MATRIXINCREASESIZE;
    if (!(a->data = (Tuple *)calloc(MATRIXINCREASESIZE, sizeof(Tuple))))
        exit(1);
}

void expandMatrix(Matrix *c)
{
    if (!(c->data = (Tuple *)realloc(c->data, (c->sizeOfMatrix + MATRIXINCREASESIZE) * sizeof(Tuple))))
        exit(1);
    c->sizeOfMatrix += MATRIXINCREASESIZE;
}

Matrix array2Matrix(int n, int m, int val[])
{
    Matrix a;
    initMatrix(&a, n, m);
    for (int i = 1; i <= n; ++i)
    {
        a.pos[i] = a.tot + 1;
        for (int j = 1; j <= m; ++j)
        {
            if (val[(i - 1) * m + j])
            {
                if (a.tot + 1 > a.sizeOfMatrix)
                    expandMatrix(&a);
                a.data[++a.tot] = (Tuple){i, j, val[(i - 1) * m + j]};
            }
        }
    }
    a.pos[n + 1] = a.tot + 1;
    return a;
}

Matrix addMatrix(Matrix a, Matrix b)
{
    if (a.n != b.n || a.m != b.m)
        exit(1);
    Matrix c;
    initMatrix(&c, a.n, b.m);
    if (!a.tot || !b.tot)
        return c;
    for (int i = 1; i <= a.n; ++i)
    {
        c.pos[i] = c.tot + 1;
        int p1 = a.pos[i], p2 = b.pos[i];
        while (p1 < a.pos[i + 1] || p2 < b.pos[i + 1])
        {
            int tempj, tempv;
            if (p2 >= b.pos[i + 1] || p1 < a.pos[i + 1] && a.data[p1].j < b.data[p2].j)
            {
                tempj = a.data[p1].j;
                tempv = a.data[p1].val;
                ++p1;
            }
            else if (p1 >= a.pos[i + 1] || p2 < b.pos[i + 1] && a.data[p1].j > b.data[p2].j)
            {
                tempj = b.data[p2].j;
                tempv = b.data[p2].val;
                ++p2;
            }
            else
            {
                tempj = a.data[p1].j;
                tempv = a.data[p1].val + b.data[p2].val;
                ++p1;
                ++p2;
            }
            if (tempv)
            {
                if (c.tot + 1 > c.sizeOfMatrix)
                    expandMatrix(&c);
                c.data[++c.tot] = (Tuple){i, tempj, tempv};
            }
        }
    }
    c.pos[c.n + 1] = c.tot + 1;
    // for (int i = 1; i <= c.tot; ++i)
    // printf("%d %d %d\n", c.data[i].i, c.data[i].j, c.data[i].val);
    return c;
}

Matrix mulMatrix(Matrix a, Matrix b)
{
    if (a.m != b.n)
        exit(1);
    Matrix c;
    initMatrix(&c, a.n, b.m);
    if (!a.tot || !b.tot)
        return c;
    int *temp = (int *)calloc(a.m + 1, sizeof(int));
    for (int i = 1; i <= a.n; ++i)
    {
        memset(temp, 0, (a.m + 1) * sizeof(int));
        c.pos[i] = c.tot + 1;
        for (int p = a.pos[i]; p < a.pos[i + 1]; ++p)
        {
            int k = a.data[p].j;
            for (int q = b.pos[k]; q < b.pos[k + 1]; ++q)
            {
                int j = b.data[q].j;
                temp[j] += a.data[p].val * b.data[q].val;
            }
        }
        for (int j = 1; j <= a.m; ++j)
        {
            if (!temp[j])
                continue;
            if (c.tot + 1 > c.sizeOfMatrix)
                expandMatrix(&c);
            c.data[++c.tot] = (Tuple){i, j, temp[j]};
        }
    }
    c.pos[c.n + 1] = c.tot + 1;
    free(temp);
    return c;
}

void matrix2Array(Matrix a, int *val)
{
    memset(val, 0, sizeof(int) * (a.n * a.m + 1));
    for (int i = 1; i <= a.tot; ++i)
        val[(a.data[i].i - 1) * a.m + a.data[i].j] = a.data[i].val;
}

void destroyMatrix(Matrix *a)
{
    free(a->pos);
    free(a->data);
    a->n = a->m = a->tot = a->sizeOfMatrix = 0;
}

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
        puts("Cannot add matrix A and B");
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
        puts("Cannot multiply matrix A and B");
    destroyMatrix(&a);
    destroyMatrix(&b);
    return 0;
}