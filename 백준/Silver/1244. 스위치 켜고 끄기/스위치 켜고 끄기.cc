#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main() {
	int n, t;
	cin >> n;
	vector<int> num(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> num[i];
	}
	cin >> t;

	// s == 1 : 남자
	// s == 2 : 여자
	int s, g;
	while (t--) {
		cin >> s >> g;

		if (s == 1) {
			for (int i = g; i <= n; i += g) {
				num[i] = 1 - num[i];
			}
		}
		else if (s == 2) {
			num[g] = 1 - num[g];

			for (int i = 1; g - i >= 1 && g + i <= n; ++i)
			{
				if (num[g - i] == num[g + i])
					num[g - i] = num[g + i] = 1 - num[g - i];
				else
					break;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << num[i];

		if (i % 20 == 0 || i == n) 
			cout << "\n";
		else
			cout << " ";
	}

	return 0;
}