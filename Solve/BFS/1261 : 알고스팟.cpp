#include <iostream>
#include <queue>

using namespace std;

int N, M;
int BOARD[101][101];
int visited[101][101];

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {1, -1, 0, 0};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp;
    cin >> N >> M;
    for (int y = 0; y < M; y++) {
        cin >> temp;
        for (int x = 0; x < N; x++) {
            BOARD[y][x] = temp[x] - '0';
            visited[y][x] = 987654321;
        }
    }
}

void display() {
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            cout << visited[y][x] << ' ';
        }
        cout << '\n';
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

            if (ny < 0 || ny >= M || nx < 0 || nx >= N)
                continue;
            if (BOARD[ny][nx] == 0) {
                if (visited[ny][nx] > visited[cy][cx]) {
                    visited[ny][nx] = visited[cy][cx];
                    q.push({ny, nx});
                }
            } else {
                if (visited[ny][nx] > visited[cy][cx] + 1) {
                    visited[ny][nx] = visited[cy][cx] + 1;
                    q.push({ny, nx});
                }
            }
        }
    }
}

void solve() {
    bfs(0, 0);
    cout << visited[M - 1][N - 1] - 1;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}