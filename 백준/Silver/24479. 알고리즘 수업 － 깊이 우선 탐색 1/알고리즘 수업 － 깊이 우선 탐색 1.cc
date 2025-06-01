#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

void dfs(int start, vector<vector<int>>& graph) {
    stack<int> s;
    vector<int> visited(graph.size(), 0);
    int count = 1;

    s.push(start);

    while (!s.empty())
    {
        int num = s.top();
        s.pop();

        if (visited[num] != 0) continue;

        visited[num] = count++;

        for (int n : graph[num])
        {
            if (visited[n] == 0)
            {
                s.push(n);
            }
        }
    }

    for (int i = 1; i < visited.size(); ++i) {
        cout << visited[i] << '\n';
    }
}


int main(void) {
    int n, m, r;    // 정점 수, 간선 수, 시작 정점
    cin >> n >> m >> r;
    vector<vector<int>> graph(n + 1);

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i < n + 1; ++i) {
        sort(graph[i].rbegin(), graph[i].rend());
    }

    dfs(r, graph);

    return 0;
}
