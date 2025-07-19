#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int manhattan(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(void)
{
	int n;
	cin >> n;
	vector<pair<int, int>> dist(n);
	for (int i = 0; i < n; ++i) {
		cin >> dist[i].first >> dist[i].second;
	}

	int total = 0;
	for (int i = 1; i < n; ++i)
		total += abs(dist[i].first - dist[i - 1].first) + abs(dist[i].second - dist[i - 1].second);

	int maxSave = 0;
	for (int i = 1; i < n - 1; ++i) {
		int origin = manhattan(dist[i], dist[i - 1]) + manhattan(dist[i], dist[i + 1]);
		int skip = manhattan(dist[i - 1], dist[i + 1]);
		maxSave = max(maxSave, origin - skip);
	}

	cout << total - maxSave;

	return 0;
}