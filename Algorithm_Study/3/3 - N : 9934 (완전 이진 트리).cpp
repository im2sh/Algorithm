//
// Created by 이석환 on 2023/05/03.
//
#include <iostream>
#include <vector>

using namespace std;

int K;
vector<int> tree;
vector<int> ret[11];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> K;
    for (int i = 0; i < (2 << K - 1) - 1; i++) {
        cin >> temp;
        tree.push_back(temp);
    }
}

void solve(int depth, int left, int right) {
    if (depth == K)
        return;

    int mid = (left + right) / 2;
    ret[depth].push_back(tree[mid]);
    solve(depth + 1, left, mid - 1);
    solve(depth + 1, mid + 1, right);
}

int main(void) {
    FastIO();
    Init();
    solve(0, 0, tree.size());
    for (int i = 0; i < K; i++) {
        for (auto &it: ret[i])
            cout << it << " ";
        cout << "\n";
    }
    return 0;
}