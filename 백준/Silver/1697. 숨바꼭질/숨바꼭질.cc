#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    if (N == K) {
        cout << 0 << endl;
        return 0;
    }

    const int MAX_POS = 100000;
    vector<bool> visited(MAX_POS + 1, false);

    queue<pair<int, int>> q;
    q.push({ N, 0 });
    visited[N] = true;

    while (!q.empty()) {
        int pos = q.front().first;
        int time = q.front().second;
        q.pop();

        int next_positions[3] = { pos - 1, pos + 1, pos * 2 };

        for (int next_pos : next_positions) {
            if (next_pos < 0 || next_pos > MAX_POS || visited[next_pos])
                continue;
            if (next_pos == K) {
                cout << time + 1 << endl;
                return 0;
            }
            visited[next_pos] = true;
            q.push({ next_pos, time + 1 });
        }
    }

    return 0;
}