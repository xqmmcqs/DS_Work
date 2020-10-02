//
// Created by xqmmcqs on 2020/9/30.
//

#ifndef DS_WORK_LIST_H
#define DS_WORK_LIST_H

#endif //DS_WORK_LIST_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef int Item;

typedef struct node
{
    Item item;
    struct Node * next;
} Node;

typedef Node * List;

void initList(List * plist);

bool isEmpty(const List list);

bool AddItem(List pnode, Item item);

void delItem(List list, List pnode);

List nextItem(const List pnode);

void destroyList(List * plist);
