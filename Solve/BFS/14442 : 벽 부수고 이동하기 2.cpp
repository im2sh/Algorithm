#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int dy[4] = {-1, 1, 0, 0};
constexpr int dx[4] = {0, 0, -1, 1};

typedef struct pos {
    int y, x, depth;
} POS;

int N, M, K, ret = 987654321;
int BOARD[1001][1001];
int visited[11][1001][1001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> K;
    for (int y = 0; y < N; y++) {
        string temp;
        cin >> temp;
        for (int x = 0; x < M; x++) {
            BOARD[y][x] = temp[x] - '0';
        }
    }
}

int solve() {
    queue<POS> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1;

    while (q.size()) {
        POS cur = q.front();
        q.pop();
        if (cur.y == N - 1 && cur.x == M - 1)
            return visited[cur.depth][cur.y][cur.x];
        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[cur.depth][ny][nx])
                continue;
            if (BOARD[ny][nx] == 1 && cur.depth < K && !visited[cur.depth + 1][ny][nx]) {
                visited[cur.depth + 1][ny][nx] = visited[cur.depth][cur.y][cur.x] + 1;
                q.push({ny, nx, cur.depth + 1});
            } else if (BOARD[ny][nx] == 0) {
                visited[cur.depth][ny][nx] = visited[cur.depth][cur.y][cur.x] + 1;
                q.push({ny, nx, cur.depth});
            }
        }
    }
    return -1;

}

int main(void) {
    FastIO();
    Init();
    cout << solve();
    return 0;
}