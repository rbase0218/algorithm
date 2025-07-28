#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<pair<int, int>> num(n); 
    vector<int> dp(n + 1, 0);      

    for (int i = 0; i < n; ++i) {
        cin >> num[i].first >> num[i].second;
    }

    for (int i = 0; i < n; ++i) {
        int next = i + num[i].first;
        if (next <= n) {
            dp[next] = max(dp[next], dp[i] + num[i].second);
        }
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }

    cout << dp[n];

    return 0;
}