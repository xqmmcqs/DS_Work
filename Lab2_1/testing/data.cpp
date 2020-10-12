#include <bits/stdc++.h>

using namespace std;

const int LEN = 1e4;

int main()
{
    srand(time(0));
    int n = rand() % LEN + 1;
    for (int i = 1; i <= n; ++i)
        printf("%d", rand() % 2);
    puts("#");
    return 0;
}
