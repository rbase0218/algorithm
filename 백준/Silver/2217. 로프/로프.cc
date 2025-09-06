#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>

using namespace std;

int main() {
	int n, ans;
	cin >> n;
	vector<int> rope(n, 0);

	for (int i = 0; i < n; ++i) {
		cin >> rope[i];
	}

	sort(rope.begin(), rope.end());
	ans = rope[n - 1];

	for (int i = n - 1; i >= 0; --i) 
	{
		if (ans < rope[i] * (n - i))
		{
			ans = rope[i] * (n - i);
		}
	}

	cout << ans;
	return 0;
}