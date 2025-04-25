#include <iostream>

#define MOD 1000000007

typedef long long ll;

using namespace std;

int N;
ll DP[51];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    DP[0] = 1;
    DP[1] = 1;
}

void solve() {
    for (int i = 2; i <= 50; i++) {
        DP[i] = DP[i - 2] + DP[i - 1] + 1;
    }
    cout << DP[N] % MOD;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}