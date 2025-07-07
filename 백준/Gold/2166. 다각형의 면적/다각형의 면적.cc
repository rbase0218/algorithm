#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

#define ll long long

int main() {
    int n = 0;
    cin >> n;

    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        int next = (i + 1) % n;
        sum += x[i] * y[next] - x[next] * y[i];
    }

    double area = abs(sum) / 2.0;
    cout << fixed << setprecision(1) << area << '\n';

    return 0;
}