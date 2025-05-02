#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> tops(n);
    for (int i = 0; i < n; ++i) {
        cin >> tops[i];
    }

    vector<int> ans(n, 0);
    stack<pair<int, int>> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top().first < tops[i]) {
            st.pop();
        }

        if (!st.empty()) {
            ans[i] = st.top().second;
        }

        st.push({ tops[i], i + 1 });
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }

    return 0;
}