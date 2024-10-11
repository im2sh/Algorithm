#include <iostream>

using namespace std;

constexpr int dy[3] = {0, 1, 1};
constexpr int dx[3] = {1, 0, 1};

int N, ret;
int BOARD[17][17];
bool visited[17][17];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> BOARD[y][x];
        }
    }

}

void go(int y, int x, int dir) {
    if (y == N - 1 && x == N - 1) {
        ret++;
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (dir == 0 && i == 1)
            continue;
        if (dir == 1 && i == 0)
            continue;

        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N || BOARD[ny][nx] == 1)
            continue;
        if (i == 0 || i == 1) {
            if (!visited[ny][nx]) {
                visited[ny][nx] = true;
                go(ny, nx, i);
                visited[ny][nx] = false;
            }
        } else {
            if (!visited[ny][nx] && BOARD[ny - 1][nx] == 0 && BOARD[ny][nx - 1] == 0) {
                visited[ny][nx] = true;
                go(ny, nx, i);
                visited[ny][nx] = false;
            }
        }
    }
}

void solve() {
    go(0, 1, 0);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}