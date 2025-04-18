#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    y -= 45;
    if (y < 0) {
        x--;
        y += 60;
    }

    if (x < 0)
        x += 24;

    cout << x << " " << y;

    return 0;
}