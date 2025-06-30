#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

void bfs(pair<int, int> startPos, pair<int, int> endPos, vector<vector<bool>> &visited)
{
	int size = visited.size();
	queue<pair<pair<int,int>, int>> q;

	q.push({startPos, 0});
	visited[startPos.second][startPos.first] = true;

	while (!q.empty())
	{
		int currX = q.front().first.first;
		int currY = q.front().first.second;
		int dist = q.front().second;

		q.pop();

		if (currX == endPos.first && currY == endPos.second)
		{
			cout << dist << endl;
			return;
		}

		for (int dy = -2; dy <= 2; ++dy) {
			for (int dx = -2; dx <= 2; ++dx) {
				if (abs(dy) + abs(dx) == 3)
				{
					int nextX = currX + dx;
					int nextY = currY + dy;

					if (nextX < 0 || nextY < 0 || nextX >= size || nextY >= size || visited[nextY][nextX] == true)
						continue;

					q.push({ { nextX, nextY }, dist + 1 });
					visited[nextY][nextX] = true;
				}
			}
		}
	}
}

int main(void) {
	int tc;
	cin >> tc;

	int size;
	pair<int, int> startPos, endPos;
	vector<vector<bool>> visited;

	while (tc--) {
		cin >> size;
		cin >> startPos.first >> startPos.second;
		cin >> endPos.first >> endPos.second;
		
		visited.assign(size, vector<bool>(size, false));

		bfs(startPos, endPos, visited);
	}
	return 0;
}