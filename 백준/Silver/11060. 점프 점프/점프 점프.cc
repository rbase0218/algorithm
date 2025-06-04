#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> num(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
    }

    queue<pair<int, int>> q;
    vector<bool> visited(n + 1, false);

    q.push({ 1, 0 });
    visited[1] = true;

    while (!q.empty())
    {
        int pos = q.front().first;
        int jump = q.front().second;
        q.pop();

        if (pos == n) {
            cout << jump;
            return 0;
        }

        for (int i = 1; i <= num[pos]; ++i) {
            int nextPos = pos + i;

            if (nextPos <= n && !visited[nextPos])
            {
                visited[nextPos] = true;
                q.push({ nextPos, jump + 1 });
            }
        }
    }

    cout << -1 << endl;

    return 0; 
}