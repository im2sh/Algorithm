#include <iostream>

using namespace std;

int R, C, W, ret;
int DP[31][31];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> R >> C >> W;
    DP[1][1] = 1;
}

void solve() {
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || i == j)
                DP[i][j] = 1;
            else
                DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
        }
    }

    for (int i = 0; i < W; i++) {
        for (int j = 0; j <= i; j++) {
            ret += DP[R + i][C + j];
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}