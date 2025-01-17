#include <iostream>

using namespace std;

int N, ret;
int DP[1001][11];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < 10; i++) {
        DP[1][i] = 1;
    }
}

void solve() {
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                DP[i][0] = 1;
                continue;
            }
            DP[i][j] = (DP[i - 1][j] + DP[i][j - 1]) % 10007;
        }
    }

    for (int i = 0; i < 10; i++)
        ret += DP[N][i];

    cout << ret % 10007;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}