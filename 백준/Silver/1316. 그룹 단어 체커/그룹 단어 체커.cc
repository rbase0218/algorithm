#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int count = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        vector<bool> seen(26, false);
        char prev = '\0';
        bool isGroup = true;

        for (char c : s) {
            if (c != prev) {
                if (seen[c - 'a']) {
                    isGroup = false;
                    break;
                }
                seen[c - 'a'] = true;
                prev = c;
            }
        }

        if (isGroup) ++count;
    }

    cout << count << '\n';
    return 0;
}
