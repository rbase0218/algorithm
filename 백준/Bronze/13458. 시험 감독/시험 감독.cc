#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
using namespace std;

int main(void) {
	int n, b, c;
	long long ans = 0;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> b >> c;

	bool first = false;
	for (int i = 0; i < n; ++i) {
		while (a[i] > 0)
		{
			// 총 감독관이 할 수 있는 수를 뺀다.
			if (first == false)
			{
				first = true;

				a[i] -= b;
				ans += 1;
			}
			else
			{
				if (a[i] <= c)
				{
					ans += 1;
					a[i] -= c;
				}
				else
				{
					int t, s;
					t = a[i] / c;
					a[i] %= c;

					ans += t;
				}
			}
		}
		first = false;
	}

	cout << ans;

	return 0;
}