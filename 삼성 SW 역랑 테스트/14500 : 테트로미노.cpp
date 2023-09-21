#include <iostream>
#include <algorithm>

using namespace std;

int N, M, ret;
int BOARD[501][501];
int visited[501][501];

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

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

void dfs(int cy, int cx, int depth, int sum) {
    if (depth == 3) {
        ret = max(ret, sum);
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int ny = cy + dy[dir];
        int nx = cx + dx[dir];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        if (!visited[ny][nx]) {
            visited[ny][nx] = 1;
            dfs(ny, nx, depth + 1, sum + BOARD[ny][nx]);
            visited[ny][nx] = 0;
        }
    }
}

void difficultShape(int cy, int cx) {
    for (int i = 0; i < 4; i++) {
        int sum = BOARD[cy][cx];
        for (int dir = 0; dir < 4; dir++) {
            if (i == dir)
                continue;
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            sum += BOARD[ny][nx];
        }
        ret = max(ret, sum);
    }
}

void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            visited[y][x] = 1;
            dfs(y, x, 0, BOARD[y][x]);
            difficultShape(y, x);
            visited[y][x] = 0;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    cout << ret << "\n";
    return 0;
}