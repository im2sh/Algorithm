#include <iostream>

using namespace std;

const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int N, M;
bool isPeak;
int ret;
int BOARD[101][101];
int visited[101][101];

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
        }
    }
}

void go(int y, int x) {
    for (int dir = 0; dir < 8; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        if (BOARD[y][x] < BOARD[ny][nx])
            isPeak = 0;
        if (visited[ny][nx])
            continue;

        if (BOARD[y][x] == BOARD[ny][nx]) {
            visited[ny][nx] = 1;
            go(ny, nx);
        }
    }
}

void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (visited[y][x])
                continue;
            isPeak = 1;
            visited[y][x] = 1;
            go(y, x);
            if (isPeak)
                ret++;
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