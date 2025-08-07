#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, m, result = 0;
    cin >> n >> m;

    vector<vector<int>> maps(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> maps[i][j];
            dp[i][j] = maps[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = maps[i][j] + max({ dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1] });
        }
    }

    cout << dp[n][m];

    return 0;
}
