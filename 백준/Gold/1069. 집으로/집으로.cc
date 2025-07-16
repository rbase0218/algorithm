#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    double x, y, d, t;
    cin >> x >> y >> d >> t;

    double dist = sqrt(x * x + y * y);
    double minTime = dist;

    if (d / t >= 1) {
        int jumpCount = static_cast<int>(dist / d);
        double jumpTime = jumpCount * t;
        double reDist = dist - jumpCount * d;

        if (reDist > 1e-9) {
            double extra = (jumpCount > 0)
                ? jumpTime + t
                : min(t * 2, t + (d - reDist));
            minTime = min(jumpTime + reDist, extra);
        } else {
            minTime = jumpTime;
        }
    }

    cout << fixed;
    cout.precision(13);
    cout << minTime << '\n';

    return 0;
}
