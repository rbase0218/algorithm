#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int minSum = 999999;
    int minPerson = 999999;

    for (int start = 1; start <= n; ++start) {
        vector<int> distance(n + 1, -1);
        queue<int> q;

        q.push(start);
        distance[start] = 0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int next : graph[current]) {
                if (distance[next] == -1) { 
                    distance[next] = distance[current] + 1;
                    q.push(next);
                }
            }
        }

        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (i != start) {
                sum += distance[i];
            }
        }

        if (sum < minSum) {
            minSum = sum;
            minPerson = start;
        }
    }

    cout << minPerson << endl;

    return 0;
}