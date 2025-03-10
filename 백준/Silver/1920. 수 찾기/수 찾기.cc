#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(const vector<int>& arr, int target) {
	int left = 0;
	int right = arr.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == target) {
			return 1;
		}
		else if (arr[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int M = 0;
	cin >> M;

	int target = 0;
	for (int i = 0; i < M; ++i) {
		cin >> target;
		cout << (binary_search(arr, target)) << '\n';
	}

	return 0;
}