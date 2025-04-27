#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int tc = 0;
	cin >> tc;

	int n, ans;
	while (tc--) {
		ans = 1;
		cin >> n;

		vector<pair<int, int>> num(n);
		for (auto& p : num) {
			cin >> p.first >> p.second;
		}

		sort(num.begin(), num.end());

		int temp = 0;
		for (int i = 1; i < n; ++i) 
		{
			if (num[temp].second > num[i].second)
			{
				ans++;
				temp = i;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}