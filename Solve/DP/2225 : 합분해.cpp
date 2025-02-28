#include <iostream>

using namespace std;

int N, K;
int DP[204][204];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int i = 1; i <= K; i++) {
        DP[1][i] = i;
    }

    for (int i = 1; i <= N; i++) {
        DP[i][1] = 1;
    }
}

void solve() {
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= K; j++) {
            DP[i][j] = (DP[i - 1][j] + DP[i][j - 1]) % 1000000000;
        }
    }
    cout << DP[N][K];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}