#include <iostream>

using namespace std;

int TC, N;
int DP[2001][2001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    for (int i = 0; i < 2001; i++) {
        DP[0][i] = 1;
    }
}

void solve() {
    for (int i = 1; i < 2001; i++) {
        for (int j = 1; j < 2001; j++) {
            DP[i][j] = DP[i][j - 1];
            if (i >= j) {
                DP[i][j] += (DP[i - j][j - 1]);
                DP[i][j] %= 100999;
            }
        }
    }

    cin >> TC;

    while (TC--) {
        cin >> N;
        cout << DP[N][N] << '\n';
    }

}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}