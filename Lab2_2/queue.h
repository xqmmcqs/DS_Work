//
// Created by xqmmcqs on 2020/10/7.
//

#ifndef LAB2_2_QUEUE_H
#define LAB2_2_QUEUE_H

#endif //LAB2_2_QUEUE_H

#include <stdbool.h>

#define QUEUEINCREASESIZE 100

typedef char ElemType;

typedef struct queue
{
    ElemType * front;
    ElemType * rear;
    ElemType * base;
    int queuesize;
} Queue;

void initQueue(Queue * q);

bool isQueueEmpty(Queue q);

void pushQueue(Queue * q, ElemType item);

ElemType popQueue(Queue * q);

void destroyQueue(Queue * q);

