#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<int> n(10001, 0);
    int x, y, sum;

    for (int i = 1; i < 10001; ++i) {
        n[i] = i;
    }

    for (int i = 1; i < 10001; ++i) {
        sum = i;
        x = i;

        while (x > 0)
        {
            y = x % 10;
            sum += y;
            x = x / 10;
        }

        if (sum < 10001)
            n[sum] = 0;
    }

    for (int i : n)
    {
        if (i != 0)
            cout << i << '\n';
    }

    return 0;
}