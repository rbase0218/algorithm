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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) 
        return 0;

    vector<vector<string>> cls(N + 1);

    while (true) {
        int c; string name;
        if (!(cin >> c >> name)) 
            break;
        if (c == 0 && name == "0") 
            break;

        if (1 <= c && c <= N) {
            if ((int)cls[c].size() < M) {
                cls[c].push_back(name);
            }
        }
    }

    auto cmp = [](const string& a, const string& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
        };

    for (int i = 1; i <= N; ++i) 
        sort(cls[i].begin(), cls[i].end(), cmp);

    for (int i = 1; i <= N; i += 2) {
        for (const auto& s : cls[i]) {
            cout << i << ' ' << s << '\n';
        }
    }
    for (int i = 2; i <= N; i += 2) {
        for (const auto& s : cls[i]) {
            cout << i << ' ' << s << '\n';
        }
    }
    return 0;
}