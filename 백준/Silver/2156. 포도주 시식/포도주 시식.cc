#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> dp(n + 1, 0);
	vector<int> num(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		cin >> num[i];
	}

	dp[1] = num[1];
	dp[2] = dp[1] + num[2];
	for (int i = 3; i <= n; ++i) {
		dp[i] = max({
			dp[i - 3] + num[i - 1] + num[i],
			dp[i - 2] + num[i],
			dp[i - 1]
			});
	}

	cout << dp[n];

	return 0;
}