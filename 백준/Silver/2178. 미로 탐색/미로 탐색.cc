#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

void bfs(int x, int y, vector<vector<int>>& maps) {
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };

    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited(y, vector<bool>(x, false));

    q.push({ {0, 0}, 1 });
    visited[0][0] = true;

    while (!q.empty())
    {
        int currX = q.front().first.first;
        int currY = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        if (currX == x - 1 && currY == y - 1)
        {
            cout << dist;
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nextX = currX + dx[i];
            int nextY = currY + dy[i];

            if (nextX >= 0 && nextY >= 0 && nextX < x && nextY < y && maps[nextY][nextX] == 1 && !visited[nextY][nextX])
            {
                visited[nextY][nextX] = true;
                q.push({ {nextX, nextY}, dist + 1 });
            }
        }
    }
    
    
}

int main(void) {
    int n, m;   // N개의 줄 M개의 정수 ( n = y , m = x )
    cin >> n >> m;
    vector<vector<int>> maps(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < m; ++j) {
            maps[i][j] = line[j] - '0';
        }
    }

    bfs(m, n, maps);

    return 0;
}
