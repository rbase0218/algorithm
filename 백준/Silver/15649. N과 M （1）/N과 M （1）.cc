#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> sequence;
bool visited[9]; 

void makeSequence(int count) {
    if (count == M) {
        for (int i = 0; i < M; i++) {
            cout << sequence[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            sequence.push_back(i);

            makeSequence(count + 1);

            visited[i] = false;
            sequence.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;

    makeSequence(0);

    return 0;
}