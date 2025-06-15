#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

void dfs(int node, vector<int>& student,vector<int>& visited, int& count) {
    visited[node] = 1;  // Visit
    
    int next = student[node];
    if (visited[next] == 0)
    {
        dfs(next, student, visited, count);
    }
    else if (visited[next] == 1)
    {
        int start = next;
        for (start; start != node; start = student[start])
            count++;
        count++;

    }

    visited[node] = 2;
}

int main(void) {
    int count;
    cin >> count;

    int n, ans = 0;
    while (count--)
    {
        ans = 0;

        cin >> n;
        vector<int> p(n + 1, 0);
        vector<int> visited(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }

        for (int i = 1; i <= n; ++i) {
            if (visited[i] == 0)    // Not Visited
                dfs(i, p, visited, ans);
        }
        cout << n - ans << endl;
    }

    return 0;
}