//
// Created by xqmmcqs on 2020/9/30.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void initList(List * plist)
{
    *plist = (List) malloc(sizeof(Node));
    (*plist)->item = 0;
    (*plist)->next = *plist;
}

bool isEmpty(const List list)
{
    return list->next == list;
}

bool AddItem(List pnode, Item item)
{
    List newNode = (List) malloc(sizeof(Node));
    if (newNode == NULL)
        return false;
    memcpy(&(newNode->item), &item, sizeof(item));
    newNode->next = pnode->next;
    pnode->next = newNode;
    return true;
}

void delItem(List list, List pnode)
{
    List delNode = pnode->next;
    if (delNode == list)
        pnode = delNode, delNode = delNode->next;
    pnode->next = delNode->next;
    printf("%d ", delNode->item);
    free(delNode);
}

List nextItem(const List pnode)
{
    List nItem = pnode->next;
    if (nItem->item == 0)
        nItem = nItem->next;
    return nItem;
}

void destroyList(List * plist)
{
    while (!isEmpty(*plist))
        delItem(*plist, *plist);
    free(*plist);
    *plist = NULL;
}
