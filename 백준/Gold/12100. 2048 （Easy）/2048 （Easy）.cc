#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
using namespace std;

int n, answer = 0;

void move(vector<vector<int>>& board, int dir) {
    switch (dir) {
    case 0:
        for (int col = 0; col < n; ++col) {
            int top = 0, last = 0;
            for (int row = 0; row < n; ++row) {
                if (board[row][col] == 0) continue;
                int val = board[row][col];
                board[row][col] = 0;
                if (last == val) {
                    board[top - 1][col] *= 2;
                    last = 0;
                }
                else {
                    board[top][col] = val;
                    last = val;
                    top++;
                }
            }
        }
        break;

    case 1:
        for (int row = 0; row < n; ++row) {
            int right = n - 1, last = 0;
            for (int col = n - 1; col >= 0; --col) {
                if (board[row][col] == 0) continue;
                int val = board[row][col];
                board[row][col] = 0;
                if (last == val) {
                    board[row][right + 1] *= 2;
                    last = 0;
                }
                else {
                    board[row][right] = val;
                    last = val;
                    right--;
                }
            }
        }
        break;

    case 2: 
        for (int col = 0; col < n; ++col) {
            int bottom = n - 1, last = 0;
            for (int row = n - 1; row >= 0; --row) {
                if (board[row][col] == 0) continue;
                int val = board[row][col];
                board[row][col] = 0;
                if (last == val) {
                    board[bottom + 1][col] *= 2;
                    last = 0;
                }
                else {
                    board[bottom][col] = val;
                    last = val;
                    bottom--;
                }
            }
        }
        break;

    case 3:
        for (int row = 0; row < n; ++row) {
            int left = 0, last = 0;
            for (int col = 0; col < n; ++col) {
                if (board[row][col] == 0) continue;
                int val = board[row][col];
                board[row][col] = 0;
                if (last == val) {
                    board[row][left - 1] *= 2;
                    last = 0;
                }
                else {
                    board[row][left] = val;
                    last = val;
                    left++;
                }
            }
        }
        break;
    }
}


void dfs(vector<vector<int>> board, int depth) {
    if (depth == 5) {
        for (auto& row : board) {
            for (int val : row) {
                answer = max(answer, val);
            }
        }
        return;
    }

    for (int dir = 0; dir < 4; ++dir) {
        vector<vector<int>> temp = board;
        move(temp, dir);
        dfs(temp, depth + 1);
    }
}

int main() {
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];

    dfs(board, 0);
    cout << answer << "\n";
    return 0;
}