#include <iostream>

using namespace std;

constexpr int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
constexpr int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int N, M, ret;
char BOARD[201][201];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
}

int go(int y, int x) {
    int cnt = 0;
    for (int dir = 0; dir < 8; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (BOARD[ny][nx] == 'N' || BOARD[ny][nx] == 'S') {
            ny += dy[dir];
            nx += dx[dir];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            if (BOARD[ny][nx] == 'F' || BOARD[ny][nx] == 'T') {
                ny += dy[dir];
                nx += dx[dir];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                    continue;
                if (BOARD[ny][nx] == 'P' || BOARD[ny][nx] == 'J') {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> BOARD[y][x];
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (BOARD[y][x] == 'E' || BOARD[y][x] == 'I') {
                ret += go(y, x);
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