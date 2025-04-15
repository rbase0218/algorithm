#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int tc, num;
	cin >> tc;

	while (tc-- > 0)
	{
		cin >> num;

		vector<int> dp(num + 1);

		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= num; ++i) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}

		cout << dp[num] << endl;
	}

	return 0;
}