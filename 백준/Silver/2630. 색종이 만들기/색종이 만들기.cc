#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int blue = 0, white = 0;
vector<vector<int>> confetti;

void divide(int x, int y, int size) {
    bool sameColor = true;
    int color = confetti[y][x]; 

    for (int i = y; i < y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            if (confetti[i][j] != color) {
                sameColor = false;
                break;
            }
        }
        if (!sameColor) break;
    }

    if (sameColor) {
        if (color == 0) white += 1;
        else blue += 1;
        return;
    }

    int n = size / 2;

    divide(x, y, n);               
    divide(x + n, y, n);           
    divide(x, y + n, n);           
    divide(x + n, y + n, n);       
}

int main(void)
{
    int n;
    cin >> n;
    confetti.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> confetti[i][j];
        }
    }

    divide(0, 0, n);

    cout << white << '\n';
    cout << blue << '\n';

    return 0;
}