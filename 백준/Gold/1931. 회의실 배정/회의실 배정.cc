#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n,last_time, ans = 1;
    vector<pair<int, int>> times;

    cin >> n;

    int start, end;
    for (int i = 0; i < n; ++i) {
        cin >> start >> end;
        times.push_back(make_pair(end, start));
    }

    sort(times.begin(), times.end());
    last_time = times[0].first;

    for (int i = 1; i < n; ++i) {
        if (last_time <= times[i].second)
        {
            last_time = times[i].first;
            ans++;
        }
    }

    cout << ans;

    return 0;
}