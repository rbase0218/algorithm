#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	int n;
	while (tc--) {
		long long ans = 0;
		int mn = -1;

		cin >> n;
		vector<int> num(n);
		for (int i = 0; i < n; ++i) {
			cin >> num[i];
		}

		for (int i = n - 1; i >= 0; --i) {
			mn = max(num[i], mn);
			ans += mn - num[i];
		}
		cout << ans << endl;
	}
	
	return 0;
}