#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main() {
	bool maps[101][101] = { false, };

	int a, b, c, d;
	bool beforeA = false, beforeB = false;
	for (int i = 0; i < 4; ++i) {
		cin >> a >> b >> c >> d;

		for (int i = a; i < c; ++i) {
			for (int j = b; j < d; ++j)
				maps[i][j] = true;
		}
	}

	int ans = 0;
	for (int i = 0; i < 101; ++i) {
		for (int j = 0; j < 101; ++j) {
			if(maps[i][j])
				ans++;
		}
	}

	cout << ans;

	return 0;
}