#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1);
    int a, b;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        graph[b].push_back(a);
    }

    vector<int> result(n + 1);
    int maxValue = 0;

    for (int i = 1; i <= n; ++i) {
        queue<int> q;
        vector<bool> visited(n + 1, false);
        int count = 0;

        q.push(i);
        visited[i] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            for (auto n : graph[node]) {
                if (visited[n])
                    continue;

                visited[n] = true;
                q.push(n);
            }

            result[i] = count;
            maxValue = max(maxValue, count);
        }

    }
    for (int i = 1; i <= n; ++i) {
        if (result[i] == maxValue)
            cout << i << " ";
    }

    return 0; 
}
