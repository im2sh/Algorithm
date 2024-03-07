#include <iostream>

using namespace std;
typedef long long ll;

int TC, N;
ll DP[101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
    DP[1] = DP[2] = DP[3] = 1;
    DP[4] = DP[5] = 2;
    for (int i = 6; i < 101; i++) {
        DP[i] = DP[i - 5] + DP[i - 1];
    }
}

void solve() {
    while (TC--) {
        cin >> N;
        cout << DP[N] << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}