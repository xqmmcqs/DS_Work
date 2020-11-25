//
// Created by xqmmcqs on 2020/11/2.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarytree.h"

int numOfSpecNodes;

// 建二叉树
Node * buildTree()
{
    char ch = getchar();
    if (ch == '*')
        return NULL;
    Node * point = (Node *) calloc(1, sizeof(Node));
    point->data = ch;
    if (point->lc = buildTree())
        point->pos += point->lc->pos;
    else
        point->pos += (numOfSpecNodes++) * 8 + 1;
    if (point->rc = buildTree())
        point->pos += point->rc->pos;
    else if (point->lc)
        point->pos += (numOfSpecNodes++) * 8 + 1;
    if (point->lc || point->rc)
        point->pos /= 2;
    return point;
}

// 先序遍历
void preOrderTraverse(Node * point)
{
    printf("%c ", point->data);
    if (point->lc)
        preOrderTraverse(point->lc);
    if (point->rc)
        preOrderTraverse(point->rc);
}

// 中序遍历
void inOrderTraverse(Node * point)
{
    if (point->lc)
        inOrderTraverse(point->lc);
    printf("%c ", point->data);
    if (point->rc)
        inOrderTraverse(point->rc);
}

// 后序遍历
void postOrderTraverse(Node * point)
{
    if (point->lc)
        postOrderTraverse(point->lc);
    if (point->rc)
        postOrderTraverse(point->rc);
    printf("%c ", point->data);
}

// 输出二叉树图形
void printGraph(Node * point)
{
    Node * que[100];
    int h = 1, t = 1;
    que[1] = point;
    while (h <= t)
    {
        int cur = 1;
        for (int k = h; k <= t; ++k)
        {
            while (cur < que[k]->pos)
            {
                putchar(' ');
                ++cur;
            }
            putchar(que[k]->data);
            ++cur;
        }
        puts("");
        cur = 1;
        for (int k = h; k <= t; ++k)
        {
            if (que[k]->lc)
            {
                while (cur < que[k]->lc->pos + 2)
                {
                    putchar(' ');
                    ++cur;
                }
                while (cur < que[k]->pos - 1)
                {
                    putchar('_');
                    ++cur;
                }
                putchar('/');
                ++cur;
            }
            if (que[k]->rc)
            {
                while (cur < que[k]->pos + 1)
                {
                    putchar(' ');
                    ++cur;
                }
                putchar('\\');
                ++cur;
                while (cur < que[k]->rc->pos - 1)
                {
                    putchar('_');
                    ++cur;
                }
            }
        }
        puts("");
        int ed = t;
        cur = 1;
        for (int k = h; k <= ed; ++k)
        {
            if (que[k]->lc)
            {
                while (cur < que[k]->lc->pos + 1)
                {
                    putchar(' ');
                    ++cur;
                }
                putchar('/');
                ++cur;
            }
            if (que[k]->rc)
            {
                while (cur < que[k]->rc->pos - 1)
                {
                    putchar(' ');
                    ++cur;
                }
                putchar('\\');
                ++cur;
            }
            if (que[k]->lc)
                que[++t] = que[k]->lc;
            if (que[k]->rc)
                que[++t] = que[k]->rc;
            ++h;
        }
        puts("");
    }
}

// 释放二叉树空间
void destroyTree(Node * point)
{
    if (point->lc)
        destroyTree(point->lc);
    if (point->rc)
        destroyTree(point->rc);
    free(point);
}
