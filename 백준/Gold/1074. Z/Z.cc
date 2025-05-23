#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

int n, m, s;
int ans = 0;

void divide(int x, int y, int size) {

	if (s == x && m == y) {
		cout << ans;
		return;
	}
	else if (s < x + size && m < y + size && s >= x && m >= y) {
		divide(x, y, size / 2);
		divide(x + size / 2, y, size / 2);
		divide(x, y + size / 2, size / 2);
		divide(x + size / 2, y + size / 2, size / 2);

	}
	else
		ans += size * size;
}

int main() {
	cin >> n >> m >> s;

	divide(0, 0, pow(2, n));
	return 0;
}