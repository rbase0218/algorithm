#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>

using namespace std;

int main() {
    string S, P;
    cin >> S >> P;

    bool is_valid = true;
    set<char> seen;

    for (char c : P) {
        if (seen.count(c)) {
            is_valid = false;
            break;
        }
        seen.insert(c);
        if (S.find(c) == string::npos) {
            is_valid = false;
            break;
        }
    }

    long long count = 0;

    if (is_valid) {
        int S_length = S.length();
        int P_length = P.length();
        int D = S_length - P_length;

        count = 1;

        int index_range = 1;

        for (int i = 2; i <= D + 1; ++i) {
            long long temp = 1;
            for (int j = 0; j < index_range; ++j) {
                temp *= static_cast<long long>(D - j);
            }
            count += temp * i;
            index_range++;
        }
    }

    cout << count << '\n';
    return 0;
}