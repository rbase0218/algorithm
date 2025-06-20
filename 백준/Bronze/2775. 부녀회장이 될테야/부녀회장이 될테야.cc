#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;

int val(int k, int n)
{
	if (k == 0 || n == 1)
		return n;

	return val(k, n - 1) + val(k - 1, n);
}

int main(void) {
	int tc;
	cin >> tc;

	int k, n;
	while (tc--) {
		// K층 N호
		cin >> k >> n;
		vector<vector<int>> dp(k, vector<int>(n + 1));

		cout << val(k, n) << '\n';
	}

	return 0;
}