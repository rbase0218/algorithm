#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int w, h;

int find(vector<vector<int>>& maps)
{
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    queue<pair<int, int>> q;
    int count = 0;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (maps[i][j] == 0 || visited[i][j])
                continue;

            // maps의 Data가 0이 아니라면 => 땅이다.
            q.push({ i, j });
            visited[i][j] = true;
            count++;

            while (!q.empty())
            {
                int currX = q.front().second;
                int currY = q.front().first;
                q.pop();

                for (int y = -1; y <= 1; ++y) {
                    for (int x = -1; x <= 1; ++x) {
                        if (x == 0 && y == 0) continue;

                        int nextX = currX + x;
                        int nextY = currY + y;
                        // 범위 안에 존재하며, 지형이면서 방문하지 않았다면
                        if (nextX >= 0 && nextY >= 0 && nextX < w && nextY < h && maps[nextY][nextX] == 1 && !visited[nextY][nextX])
                        {
                            q.push({ nextY, nextX });
                            visited[nextY][nextX] = true;
                        }
                    }
                }
            }
        }
    }

    return count;
}

int main(void) {
    while (true)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        vector<vector<int>> maps(h, vector<int>(w));

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> maps[i][j];
            }
        }

        cout << find(maps) << "\n";
    }

    return 0; 
}