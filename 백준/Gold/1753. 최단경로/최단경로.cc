#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 98765432

vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int start, int V) {
    vector<int> dp(V + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, start });
    dp[start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if (dp[x] < cost) continue;

        for (int i = 0; i < graph[x].size(); i++) {
            int nx = graph[x][i].first;
            int ncost = cost + graph[x][i].second;

            if (dp[nx] > ncost) {
                pq.push({ ncost, nx });
                dp[nx] = ncost;
            }
        }
    }

    return dp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pair<int, int>>> graph(V + 1);

    for (int i = 0; i < E; i++) {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        graph[a1].push_back({ a2, a3 });
    }

    vector<int> distances = dijkstra(graph, K, V);

    for (int i = 1; i <= V; i++) {
        if (distances[i] == INF) {
            cout << "INF\n";
        }
        else {
            cout << distances[i] << '\n';
        }
    }

    return 0;
}