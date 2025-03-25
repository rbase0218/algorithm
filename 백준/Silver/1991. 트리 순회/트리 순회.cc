#include <iostream>
#include <vector>
#include <map>
using namespace std;

void preorder(map<char, pair<char, char>>& tree, char node) {
    if (node == '.') return;
    cout << node;
    preorder(tree, tree[node].first);
    preorder(tree, tree[node].second);
}

void inorder(map<char, pair<char, char>>& tree, char node) {
    if (node == '.') return;
    inorder(tree, tree[node].first);
    cout << node;
    inorder(tree, tree[node].second);
}

void postorder(map<char, pair<char, char>>& tree, char node) {
    if (node == '.') return;
    postorder(tree, tree[node].first);
    postorder(tree, tree[node].second);
    cout << node;
}

int main() {
    int n;
    cin >> n;

    map<char, pair<char, char>> tree;

    for (int i = 0; i < n; i++) {
        char node, left, right;
        cin >> node >> left >> right;
        tree[node] = make_pair(left, right);
    }

    preorder(tree, 'A'); cout << "\n";
	inorder(tree, 'A'); cout << "\n";
    postorder(tree, 'A');

    return 0;
}