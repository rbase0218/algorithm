#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int dir[4][2] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };

void bfs(int x, int y, vector<vector<char>>& map, vector<vector<bool>>& visited, bool color)
{
    queue<pair<int, int>> q;

    q.push({ x, y });
    visited[y][x] = true;

    while (!q.empty())
    {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextX = currX + dir[i][1];  // X
            int nextY = currY + dir[i][0];  // Y
            
            // 범위 밖에 있거나, 방문을 했으면 반려
            if (nextX < 1 || nextY < 1 || nextX >= map.size() || nextY >= map.size() || visited[nextY][nextX])
                continue;

            bool okay = false;
            if (color)
            {
                if (map[y][x] == map[nextY][nextX] || (map[y][x] == 'R' || map[y][x] == 'G') &&
                    (map[nextY][nextX] == 'R' || map[nextY][nextX] == 'G'))
                {
                    okay = true;
                }
            }
            else if (map[y][x] == map[nextY][nextX])
                okay = true;

            if (okay)
            {
                visited[nextY][nextX] = true;
                q.push({ nextX, nextY });
            }
        }
    }
}


int main(void) {
    int n, ans1, ans2;
    ans1 = ans2 = 0;
    cin >> n;
    vector<vector<char>> map(n + 1, vector<char>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j) {
            cin >> map[i][j];
        }
    }

    vector<vector<bool>> normalVisited(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
        {
            if (!normalVisited[i][j])
            {
                bfs(j, i, map, normalVisited, false);
                ans1++;
            }
        }
    }

    vector<vector<bool>> blindVisited(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
        {
            if (!blindVisited[i][j])
            {
                bfs(j, i, map, blindVisited, true);
                ans2++;
            }
        }
    }

    cout << ans1 << " " << ans2;

    return 0; 
}
