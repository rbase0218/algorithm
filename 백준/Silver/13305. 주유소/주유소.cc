#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dist(n - 1, 0);
    vector<int> cost(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        cin >> dist[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    // 1. 이전에 방문한 주유소의 가격
    int min_cost = cost[0];
    int sum = dist[0];
    int ans = 0;

    for (int i = 1; i < n - 1; ++i) {
        if (min_cost > cost[i])
        {
            // 이동한 거리만큼 주유
            ans += sum * min_cost;
            sum = 0;

            // 최저가 변경
            min_cost = cost[i];
        }

        // 누적 거리 저장
        sum += dist[i];
    }
    ans += sum * min_cost;

    cout << ans;
    return 0;
}