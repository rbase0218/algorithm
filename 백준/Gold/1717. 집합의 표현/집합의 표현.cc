#include <iostream>
#include <vector>
using namespace std;

int findParent(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = findParent(parent, parent[x]);
    }
    return parent[x];
}

void unionSets(vector<int>& parent, vector<int>& rank, int a, int b) {
    a = findParent(parent, a);
    b = findParent(parent, b);

    if (a != b) {
        if (rank[a] < rank[b]) {
            parent[a] = b;
        }
        else {
            parent[b] = a;
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 0) {
            unionSets(parent, rank, a, b);
        }
        else if (op == 1) {
            if (findParent(parent, a) == findParent(parent, b)) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}