#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	vector<int> dp(n + 1, 5001);

	dp[0] = 0;

	for (int i = 0; i <= n; ++i) {
		if (i >= 3 && dp[i - 3] != 5001)
			dp[i] = min(dp[i], dp[i - 3] + 1);
		if (i >= 5 && dp[i - 5] != 5001)
			dp[i] = min(dp[i], dp[i - 5] + 1);
	}

	cout << ((dp[n] == 5001) ? -1 : dp[n]) << endl;

	return 0;
}