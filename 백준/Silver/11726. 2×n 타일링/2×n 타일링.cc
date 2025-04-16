#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int num;
	cin >> num;
	vector<int> dp(num + 1, 0);

	if (num < 4)
	{
		cout << num;
		return 0;
	}
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= num; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[num];

	return 0;
}