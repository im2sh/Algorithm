#include <iostream>
#include <queue>

using namespace std;

int W, H;
int BOARD[51][51];
int visited[51][51];
int ret;

int dx[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, -1, 1, -1, 1, 1, -1};

void FastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 8; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= H || nx < 0 || nx >= W)
                continue;
            if (BOARD[ny][nx] && !visited[ny][nx]) {
                q.push({ny, nx});
                visited[ny][nx] = 1;
            }
        }
    }
}

void solve() {
    while (true) {
        cin >> W >> H;
        ret = 0;
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        if (!W && !H)
            break;

        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++)
                cin >> BOARD[y][x];
        }

        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                if (BOARD[y][x] && !visited[y][x]) {
                    visited[y][x] = 1;
                    bfs(y, x);
                    ret++;
                }
            }
        }

        cout << ret << '\n';
    }
}

int main() {
    FastIO();
    solve();
    return 0;
}