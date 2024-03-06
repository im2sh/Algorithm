#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int N, M;
int BOARD[1001][1001];
int visited[1001][1001][2];
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp = "";
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        for (int j = 0; j < M; j++) {
            BOARD[i][j] = temp[j] - '0';
        }
    }
}

int bfs(int y, int x) {
    queue<pair<pair<int, int>, int>> q;
    visited[y][x][0] = 1;
    q.push({{y, x}, 0});

    while (q.size()) {
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int wallIsBroken = q.front().second;
        q.pop();

        if (cy == N - 1 && cx == M - 1)
            return visited[cy][cx][wallIsBroken];

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx][wallIsBroken])
                continue;
            if (BOARD[ny][nx] == 0) {
                visited[ny][nx][wallIsBroken] = visited[cy][cx][wallIsBroken] + 1;
                q.push({{ny, nx}, wallIsBroken});
            } else if (BOARD[ny][nx] == 1 && wallIsBroken == 0) {
                visited[ny][nx][wallIsBroken + 1] = visited[cy][cx][wallIsBroken] + 1;
                q.push({{ny, nx}, wallIsBroken + 1});
            }
        }
    }

    return -1;
}

void display() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cout << visited[y][x][1] << ' ';
        }
        cout << '\n';
    }
}

void solve() {
    cout << bfs(0, 0) << '\n';
    display();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}