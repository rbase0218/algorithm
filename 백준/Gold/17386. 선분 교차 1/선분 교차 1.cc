#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

#define ll long long

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll res = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (res > 0) return 1;
    if (res < 0) return -1;
    return 0;
}

int main() {
    ll x1, y1, x2, y2;
    ll x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    ll ab1 = ccw(x1, y1, x2, y2, x3, y3);
    ll ab2 = ccw(x1, y1, x2, y2, x4, y4);
    ll cd1 = ccw(x3, y3, x4, y4, x1, y1);
    ll cd2 = ccw(x3, y3, x4, y4, x2, y2);

    if (ab1 * ab2 < 0 && cd1 * cd2 < 0) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}