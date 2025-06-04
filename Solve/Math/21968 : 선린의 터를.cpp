#include <iostream>
#include <deque>

using namespace std;

typedef long long ll;

int TC;
ll N, ret;
deque<ll> dq;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    dq.clear();
    ret = 0;
    cin >> N;

    while (N > 0) {
        ret *= 3;
        if (N & 1)
            dq.push_back(1);
        else
            dq.push_back(0);
        N >>= 1;
    }
}

void solve() {
    while (TC--) {
        Input();
        ll exp3 = 1;
        while (!dq.empty()) {
            ret += dq.front() * exp3;
            dq.pop_front();
            exp3 *= 3;
        }
        cout << ret << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}