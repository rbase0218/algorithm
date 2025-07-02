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

	pair<pair<int, int>, int> pos1, pos2;
	while (tc--) {
		int ans = 0;
		cin >> pos1.first.first >> pos1.first.second >> pos1.second >> pos2.first.first >> pos2.first.second >> pos2.second;
		
		double d = sqrt(pow(pos2.first.first - pos1.first.first, 2) + pow(pos2.first.second - pos1.first.second, 2));
		if (d == 0 && pos1.second == pos2.second)
			ans = -1;
		else if (d > pos1.second + pos2.second || d < abs(pos1.second - pos2.second))
			ans = 0;
		else if (d == pos1.second + pos2.second || d == abs(pos1.second - pos2.second))
			ans = 1;
		else
			ans = 2;

		cout << ans << endl;
	}
	return 0;
}