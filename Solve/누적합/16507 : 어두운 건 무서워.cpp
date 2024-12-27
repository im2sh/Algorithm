#include <iostream>

using namespace std;

int R, C, Q;
int BOARD[1001][1001];
int prefixSum[1001][1001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> R >> C >> Q;
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            cin >> BOARD[y][x];
        }
    }
}

void solve() {
    for (int i = 1; i <= R; i++) {
        for (int j = 0; j <= C; j++) {
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + BOARD[i - 1][j - 1];
        }
    }

    for (int i = 0; i < Q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << (prefixSum[r2][c2] - prefixSum[r1 - 1][c2] - prefixSum[r2][c1 - 1] + prefixSum[r1 - 1][c1 - 1]) /
                ((r2 - r1 + 1) * (c2 - c1 + 1)) << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}