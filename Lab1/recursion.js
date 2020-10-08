function cal(n, x, y) {
    var res = 0;
    for (var i = 2; i <= n; i++)
    {
        res = (res + y) % i;
    }
    return (res + x - 1) % n + 1;
}
