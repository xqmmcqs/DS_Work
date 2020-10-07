//
// Created by xqmmcqs on 2020/10/7.
//

#include <string.h>
#include <stdlib.h>
#include "queue.h"

void initQueue(Queue * q)
{
    q->base = (ElemType *) malloc(QUEUEINCREASESIZE * sizeof(ElemType));
    if (!q->base)exit(1);
    q->front = q->rear = q->base;
    q->queuesize = QUEUEINCREASESIZE;
}

bool isQueueEmpty(Queue q)
{
    return q.front == q.rear;
}

void pushQueue(Queue * q, ElemType item)
{
    if (q->rear - q->base >= q->queuesize)
    {
        q->base = (ElemType *) realloc(q->base, (q->queuesize + QUEUEINCREASESIZE) * sizeof(ElemType));
        if (!q->base)exit(1);
        q->queuesize += QUEUEINCREASESIZE;
    }
    *(q->rear++) = item;
}

ElemType popQueue(Queue * q)
{
    if (q->front == q->rear)exit(1);
    return *(q->front++);
}

void destroyQueue(Queue * q)
{
    free(q->base);
    q->base = q->front = q->rear = NULL;
    q->queuesize = 0;
}
