#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0, x, y;
    for (int i = 1; i < n; ++i) {
        sum = i;
        x = i;

        while (x > 0)
        {
            y = x % 10;
            sum += y;
            x = x / 10;
        }

        if (sum == n)
        {
            cout << i;
            return 0;
        }
    }
    cout << 0;

    return 0;
}