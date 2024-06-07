#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int N, ret = 0;
int last = 600;
vector<pair<int, int>> rides;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    rides.resize(N + 1);
}

int go(int k) {
    int h = k / 100;
    int m = k % 100;
    return h * 60 + m;
}

void solve() {
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        rides[i].first = go(k) - 10;
        cin >> k;
        rides[i].second = go(k) + 10;
    }
    rides[N] = {1320, INT_MAX};
    sort(rides.begin(), rides.end());
    for (int i = 0; i < rides.size(); i++) {
        ret = max(ret, rides[i].first - last);
        last = max(last, rides[i].second);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}