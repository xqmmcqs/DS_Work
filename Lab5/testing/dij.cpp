#include <bits/stdc++.h>
#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef double db;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    return x * f;
}

const int MAXN = 1e5 + 10, MAXM = 2e6 + 10,INF=2147483647;
int n, m, head[MAXN], cnt, dis[MAXN], ind[MAXN];
struct edge
{
    int v, next, val;
} e[MAXM];

void addedge(int x, int y, int z)
{
    e[++cnt] = (edge){y, head[x], z};
    head[x] = cnt;
    return;
}

void dijkstra()
{
    priority_queue<pair<int, int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    dis[0] = 0;
    for (int i = 1; i <= n; ++i)
        dis[i] = INF;
    q.push(make_pair(0, 0));
    while (!q.empty())
    {
        int u = q.top().sec;
        q.pop();
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].v;
            if (dis[v] > dis[u] + e[i].val)
            {
                dis[v] = dis[u] + e[i].val;
                q.push(make_pair(dis[v], v));
            }
        }
    }
}

int main()
{
    n = read();
    m = read();
    for (int i = 1; i <= m; ++i)
    {
        int x = read(), y = read(), z = read();
        addedge(x, y, z);
        ++ind[y];
    }
    for (int i = 1; i <= n; ++i)
        if (!ind[i])
            addedge(0, i, 0);
    dijkstra();
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (dis[i] > ans)
            ans = dis[i];
    printf("%d\n", ans);
    return 0;
}
