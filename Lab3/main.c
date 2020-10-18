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
        for (int p1 = a.pos[i], p2 = b.pos[i]; p1 < a.pos[i + 1] && p2 < b.pos[i + 1]; ++i)
        {
            while (p2 < b.pos[i + 1] && b.data[p2].j < a.data[p1].j)
                ++p2;
            if (b.data[p2].j == a.data[p1].j)
                if (a.data[p1].val + b.data[p2].val)
                {
                    if (c.tot + 1 > c.sizeOfMatrix)
                        expandMatrix(&c);
                    c.data[++c.tot] = (Tuple){i, a.data[p1].j, a.data[p1].val + b.data[p2].val};
                }
        }
    }
    c.pos[c.n + 1] = c.tot;
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
    c.pos[c.n + 1] = c.tot;
    free(temp);
    return c;
}

int main()
{
    
}