#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int n;
	
	cin >> n;

	vector<int> num(n);
	vector<int> dp(n, 0);

	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}

	dp[0] = num[0];
	dp[1] = num[0] + num[1];
	dp[2] = max(num[0] + num[2], num[1] + num[2]);
	for (int i = 3; i < n; ++i) {
		dp[i] = max(dp[i - 3] + num[i - 1] + num[i], dp[i - 2] + num[i]);
	}
	
	cout << dp[n - 1] << '\n';

	return 0;
}