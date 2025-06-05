#include <iostream>

using namespace std;

constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};

int R, C;
int BOARD[5][5];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            cin >> BOARD[y][x];
        }
    }
    cin >> R >> C;
    BOARD[R][C] = -1;
}

bool go(int cy, int cx, int depth, int cnt) {
    if (depth > 3)
        return false;

    if (cnt >= 2)
        return true;

    for (int i = 0; i < 4; ++i) {
        int ny = dy[i] + cy;
        int nx = dx[i] + cx;

        if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
            continue;

        if (BOARD[ny][nx] == -1)
            continue;

        int temp = BOARD[ny][nx];

        BOARD[ny][nx] = -1;

        if (go(ny, nx, depth + 1, cnt + temp))
            return true;

        BOARD[ny][nx] = temp;
    }

    return false;
}

void solve() {
    cout << go(R, C, 0, 0);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}