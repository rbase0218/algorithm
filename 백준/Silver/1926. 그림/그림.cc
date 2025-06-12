#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int dir[4][2] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };
int n, m;

int bfs(int x, int y, vector<vector<int>>& maps, vector<vector<bool>>& visited)
{
    queue<pair<int, int>> q;
    int size = 0;

    q.push({ x, y });
    visited[y][x] = true;

    while (!q.empty())
    {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        size++;

        for (int i = 0; i < 4; ++i) {
            int nextX = currX + dir[i][1];
            int nextY = currY + dir[i][0];

            if (nextX < 0 || nextY < 0 || nextX >= m || nextY >= n || visited[nextY][nextX] || maps[nextY][nextX] != 1)
                continue;

            q.push({ nextX, nextY });
            visited[nextY][nextX] = true;
        }
    }

    return size;
}

int main(void) {
    int size, count;
    cin >> n >> m;
    vector<vector<int>> maps(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maps[i][j];
        }
    }

    size = count = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && maps[i][j] == 1)
            {
                size = max(size, bfs(j, i, maps, visited));
                count++;
            }
        }
    }

    cout << count << '\n' << size;
    
    return 0; 
}
