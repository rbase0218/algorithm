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

	int a, b;
	while (tc--) {
		cin >> a >> b;

		if (a > b - a)
			a = b - a;

		long long result = 1;
		for (int i = 0; i < a; ++i)
			result = result * (b - i) / (i + 1);

		cout << result << "\n";
	}

	return 0;
}