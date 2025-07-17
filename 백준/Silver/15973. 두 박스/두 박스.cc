#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

#define ll long long

struct Rect {
    ll x1, y1, x2, y2;
};

int main() {
    Rect r1, r2;
    cin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
    cin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;

    ll x_overlap = min(r1.x2, r2.x2) - max(r1.x1, r2.x1);
    ll y_overlap = min(r1.y2, r2.y2) - max(r1.y1, r2.y1);

    string result = "NULL";

    if (x_overlap > 0 && y_overlap > 0)
        result = "FACE";
    else if (x_overlap == 0 && y_overlap == 0)
        result = "POINT";
    else if (x_overlap == 0 || y_overlap == 0)
        result = "LINE";

    cout << result << '\n';
    return 0;
}