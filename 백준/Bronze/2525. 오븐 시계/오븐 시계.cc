#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int x, y, t;
    cin >> x >> y >> t;

    y += t;
    if (y >= 60)
    {
        t = y / 60;
        x += t;

        y %= 60;
    }

    if (x > 23)
        x %= 24;

    cout << x << " " << y;

    return 0;
}