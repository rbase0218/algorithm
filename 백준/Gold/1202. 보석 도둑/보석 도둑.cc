#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

long long checked(int n, int k, vector<pair<int, int>>& jewel, vector<int>& backpack)
{
    long long sum = 0;

    sort(jewel.begin(), jewel.end());
    sort(backpack.begin(), backpack.end());

    priority_queue<int> pq;

    int jewelIndex = 0;

    for (int i = 0; i < k; i++) {
        int bagCapacity = backpack[i];

        while (jewelIndex < n && jewel[jewelIndex].first <= bagCapacity) {
            pq.push(jewel[jewelIndex].second);
            jewelIndex++;
        }

        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }

    return sum;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> jewel;
    vector<int> knapback(k);
    int a, b;

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        jewel.push_back({ a, b });
    }

    for (int i = 0; i < k; ++i) {
        cin >> knapback[i];
    }

    cout << checked(n, k, jewel, knapback) << endl;
    return 0;
}