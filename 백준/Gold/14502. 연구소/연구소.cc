#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
using namespace std;

int n, m;
int maps[8][8];			// 원본 데이터
int tempMaps[8][8];	// 복사 데이터

// 방향
int dir[4][2] = { {1, 0}, {-1,0}, {0, -1}, {0, 1} };
int safeAreaCount = 0;	// 정답

void spread() {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (tempMaps[i][j] == 2)
				q.push({ i, j });
		}
	}

	while (!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nextX = x + dir[i][1];
			int nextY = y + dir[i][0];

			if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n)
			{
				if (tempMaps[nextY][nextX] == 0)
				{
					tempMaps[nextY][nextX] = 2;
					q.push({ nextY, nextX });
				}
			}
		}
	}
}

int getSafeArea() {
	int count = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (tempMaps[i][j] == 0)
				count++;
		}
	}

	return count;
}

void dfs(int count) {
	if (count == 3)
	{
		// 복사
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				tempMaps[i][j] = maps[i][j];
			}
		}

		spread();
		safeAreaCount = max(safeAreaCount, getSafeArea());
		return;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (maps[i][j] == 0)
			{
				maps[i][j] = 1;
				dfs(count + 1);
				maps[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> maps[i][j];
		}
	}

	dfs(0);

	cout << safeAreaCount;

	return 0;
}