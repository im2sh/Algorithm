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
    vector<ll> v(N + 1), pSum(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        pSum[i] = pSum[i - 1] + v[i];
    }
    for (int i = 2; i <= N; i++) {
        ret += v[i] * pSum[i - 1];
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}