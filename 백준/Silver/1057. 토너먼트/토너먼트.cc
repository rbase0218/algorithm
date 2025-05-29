#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(void) {
	int n, m, x;
	cin >> n >> m >> x;

	int ans = 0;
	while (m != x)
	{
		m = (m + 1) / 2;
		x = (x + 1) / 2;
		ans++;
	}
	cout << ans;

	return 0;
}
