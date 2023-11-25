#include <iostream>
#include <map>

using namespace std;

int n;
char leftChild, node, rightChild;
map<char, pair<char, char>> tree;


void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> node >> leftChild >> rightChild;
        tree[node] = make_pair(leftChild, rightChild);
    }
}

void preorder(char node) {
    cout << node;
    if (tree[node].first != '.') {
        preorder(tree[node].first);
    }
    if (tree[node].second != '.') {
        preorder(tree[node].second);
    }
}

void inorder(char node) {
    if (tree[node].first != '.') {
        inorder(tree[node].first);
    }
    cout << node;
    if (tree[node].second != '.') {
        inorder(tree[node].second);
    }
}

void postorder(char node) {
    if (tree[node].first != '.') {
        postorder(tree[node].first);
    }
    if (tree[node].second != '.') {
        postorder(tree[node].second);
    }
    cout << node;
}

void solve() {
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
