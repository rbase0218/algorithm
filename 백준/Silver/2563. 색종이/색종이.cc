#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int maps[100][100] = { 0, };

int main(void) {
    int n;
    cin >> n;
    vector<pair<int, int>> paper(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> paper[i].first >> paper[i].second;
        for (int y = paper[i].second; y < paper[i].second + 10; ++y) {
            for (int x = paper[i].first; x < paper[i].first + 10; ++x)
            {
                if (maps[y][x] == 1) continue;
                maps[y][x] = 1;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (maps[i][j] > 0) sum++;
        }
    }

    cout << sum;
    
    return 0;
}