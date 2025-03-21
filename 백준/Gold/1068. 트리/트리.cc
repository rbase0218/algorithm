#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
int deleteNode;

int countLeaf(int node) {
    if (node == deleteNode) return 0;

    bool isLeaf = true;
    int leafCount = 0;

    for (int child : tree[node]) {
        if (child != deleteNode) {
            isLeaf = false;
            leafCount += countLeaf(child);
        }
    }

    if (isLeaf) return 1;

    return leafCount;
}

int main() {
    int n;
    cin >> n;

    tree.resize(n);
    int rootNode = -1;

    for (int i = 0; i < n; i++) {
        int parent;
        cin >> parent;

        if (parent == -1) {
            rootNode = i;
        }
        else {
            tree[parent].push_back(i);
        }
    }

    cin >> deleteNode;

    if (rootNode == deleteNode)
        cout << 0 << endl;
    else
        cout << countLeaf(rootNode) << endl;

    return 0;
}