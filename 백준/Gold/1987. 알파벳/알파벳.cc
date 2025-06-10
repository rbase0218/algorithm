#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int h, w;
int dir[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
int ans = 0;

void dfs(vector<vector<char>>& map, vector<bool>& visited, int x, int y, int count)
{
    ans = max(ans, count);

    for (int i = 0; i < 4; ++i) {
        int nextX = x + dir[i][0];  // X
        int nextY = y + dir[i][1];  // Y

        if (nextX < 0 || nextY < 0 || nextX >= w || nextY >= h || visited[map[nextY][nextX] - '65'])
            continue;

        visited[map[nextY][nextX] - '65'] = true;
        dfs(map, visited, nextX, nextY, count + 1);
        visited[map[nextY][nextX] - '65'] = false;
    }
}

int main(void) {
    cin >> h >> w;
    vector<vector<char>> map(h, vector<char>(w));
    vector<bool> visited(26, false);

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j)
        {
            cin >> map[i][j];
        }
    }

    visited[map[0][0] - '65'] = true;
    dfs(map, visited, 0, 0, 1);

    cout << ans << '\n';

    return 0; 
}
