#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, K, ret;
ll low = 1, high;
vector<ll> bottle;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        ll temp;
        cin >> temp;
        bottle.push_back(temp);
        high = max(temp, high);
    }
}

bool check(int mid) {
    int cnt = 0;
    for (int i = 0; i < bottle.size(); i++) {
        cnt += bottle[i] / mid;
    }

    if (cnt >= K)
        return true;
    return false;
}

void solve() {
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