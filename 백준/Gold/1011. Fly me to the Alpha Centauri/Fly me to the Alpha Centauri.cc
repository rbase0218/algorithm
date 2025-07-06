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

	long long x, y;
	while (tc--) {
		cin >> x >> y;
		long long dist = y - x;
		long long n = (long long)sqrt(dist);

		long long result = 0;
		if (dist == n * n)
			result = 2 * n - 1;
		else if (dist <= n * n + n)
			result = 2 * n;
		else
			result = 2 * n + 1;

		cout << result << '\n';
	}

	return 0;
}