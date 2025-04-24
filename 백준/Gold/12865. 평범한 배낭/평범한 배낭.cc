#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> c(n + 1);   // Cost
    vector<int> w(n + 1);   // Weight
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    for (int i = 1; i <= n; ++i) {
        cin >> c[i] >> w[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (j >= c[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + w[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][k];

    return 0;
}