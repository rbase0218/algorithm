#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<pair<int, int>> q;
    vector<bool> visited(n + 1, false);
    set<int> invited;

    q.push({ 1, 0 });
    visited[1] = true;

    while (!q.empty()) {
        int current = q.front().first;
        int distance = q.front().second;
        q.pop();

        if (distance <= 2 && current != 1) {
            invited.insert(current);
        }

        if (distance >= 2) continue;

        for (int next : graph[current]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push({ next, distance + 1 });
            }
        }
    }

    cout << invited.size() << endl;

    return 0;
}