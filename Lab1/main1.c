#include <stdio.h>

int main()
{
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    int ans = 0;
    for (int i = 2; i <= n; ++i)
        ans = (ans + y) % i;
    printf("%d\n", (ans + x - 1) % n + 1);
    return 0;
}