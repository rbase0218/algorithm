#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> heights(9);
    vector<int> reals;

    int total_sum = 0, zzap;
    int fake1 = -1, fake2 = -1;

    for (int i = 0; i < 9; i++) {
        cin >> heights[i];
        total_sum += heights[i];
    }

    zzap = total_sum - 100;

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (heights[i] + heights[j] == zzap) {
                fake1 = i;
                fake2 = j;
                break;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        if (i != fake1 && i != fake2) {
            reals.push_back(heights[i]);
        }
    }

    sort(reals.begin(), reals.end());

    for (int height : reals) {
        cout << height << endl;
    }

    return 0;
}