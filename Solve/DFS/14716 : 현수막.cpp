#include <iostream>

using namespace std;

const int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int M, N, ret;
int BOARD[251][251];
bool visited[251][251];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> M >> N;
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            cin >> BOARD[y][x];
        }
    }
}

void go(int y, int x) {
    visited[y][x] = true;

    for (int dir = 0; dir < 8; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny >= M || nx < 0 || nx >= N || BOARD[ny][nx] == 0 || visited[ny][nx])
            continue;
        go(ny, nx);
    }
}

void solve() {
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            if (BOARD[y][x] && !visited[y][x]) {
                go(y, x);
                ret++;
            }
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