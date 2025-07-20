#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

double getHeight(double x, double y, double w) {
    double a = sqrt(x * x - w * w);
    double b = sqrt(y * y - w * w);

    return (a * b) / (a + b);
}

int main() {
    double x, y, c;
    cin >> x >> y >> c;

    double low = 0;
    double high = min(x, y);
    double mid;

    for (int i = 0; i < 100; ++i) {
        mid = (low + high) / 2.0;
        double h = getHeight(x, y, mid);

        if (h >= c)
            low = mid;
        else
            high = mid;
    }

    cout << fixed << setprecision(3) << mid << '\n';

    return 0;
}