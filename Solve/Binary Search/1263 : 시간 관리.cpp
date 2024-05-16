#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, ret = -1;
vector<pair<int, int>> times;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        times.push_back({a, b});
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

bool check(ll mid) {
    ll start = mid;
    for (int i = 0; i < N; i++) {
        if (start + times[i].first > times[i].second)
            return false;
        start += times[i].first;
    }
    return true;
}

void solve() {
    sort(times.begin(), times.end(), cmp);
    ll low = 0;
    ll high = 1000000 * 1000;
    
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (check(mid)) {
            ret = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}