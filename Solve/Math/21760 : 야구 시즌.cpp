#include <iostream>

using namespace std;

typedef long long ll;

int TC, N, M, K, D;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    cin >> N >> M >> K >> D;
}

void solve() {
    while (TC--) {
        Input();
        int S = N * M;

        ll num = S * K * (M - 1) / 2;
        num += S * (S - M) / 2;

        int ret = D / num;
        if (ret == 0)
            cout << -1 << '\n';
        else
            cout << ret * num << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}