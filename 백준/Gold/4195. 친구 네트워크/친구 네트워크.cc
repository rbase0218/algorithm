#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct DSU {
    vector<int> parent, sz;

    int add_node() {
        int id = static_cast<int>(parent.size());
        parent.push_back(id);
        sz.push_back(1);
        return id;
    }

    DSU() {
        parent.reserve(200000); // 여유 있는 초기 예약
        sz.reserve(200000);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // 경로 압축
    }

    int unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return sz[a];
        if (sz[a] < sz[b]) swap(a, b);     // 크기 기준 union
        parent[b] = a;
        sz[a] += sz[b];
        return sz[a];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int F; 
        cin >> F;

        DSU dsu;
        unordered_map<string, int> id;
        id.reserve(F * 2);
        id.max_load_factor(0.7f);

        while (F--) {
            string a, b;
            cin >> a >> b;

            // 이름이 처음 등장하면 노드 추가
            if (id.find(a) == id.end()) {
                int na = dsu.add_node();
                id[a] = na;
            }
            if (id.find(b) == id.end()) {
                int nb = dsu.add_node();
                id[b] = nb;
            }

            int ans = dsu.unite(id[a], id[b]);
            cout << ans << '\n';
        }
    }
    return 0;
}
