#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int BOARD[51][51];
int N, M;
int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int ret = -1;
int visited[51][51];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    cin >> N >> M;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> BOARD[y][x];
        }
    }
}

int bfs(int x, int y) {
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {x, y}});
    visited[y][x] = 1;
    fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
    while (!q.empty()) {
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        int temp = q.front().first;
        q.pop();

        if (BOARD[cy][cx] == 1) {
            return temp;
        }

        for (int dir = 0; dir < 8; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
                continue;

            visited[ny][nx] = 1;
            q.push({temp + 1, {nx, ny}});
        }
    }
}

void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (BOARD[y][x] == 0) {
                ret = max(ret, bfs(x, y));
            }
        }
    }
}

int main() {
    FastIO();
    init();
    solve();
    cout << ret;
    return 0;
}