#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> num(n);
	vector<int> dp(n, 1);

	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (num[j] < num[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	cout << *max_element(dp.begin(), dp.end());

	return 0; 
}