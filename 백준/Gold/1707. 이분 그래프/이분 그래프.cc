#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

#define RED 1
#define BLUE 2

bool dfs(vector<vector<int>>& graph, vector<int>& visited, int node, int color)
{
    visited[node] = color;
    for (auto g : graph[node])
    {
        if (visited[g] == 0)
        {
            if (!dfs(graph, visited, g, (color == RED) ? BLUE : RED))
                return false;
        }
        else if (visited[g] == color)
            return false;
    }
    return true;
}

int main(void) {
    int t;
    cin >> t;

    int v, e;
    while (t--)
    {
        cin >> v >> e;
        vector<vector<int>> graph(v + 1);
        vector<int> visited(v + 1, 0);

        for (int i = 0; i < e; ++i) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        bool checked = true;
        for (int i = 1; i <= v; ++i) {
            if (visited[i]) continue;
            if (!dfs(graph, visited, i, RED))
            {
                checked = false;
                break;
            }
        }
        if (checked) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    return 0; 
}
