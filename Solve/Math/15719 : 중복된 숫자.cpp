#include <iostream>

using namespace std;
typedef long long ll;

ll N, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    ll temp = (N - 1) * N / 2;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        ret += x;
    }
    cout << ret - temp;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}