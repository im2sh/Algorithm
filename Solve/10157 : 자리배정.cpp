#include <iostream>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int N, M, C;
int BOARD[1004][1004];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> C;
    for (int i = 0; i <= 1001; i++)
        BOARD[i][0] = BOARD[0][i] = BOARD[M + 1][i] = BOARD[i][N + 1] = 1;
}

void solve() {
    int x = 0, y = 1, dir = 0;
    for (int i = 1; i <= N * M; i++) {
        y += dy[dir];
        x += dx[dir];
        BOARD[x][y] = 1;
        if (BOARD[x + dx[dir]][y + dy[dir]])
            dir = (dir + 1) % 4;
        if (i == C) {
            cout << y << " " << x;
            return;
        }
    }

    cout << "0";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}