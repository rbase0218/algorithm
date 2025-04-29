#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i) {
		int ms, ds, me, de;
		cin >> ms >> ds >> me >> de;
		v[i] = { ms * 100 + ds, me * 100 + de };
	}
	sort(v.begin(), v.end());

	int current = 301;
	int result = 0;

	while (current < 1201) {
		int next_date = current;
		int best_idx = -1;

		for (int i = 0; i < n; ++i) {
			if (v[i].first <= current && v[i].second > next_date) {
				next_date = v[i].second;
				best_idx = i;
			}
		}

		if (best_idx == -1) {
			cout << "0\n";
			return 0;
		}

		current = next_date;
		result++;
		if (current > 1130) break;
	}

	cout << result;

	return 0;
}