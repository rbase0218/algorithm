#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
        }

        cout << n - 1 << '\n';
    }

    return 0;
}