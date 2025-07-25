#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
using namespace std;

int main() {
	string s;
	cin >> s;

	int val, ans = 1;
	vector<int> data(9);

	for (int i = 0; i < s.size(); ++i) {
		val = s[i] - '0';
		data[val == 9 ? 6 : val]++;
	}

	for (int i = 0; i < data.size(); ++i) {
		if (i == 6)
		{
			data[i]++;
			data[i] /= 2;
		}
		ans = max(data[i], ans);
	}

	cout << ans;

	return 0;
}