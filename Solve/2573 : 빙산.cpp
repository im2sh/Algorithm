#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int N, M, ret;
int BOARD[301][301];
int COPY_BOARD[301][301];
int visited[301][301];
vector<pair<int, int>> v;

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

void copy_board() {
    fill(&visited[0][0], &visited[0][0] + 301 * 301, 0);
    v.clear();
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            BOARD[y][x] = COPY_BOARD[y][x];
            if (BOARD[y][x] != 0)
                v.push_back({y, x});
        }
    }
}

void go() {
    for (int y = 1; y < N; y++) {
        for (int x = 1; x < M; x++) {
            if (BOARD[y][x] != 0) {
                int cnt = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];

                    if (BOARD[ny][nx] == 0)
                        cnt++;
                }
                COPY_BOARD[y][x] = BOARD[y][x] - cnt;
                if (COPY_BOARD[y][x] < 0)
                    COPY_BOARD[y][x] = 0;
            }
        }
    }
}

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;

    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 1 || ny > N || nx < 1 || nx > M || visited[ny][nx] || BOARD[ny][nx] == 0)
                continue;
            visited[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
}

int check() {
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (!visited[v[i].first][v[i].second]) {
            cnt++;
            bfs(v[i].first, v[i].second);
        }
    }
    return cnt;
}

void solve() {
    while (true) {
        go();
        copy_board();
        ret++;
        int island = check();
        if (island >= 2)
            break;
        else if (island == 0) {
            ret = 0;
            break;
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