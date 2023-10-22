#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, M, K;
int BOARD[101][101];
int visited[101][101];
int cnt = 0;
int ret = 0;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> K;
    N = N;
    M = M;
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;

        BOARD[a - 1][b - 1] = 1;
    }
}

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;

    cnt = 1;

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dx[dir];
            int nx = cx + dy[dir];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            if (visited[ny][nx] == 0 && BOARD[ny][nx] == 1) {
                visited[ny][nx] = 1;
                cnt++;
                q.push({ny, nx});
            }
        }
    }
}

void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (BOARD[y][x] == 1 && visited[y][x] == 0) {
                cnt = 0;
                bfs(y, x);
                ret = cnt > ret ? cnt : ret;
            }
        }
    }
}

int main() {
    FastIO();
    Init();
    solve();
    cout << ret;
    return 0;
}