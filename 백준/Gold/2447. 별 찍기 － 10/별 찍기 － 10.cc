#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

vector<string> board;

void draw(int r, int c, int n) {
    if (n == 1) {                // 한 칸이면 별 하나
        board[r][c] = '*';
        return;
    }
    int m = n / 3;               // 하위 블록 한 변의 길이
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) continue; // 중앙은 공백
            draw(r + i * m, c + j * m, m);  // 나머지 8칸 재귀
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    board.assign(N, string(N, ' ')); // 미리 공백으로 채워둠
    draw(0, 0, N);

    for (int i = 0; i < N; ++i)
        cout << board[i] << '\n';
    return 0;
}