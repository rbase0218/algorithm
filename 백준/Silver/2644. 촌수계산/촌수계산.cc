#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int bfs(int start, int target, vector<vector<int>>& graph, int n) {
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q;

    q.push({ start, 0 });
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (current == target) {
            return dist;
        }

        for (int i = 1; i <= n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push({ i, dist + 1 });
            }
        }
    }

    return -1;
}

int main(void) {
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;

    int m;
    cin >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    int result = bfs(a, b, graph, n);
    cout << result << endl;

    return 0;
}