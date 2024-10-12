#include <iostream>
#include <algorithm>

using namespace std;

int N, M, ret;
int BOARD[301][301];
int DP[301][301];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            cin >> BOARD[y][x];
        }
    }
}

void solve() {
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            DP[y][x] = max(DP[y][x], DP[y - 1][x] + BOARD[y][x]);
            DP[y][x] = max(DP[y][x], DP[y][x - 1] + BOARD[y][x]);
            ret = max(ret, DP[y][x]);
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