//
// Created by xqmmcqs on 2020/11/2.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data;
    struct node *lc, *rc;
} Node;

Node *buildTree()
{
    char ch = getchar();
    if (ch == '*')
        return NULL;
    Node *point = (Node *)calloc(1, sizeof(Node));
    point->data = ch;
    point->lc = buildTree();
    point->rc = buildTree();
    return point;
}

void preorderTraverse(Node *point)
{
    printf("%c ", point->data);
    if (point->lc)
        printf("%c ", point->lc->data);
    else printf("*");
    if (point->rc)
        printf("%c ", point->rc->data);
    else printf("*");
    puts("");
    if (point->lc)
        preorderTraverse(point->lc);
    if (point->rc)
        preorderTraverse(point->rc);
}

void destroyTree(Node *point)
{
    if (point->lc)
        destroyTree(point->lc);
    if (point->rc)
        destroyTree(point->rc);
    free(point);
}

int main()
{
    Node *root = buildTree();
    puts("\n");
    puts("--------------------");
    puts("|** 选择程序功能 **|");
    puts("--------------------");
    puts("(1) 压缩");
    puts("(2) 解压");
    puts("");
    preorderTraverse(root);
    destroyTree(root);
    return 0;
}