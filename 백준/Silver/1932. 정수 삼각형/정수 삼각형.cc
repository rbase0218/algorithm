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
	int n;
	cin >> n;

	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> dp[i][j];
		}
	}
	
	int maxNumber = dp[0][0];
	for (int i = 1; i < n; ++i) {
		dp[i][0] = dp[i - 1][0] + dp[i][0];
		dp[i][i] = dp[i - 1][i - 1] + dp[i][i];

		for (int j = 1; j < i; ++j) {
			dp[i][j] = max(dp[i - 1][j - 1] + dp[i][j], dp[i - 1][j] + dp[i][j]);
			maxNumber = max({maxNumber, dp[i][0], dp[i][i], dp[i][j]});
		}
	}

	cout << maxNumber;

	return 0;
}