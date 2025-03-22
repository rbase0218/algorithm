#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<int> parent;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;

    for (int next : tree[node]) {
        if (!visited[next]) {
            parent[next] = node;
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int n1, n2;
    cin >> N;

    tree.resize(N + 1);
    parent.resize(N + 1, 0);
    visited.resize(N + 1, false);

    for (int i = 0; i < N - 1; i++) {
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }

    dfs(1);

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}