#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int computer_count, connect_count;
    cin >> computer_count >> connect_count;

    vector<vector<int>> graph(computer_count + 1, vector<int>(computer_count + 1, 0));

    for (int i = 0; i < connect_count; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1;
    }

    vector<bool> visit(computer_count + 1, false);

    int sum = 0;
    queue<int> q;
    q.push(1);
    visit[1] = true;

    while (!q.empty()) {
        int s = q.front();
        q.pop();

        for (int i = 1; i <= computer_count; i++) {
            if (graph[s][i] == 1 && !visit[i]) {
                visit[i] = true;
                sum++;
                q.push(i);
            }
        }
    }

    cout << sum << endl;

    return 0;
}