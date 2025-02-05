#include <iostream>

using namespace std;

int N, K;
int DP[31][31];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int i = 0; i < 31; i++) {
        DP[i][0] = 1;
    }
}

void solve() {
    for (int i = 1; i < 31; i++) {
        for (int j = 1; j <= i; j++) {
            DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
        }
    }
    cout << DP[N - 1][K - 1];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}