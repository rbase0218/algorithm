#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solve(vector<int>& board, int row, int n, int& count) {
    if (row == n) {
        count++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isValid(board, row, col)) {
            board[row] = col;
            solve(board, row + 1, n, count);
        }
    }
}

int getNqueenCount(int n) {
    vector<int> board(n, 0);
    int count = 0;
    solve(board, 0, n, count);
    return count;
}

int main() {
    int size;
    cin >> size;

    int solutions = getNqueenCount(size);
    cout << solutions << endl;

    return 0;
}