#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> dp(n + 1, 0);

	if (n < 2)
		dp[n] = n;
	else
	{
		dp[1] = 1;
		dp[2] = 2;

		for (int i = 3; i <= n; ++i) {
			dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
		}
	}

	cout << dp[n];

	return 0;
}