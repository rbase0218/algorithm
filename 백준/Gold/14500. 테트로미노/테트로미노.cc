#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int board[501][501];
bool visited[501][501];
int answer = 0;

// 상하좌우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// DFS를 이용한 모양 탐색
void dfs(int x, int y, int depth, int sum) {
    if (depth == 4) {
        answer = max(answer, sum);
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (visited[nx][ny]) continue;

        visited[nx][ny] = true;
        dfs(nx, ny, depth + 1, sum + board[nx][ny]);
        visited[nx][ny] = false;
    }
}

// 'ㅗ', 'ㅜ', 'ㅏ', 'ㅓ' 모양 별도 처리
void checkExtra(int x, int y) {
    // 중심과 주변 4칸 중 3칸을 선택하는 방식 (5칸 중 4칸을 선택)
    int center = board[x][y];
    for (int i = 0; i < 4; i++) {
        int temp = center;
        bool valid = true;
        for (int j = 0; j < 3; j++) {
            int dir = (i + j) % 4;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                valid = false;
                break;
            }
            temp += board[nx][ny];
        }
        if (valid)
            answer = max(answer, temp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            visited[i][j] = false;

            checkExtra(i, j);  // 'ㅗ' 모양
        }
    }

    cout << answer << '\n';
    return 0;
}
