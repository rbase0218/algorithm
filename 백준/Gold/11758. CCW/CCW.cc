#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

#define ll long long

int main(void) {
    ll a, b, c, d, e, f;
    cin >> a >> b;
    cin >> c >> d;
    cin >> e >> f;

    ll cp = (c - a) * (f - b) - (d - b) * (e - a);

    cout << (cp == 0 ? 0 : cp > 0 ? 1 : -1) << endl;

    return 0;
}