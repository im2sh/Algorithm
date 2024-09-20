#include <iostream>

using namespace std;

typedef long long ll;
constexpr ll MOD = 1000000007;

ll A, X, ret = 1;
ll DP[104];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> A >> X;
    DP[1] = A % MOD;
    DP[2] = (DP[1] * DP[1]) % MOD;
    DP[2] %= MOD;
}

void solve() {
    for (int i = 3; i <= 65; i++) {
        DP[i] = DP[i - 1] % MOD * DP[i - 1] % MOD;
        DP[i] %= MOD;
    }
    for (int i = 0; i < 63; i++) {
        if (X & (1LL << i)) {
            ret *= DP[i + 1] % MOD;
            ret %= MOD;
        }
    }
    cout << ret % MOD;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
