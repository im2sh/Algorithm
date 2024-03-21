#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int BOARD[1001][1001];
int DP[1001][1001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> temp;
            BOARD[y][x] = temp;
        }
    }
}

void solve() {
    DP[0][0] = BOARD[0][0];
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            DP[y + 1][x] = max(BOARD[y + 1][x] + DP[y][x], DP[y + 1][x]);
            DP[y][x + 1] = max(BOARD[y][x + 1] + DP[y][x], DP[y][x + 1]);
            DP[y + 1][x + 1] = max(BOARD[y + 1][x + 1] + DP[y][x], DP[y + 1][x + 1]);
        }
    }

    cout << DP[N - 1][M - 1];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}