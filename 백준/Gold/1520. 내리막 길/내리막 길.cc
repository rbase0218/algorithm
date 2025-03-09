#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int M, N;
vector<vector<int>> map;
vector<vector<int>> dp;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

int dfs(int x, int y) {
    if (x == M - 1 && y == N - 1) return 1;
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
        
        if (map[nx][ny] < map[x][y]) {
            dp[x][y] += dfs(nx, ny);
        }
    }

    return dp[x][y];
}

int main() {
    cin >> M >> N;

    map.resize(M, vector<int>(N));
    dp.resize(M, vector<int>(N, -1));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int result = dfs(0, 0);
    cout << result << endl;

    return 0;
}