#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    vector<long long> one(n + 1, 0), two(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> one[i];
        one[i] += one[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> two[i];
        two[i] += two[i - 1];
    }

    int a, b;
    a = b = n;
    for (int i = 0; i < m; ++i) {
        if (one[a] > two[b])
            a--;
        else
            b--;
    }

    cout << max(one[a], two[b]);

    return 0;
}