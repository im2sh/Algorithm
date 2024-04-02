#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};
const int hdy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int hdx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};

typedef struct pos {
    int y, x;
} Pos;

int K, W, H, ret = 987654321;
int BOARD[204][204];
int visited[204][204][34];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> K;
    cin >> W >> H;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            cin >> BOARD[y][x];
        }
    }
}

void solve() {
    fill(&visited[0][0][0], &visited[0][0][0] + 204 * 204 * 34, 987654321);
    queue<pair<Pos, int>> q;
    q.push({{0, 0}, 0});
    visited[0][0][0] = 1;

    while (q.size()) {
        int cy = q.front().first.y;
        int cx = q.front().first.x;
        int jumping = q.front().second;
        q.pop();
        if (jumping > K)
            continue;
        for (int dir = 0; dir < 8; dir++) {
            int ny = cy + hdy[dir];
            int nx = cx + hdx[dir];

            if (ny < 0 || ny >= H || nx < 0 || nx >= W || BOARD[ny][nx] == 1)
                continue;
            if (visited[ny][nx][jumping + 1] > visited[cy][cx][jumping] + 1) {
                q.push({{ny, nx}, jumping + 1});
                visited[ny][nx][jumping + 1] = visited[cy][cx][jumping] + 1;
            }
        }
        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= H || nx < 0 || nx >= W || BOARD[ny][nx] == 1)
                continue;
            if (visited[ny][nx][jumping] > visited[cy][cx][jumping] + 1) {
                q.push({{ny, nx}, jumping});
                visited[ny][nx][jumping] = visited[cy][cx][jumping] + 1;
            }
        }
    }
    for (int i = 0; i <= K; i++) {
        ret = min(ret, visited[H - 1][W - 1][i] - 1);
    }

    if (ret == 987654320) {
        cout << "-1";
    } else
        cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}