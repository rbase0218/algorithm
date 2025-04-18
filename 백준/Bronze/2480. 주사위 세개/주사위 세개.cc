#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c)
        cout << 10000 + (a * 1000);
    else if (a == b || b == c || a == c)
    {
        int ans = (a == b) ? a : (a == c) ? a : b;
        cout << 1000 + ans * 100;
    }
    else
    {
        int ans = (a > b) ? (a > c) ? a : c : (b > c) ? b : c;
        cout << ans * 100;
    }

    return 0;
}