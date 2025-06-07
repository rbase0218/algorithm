#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int n, m;
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} }; // 우, 좌, 하, 상

void melting(vector<vector<int>>& maps)
{
    vector<vector<int>> melt(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maps[i][j] > 0)
            {
                for (int k = 0; k < 4; ++k) {
                    int nextX = j + dir[k][0];
                    int nextY = i + dir[k][1];

                    if (nextX >= 0 && nextY >= 0 && nextX < m && nextY < n
                        && maps[nextY][nextX] == 0) {
                        melt[i][j]++;  // 녹을 양 증가
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            maps[i][j] = max(0, maps[i][j] - melt[i][j]);
        }
    }
}

int find(vector<vector<int>>& maps)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maps[i][j] > 0 && !visited[i][j])
            {
                queue<pair<int, int>> q;
                q.push({ i, j });
                visited[i][j] = true;

                while (!q.empty())
                {
                    int x = q.front().second;
                    int y = q.front().first;
                    q.pop();

                    for (int k = 0; k < 4; ++k) {
                        int nextX = x + dir[k][0];
                        int nextY = y + dir[k][1];

                        if (nextX >= 0 && nextY >= 0 && nextX < m && nextY < n
                            && maps[nextY][nextX] > 0 && !visited[nextY][nextX]) {
                            visited[nextY][nextX] = true;
                            q.push({ nextY, nextX });
                        }
                    }
                }
                count++;
            }
        }
    }
    return count;
}

int main(void) {
    cin >> n >> m;
    
    vector<vector<int>> maps(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cin >> maps[i][j];
    }

    int y = 0;
    while (true) {
        int count = find(maps);

        if (count >= 2)
        {
            cout << y;
            break;
        }

        if (count == 0)
        {
            cout << 0;
            break;
        }

        melting(maps);
        y++;
    }

    return 0; 
}
