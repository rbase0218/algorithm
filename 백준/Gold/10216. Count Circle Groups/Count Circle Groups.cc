#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

#define ll long long

struct Circle
{
    int x, y, r;
};

int parent[3000];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

bool isConnected(const Circle& a, const Circle& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    long long distSq = dx * dx + dy * dy;
    long long rSum = a.r + b.r;
    return distSq <= rSum * rSum;
}

int main() {
    int t;
    cin >> t;

    int n;
    while (t--) {
        cin >> n;
        vector<Circle> data;
        int a, b, c;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b >> c;
            data.push_back({ a, b, c });
        }

        for (int i = 0; i < n; ++i)
            parent[i] = i;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected(data[i], data[j])) {
                    unite(i, j);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) count++;
        }

        cout << count << '\n';
    }

    return 0;
}
