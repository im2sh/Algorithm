#include <iostream>

#define MAX_SIZE 1000001

using namespace std;

long long N;
long long A, B, C;
long long tree[4000001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}


void updateTree(int node, int start, int end, long long idx, long long num) {
    if (idx < start or idx > end) {
        return;
    }

    if (start == idx and end == idx) {
        tree[node] += num;
        return;
    }

    updateTree(node * 2, start, (start + end) / 2, idx, num);
    updateTree(node * 2 + 1, (start + end) / 2 + 1, end, idx, num);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long sumTree(int node, int start, int end, long long num) {
    if (start == end) {
        updateTree(1, 0, MAX_SIZE - 1, start, -1);
        return start + 1;
    }

    if (tree[node * 2] < num) {
        return sumTree(node * 2 + 1, (start + end) / 2 + 1, end, num - tree[node * 2]);
    } else {
        return sumTree(node * 2, start, (start + end) / 2, num);
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        cin >> A;
        if (A & 1) {
            cin >> B;
            cout << sumTree(1, 0, MAX_SIZE - 1, B) << "\n";
        } else {
            cin >> B >> C;
            updateTree(1, 0, MAX_SIZE - 1, B - 1, C);
        }
    }
}

int main() {
    FastIO();
    Init();
    solve();
    return 0;
}