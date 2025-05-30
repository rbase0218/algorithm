#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void check(int x, int y, int size, vector<vector<int>>& maps)
{
    if (size == 1) {
        cout << maps[y][x];
        return;
    }

    int num = maps[y][x];
    bool same = true;

    for (int i = y; i < y + size && same; ++i) {
        for (int j = x; j < x + size && same; ++j) {
            if (maps[i][j] != num) {
                same = false;
            }
        }
    }

    if (same) {
        cout << num;
    }
    else {
        cout << "(";
        int half = size / 2;
        check(x, y, half, maps);
        check(x + half, y, half, maps);
        check(x, y + half, half, maps);
        check(x + half, y + half, half, maps);
        cout << ")";
    }
}

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < n; ++j) {
            nums[i][j] = line[j] - '0';
        }
    }

    check(0, 0, n, nums);
    return 0;
}