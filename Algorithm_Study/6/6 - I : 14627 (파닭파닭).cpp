#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;
ll S, C, len, ret;
ll low = 1;
ll high = 1;
vector<ll> vegetable;


void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    ll temp;
    cin >> S >> C;
    for (int i = 0; i < S; i++) {
        cin >> temp;
        vegetable.push_back(temp);
        high = max(high, temp);
    }
}

bool go(ll mid) {
    int sum = 0;
    for (int i = 0; i < S; i++) {
        sum += vegetable[i] / mid;
    }
    if (sum >= C)
        return true;
    return false;
}

void solve() {
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (go(mid)) {
            low = mid + 1;
            len = mid;
        } else {
            high = mid - 1;
        }
    }

    for (int i = 0; i < S; i++) {
        ret += vegetable[i];
    }
    cout << ret - (len * C);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}