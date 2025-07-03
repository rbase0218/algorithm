#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	int tc;
	cin >> tc;


	while (tc--) {
		int n;
		cin >> n;

		if (n < 3)
		{
			cout << "1" << '\n';
			continue;
		}

		vector<long long> num(n + 1, 0);
		num[1] = 1;
		num[2] = 1;
		num[3] = 1;

		for (int i = 4; i <= n; ++i) {
			num[i] = num[i - 2] + num[i - 3];
		}
		cout << num[n] << '\n';
	}
	return 0;
}