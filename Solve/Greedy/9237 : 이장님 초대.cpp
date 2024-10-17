#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ret;
vector<int> tree;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool cmp(int a, int b) {
    return a > b;
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        tree.push_back(temp);
    }
    sort(tree.begin(), tree.end(), cmp);
}

void solve() {
    for (int i = 0; i < tree.size(); i++) {
        ret = max(ret, tree[i] + i);
    }
    cout << ret + 2;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}