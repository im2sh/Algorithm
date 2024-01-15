#include <iostream>
#include <queue>
#include <algorithm>

const int dh[3] = {-1, 0, 1};
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

using namespace std;

int N, M, H;
int ret = -1;
int BOARD[101][101][101];
queue<pair<int, pair<int, int>>> q;
int visited[101][101][101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                cin >> BOARD[i][y][x];
                if (BOARD[i][y][x] == 1) {
                    q.push({i, {y, x}});
                    visited[i][y][x] = 1;
                }
            }
        }
    }
}

bool check() {
    for (int i = 0; i < H; i++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (BOARD[i][y][x] == 0)
                    return false;
            }
        }
    }
    return true;
}

void BFS() {
    while (q.size()) {
        int ch = q.front().first;
        int cy = q.front().second.first;
        int cx = q.front().second.second;
        q.pop();

        for (int i = 0; i < 3; i++) {
            int nh = dh[i] + ch;
            if (nh < 0 || nh >= H || BOARD[nh][cy][cx] == -1 || visited[nh][cy][cx])
                continue;
            visited[nh][cy][cx] = visited[ch][cy][cx] + 1;
            BOARD[nh][cy][cx] = 1;
            q.push({nh, {cy, cx}});
        }

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || BOARD[ch][ny][nx] == -1 ||
                visited[ch][ny][nx] || BOARD[ch][ny][nx] == 1)
                continue;
            visited[ch][ny][nx] = visited[ch][cy][cx] + 1;
            BOARD[ch][ny][nx] = 1;
            q.push({ch, {ny, nx}});
        }
    }

}

void getMax() {
    for (int i = 0; i < H; i++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                ret = max(ret, visited[i][y][x]);
            }
        }
    }
}

void display() {
    for (int i = 0; i < H; i++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                cout << BOARD[i][y][x] << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
    cout << '\n';
}

void solve() {
    BFS();
    getMax();
    if (check())
        cout << ret - 1;
    else
        cout << -1;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
