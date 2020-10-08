function cal(n, x, y) {
    var res = 0;
    for (var i = 2; i <= n; i++) {
        res = (res + y) % i;
    }
    return (res + x - 1) % n + 1;
}


function getPoints(n) {
    var points = [];
    for (var x = 1; x <= n; x++) {
        for (var y = 1; y <= n; y++) {
            points.push({
                x: x,
                y: y,
                z: cal(n, x, y)
            });
        }
    }
    return points;
}
