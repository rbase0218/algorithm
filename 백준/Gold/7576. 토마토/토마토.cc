#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main(void) {
    int n, m;   // n : 세로 m : 가로
    int days = 0;
    cin >> m >> n;
    vector<vector<int>> maps(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maps[i][j];

            if (maps[i][j] == 1)
                q.push({ i,j });
        }
    }

    while (!q.empty()) {
        int size = q.size();
        bool newTomato = false;

        for (int i = 0; i < size; ++i) {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();

            for (int j = 0; j < 4; ++j) {
                int nextX = x + dx[j];
                int nextY = y + dy[j];

                if (nextX >= 0 && nextY >= 0 && nextX < m && nextY < n && maps[nextY][nextX] == 0) {
                    maps[nextY][nextX] = 1;
                    q.push({ nextY, nextX });
                    newTomato = true;
                }
            }
        }
        if (newTomato)
            days++;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maps[i][j] == 0)
                days = -1;
        }
    }

    cout << days;

    return 0;
}
