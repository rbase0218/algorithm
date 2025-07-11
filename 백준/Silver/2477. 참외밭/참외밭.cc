#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int dx[] = { 0, 1, -1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };

int main() {
    int K;
    cin >> K;

    vector<pair<int, int>> points;
    int x = 0, y = 0;

    points.push_back({ x, y });

    for (int i = 0; i < 6; ++i) {
        int dir, len;
        cin >> dir >> len;

        x += dx[dir] * len;
        y += dy[dir] * len;

        points.push_back({ x, y });
    }

    int area = 0;
    for (int i = 0; i < 6; ++i) {
        int x1 = points[i].first;
        int y1 = points[i].second;
        int x2 = points[i + 1].first;
        int y2 = points[i + 1].second;

        area += (x1 * y2 - x2 * y1);
    }

    area = abs(area) / 2;
    cout << area * K << endl;

    return 0;
}