//
// Created by xqmmcqs on 2020/11/27.
//

#include <stdio.h>
#include "graph.h"

int main()
{
    scanf("%d%d", &n, &m);
    if (n <= 1)
    {
        puts("There should be at least two points!");
        return 0;
    }
    if (m <= 0)
    {
        puts("No solution.");
        return 0;
    }
    initGraph();
    for (int i = 1; i <= m; ++i)
    {
        int u, v, val;
        scanf("%d%d%d", &u, &v, &val);
        if (u < 1 || u > n || v < 1 || v > n || val <= 0 || u == v)
        {
            puts("Invalid input.");
            return 0;
        }
        u--;
        v--;
        addEdge(u, v, val);
    }
    topologicalSort();
    int ans1 = -1, ans2;
    for (int i = 0; i < n; ++i)
        if (dist[i] > ans1)
        {
            ans1 = dist[i];
            ans2 = i;
        }
    int u = ans2;
    while (~par[u])u = par[u];
//    printf("%d\n", ans1);
    printf("%d %d %d\n", ans1, u + 1, ans2 + 1);
    destroyGraph();
    return 0;
}
