//
// Created by xqmmcqs on 2020/11/30.
//

#include <stdlib.h>
#include "graph.h"

int n, m;
int * ind, * dist, * par;
Edge ** firstEdge;
const int INF = 2147483647;

// 初始化有向无环图
void initGraph()
{
    if (!(firstEdge = (Edge **) calloc(n, sizeof(Edge *))))
        exit(1);
    if (!(dist = (int *) calloc(n, sizeof(int *))))
        exit(1);
    if (!(ind = (int *) calloc(n, sizeof(int))))
        exit(1);
    if (!(par = (int *) calloc(n, sizeof(int))))
        exit(1);
}

// 向图中加入弧
void addEdge(int u, int v, int val)
{
    Edge * temp;
    if (!(temp = (Edge *) calloc(1, sizeof(Edge))))
        exit(1);
    temp->val = val;
    temp->v = v;
    temp->next = firstEdge[u];
    firstEdge[u] = temp;
    ++ind[v];
}

// 有向无环图的拓扑排序，求出dist和par数组的值
void topologicalSort()
{
    int * stac, tot = -1;
    if (!(stac = (int *) calloc(n, sizeof(int *))))
        exit(1);
    for (int i = 0; i < n; ++i)
    {
        if (!ind[i])
        {
            stac[++tot] = i;
            par[i] = -1;
            dist[i] = 0;
        }
        else dist[i] = INF;
    }
    while (~tot)
    {
        int u = stac[tot--];
        for (Edge * i = firstEdge[u]; i; i = i->next)
        {
            int v = i->v;
            if (dist[u] + i->val < dist[v])
            {
                dist[v] = dist[u] + i->val;
                par[v] = u;
            }
            --ind[v];
            if (!ind[v])
                stac[++tot] = v;
        }
    }
    free(stac);
}

// 释放有向无环图的空间
void destroyGraph()
{
    for (int u = 0; u < n; ++u)
        for (Edge * i = firstEdge[u], * t; i; t = i, i = i->next, free(t));
    free(firstEdge);
    free(dist);
    free(ind);
    free(par);
}