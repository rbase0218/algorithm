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
	int ans = 0;
	for (int i = 0; i < 4; ++i) {
		cin >> a >> b >> c >> d;

		for (int i = a; i < c; ++i) {
			for (int j = b; j < d; ++j)
			{
				if (maps[i][j])
					ans--;

				maps[i][j] = true;
				if (maps[i][j])
					ans++;
			}
		}
	}

	cout << ans;

	return 0;
}