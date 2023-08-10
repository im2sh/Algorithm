#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L, ret;
vector<pair<int, int>> pool;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int x, y;
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        pool.push_back({x, y});
    }
    sort(pool.begin(), pool.end());
}

void solve() {
    int cur = 0;
    for (int i = 0; i < pool.size(); i++) {
        if (cur < pool[i].first)
            cur = pool[i].first;
        while (cur < pool[i].second) {
            cur += L;
            ret++;
        }
    }
    cout << ret << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}