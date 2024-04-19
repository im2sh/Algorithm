#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, ret;
vector<pair<int, int>> times;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        times.push_back({s, e});
    }
    sort(times.begin(), times.end());
}

void solve() {
    int prev_s = times[0].first;
    int prev_e = times[0].second;

    for (int i = 1; i < N; i++) {
        int cur_s = times[i].first;
        int cur_e = times[i].second;

        if (prev_s < cur_s && prev_e > cur_e)
            continue;
        if (cur_s <= prev_e) {
            prev_e = cur_e;
        } else if (cur_s > prev_e) {
            ret += abs(prev_e - prev_s);
            prev_s = cur_s;
            prev_e = cur_e;
        }
    }
    ret += abs(prev_e - prev_s);

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
