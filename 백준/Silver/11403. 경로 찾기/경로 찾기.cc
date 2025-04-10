#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int size;
    cin >> size;
    vector<vector<int>> graph(size, vector<int>(size, 0));
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            cin >> graph[i][j];
    }

    for (int k = 0; k < size; ++k) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (graph[i][k] && graph[k][j])
                {
                    graph[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            cout << graph[i][j] << " ";
        cout << '\n';
    }
    

    return 0;
}