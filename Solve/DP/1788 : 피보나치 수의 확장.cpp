#include <iostream>

#define MOD 1000000000

using namespace std;

int N, idx;
int DP[1000001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 0;
}

void solve() {
    if (N < 0)
        idx = N * (-1);
    else
        idx = N;
    if (N == 0) {
        cout << 0 << "\n" << 0;
        return;
    }
    for (int i = 2; i <= idx; i++) {
        DP[i] = (DP[i - 1] + DP[i - 2]) % MOD;
    }
    DP[idx] = DP[idx] % MOD;
    if (N < 0) {
        if (idx % 2 == 0) {
            cout << -1 << '\n' << DP[idx];
            return;
        }
    }

    cout << 1 << "\n" << DP[idx];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}