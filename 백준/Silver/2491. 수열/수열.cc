#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main() {
	int n, result = 1;
	cin >> n;
	vector<int> num(n, 0);
	int b = 1, s = 1;

	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}

	for (int i = 0; i < n - 1; ++i) {
		if (num[i] <= num[i + 1]) b++;
		else b = 1;

		if (num[i] >= num[i + 1]) s++;
		else s = 1;

		result = max(max(b, s), result);
	}

	cout << result;

	return 0;
}