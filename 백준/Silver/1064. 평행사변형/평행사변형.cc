#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    
    double cross1 = (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
    if (abs(cross1) < 1e-9) {
        cout << -1.0 << endl;
        return 0;
    }
    
    double ab = dist(ax, ay, bx, by);
    double bc = dist(bx, by, cx, cy);
    double ca = dist(cx, cy, ax, ay);
    
    double pt1 = 2 * (ab + ca);
    double pt2 = 2 * (bc + ab);
    double pt3 = 2 * (ca + bc);
    
    double max_pt = max({pt1, pt2, pt3});
    double min_pt = min({pt1, pt2, pt3});
    
    cout << fixed;
    cout.precision(9);
    cout << max_pt - min_pt << endl;
    
    return 0;
}