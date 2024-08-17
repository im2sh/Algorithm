#include <iostream>
#include <algorithm>

using namespace std;

int N, M, ret = 1000;
int BOARD[7][7];
int DP[7][7][3];;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> BOARD[y][x];
            DP[y][x][0] = DP[y][x][1] = DP[y][x][2] = BOARD[y][x];
            if (x == 0)
                DP[y][x][0] = 1000;
            if (x == M - 1)
                DP[y][x][2] = 1000;
        }
    }
}

void solve() {
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j != 0)
                DP[i][j][0] += min(DP[i - 1][j - 1][1], DP[i - 1][j - 1][2]);
            DP[i][j][1] += min(DP[i - 1][j][0], DP[i - 1][j][2]);

            if (j != M - 1)
                DP[i][j][2] += min(DP[i - 1][j + 1][0], DP[i - 1][j + 1][1]);
        }
    }

    for (int j = 0; j < M; j++) {
        for (int k = 0; k < 3; k++) {
            ret = min(ret, DP[N - 1][j][k]);
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
