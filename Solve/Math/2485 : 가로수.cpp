#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, gcd, ret;
vector<int> tree;
int tree_dist[100004];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        tree.push_back(temp);
    }

    sort(tree.begin(), tree.end());

    for (int i = 0; i < N - 1; i++) {
        tree_dist[i] = tree[i + 1] - tree[i];
    }
}

int go(int a, int b) {
    int r = a % b;
    if (r == 0)
        return b;
    else
        return go(b, r);
}

void solve() {
    gcd = tree_dist[0];
    for (int i = 1; i < N - 1; i++) {
        gcd = go(gcd, tree_dist[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        ret += (tree_dist[i] / gcd) - 1;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}