#include <iostream>

using namespace std;

typedef long long ll;

int N;
ll DP[84][2];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    DP[1][0] = 1;
    DP[1][1] = 1;
}

void solve() {
    for (int i = 2; i <= N; i++) {
        if (i % 2 == 0) {
            DP[i][1] = DP[i - 1][0] + DP[i - 1][1];
            DP[i][0] = DP[i - 1][0];
        } else {
            DP[i][0] = DP[i - 1][0] + DP[i - 1][1];
            DP[i][1] = DP[i - 1][1];
        }
    }
    cout << DP[N][0] * 2 + DP[N][1] * 2;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}