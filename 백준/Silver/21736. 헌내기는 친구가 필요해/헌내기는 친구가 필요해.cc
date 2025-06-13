#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int dir[4][2] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };
int n, m;

int bfs(int x, int y, vector<vector<char>>& maps, vector<vector<bool>>& visited)
{
	int count = 0;
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[y][x] = true;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nextX = cx + dir[i][1];
			int nextY = cy + dir[i][0];

			if (nextX < 0 || nextY < 0 || nextX >= maps[0].size() || nextY >= maps.size() || visited[nextY][nextX])
				continue;

			switch (maps[nextY][nextX])
			{
			case 'P':
				count++;
			case 'O':
				q.push({ nextX, nextY });
				visited[nextY][nextX] = true;
				break;
			}
		}
	}
	return count;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> maps(n, vector<char>(m));
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	int x = 0, y = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> maps[i][j];
			if (maps[i][j] == 'I')
			{
				x = j;
				y = i;
			}
		}
	}

	int count;
	if (count = bfs(x, y, maps, visited))
	{
		cout << count;
	}
	else
		cout << "TT";

	return 0;
}