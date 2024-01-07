#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

ll N, M, low, high;
ll ret = 987654321;
vector<ll> video;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    ll temp;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        video.push_back(temp);
        high += temp;
        low = max(low, temp);
    }
}

bool getBluelay(ll mid) {
    ll sum = 0;
    ll bulelayCount = 0;
    for (int i = 0; i < N; i++) {
        sum += video[i];
        if (sum > mid) {
            bulelayCount++;
            sum = 0;
            sum += video[i];
        }
    }
    if (sum != 0)
        bulelayCount++;

    if (bulelayCount <= M) {
        return true;
    }
    return false;
}

void solve() {
    ll mid = (low + high) / 2;
    while (low <= high) {
        if (getBluelay(mid)) {
            ret = min(ret, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}