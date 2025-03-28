#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, m, sum = 0, count = 0;
	cin >> n >> m;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				int temp = arr[i] + arr[j] + arr[k];
				if (temp <= m) {
					sum = max(sum, temp);
				}
			}
		}
	}

	cout << sum;

	return 0;
}