#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ret;
vector<pair<int, int>> egg;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        egg.push_back({a, b});
    }
}

void dfs(int idx) {
    if (idx == N) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (egg[i].first <= 0) {
                cnt++;
            }
        }
        ret = max(ret, cnt);
        return;
    }

    bool isBreak = false;

    for (int i = 0; i < N; i++) {
        if (i == idx)
            continue;
        if (egg[i].first <= 0 || egg[idx].first <= 0)
            continue;
        egg[i].first -= egg[idx].second;
        egg[idx].first -= egg[i].second;
        isBreak = true;
        dfs(idx + 1);
        egg[i].first += egg[idx].second;
        egg[idx].first += egg[i].second;
    }

    if (!isBreak)
        dfs(idx + 1);
}

void solve() {
    dfs(0);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}