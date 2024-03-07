#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int N, M, K;
int visited[1001][1001][11];
int BOARD[1001][1001];

typedef struct pos {
    int y;
    int x;
    int wallIsBroken;
    bool time; // true면 낮, false면 밤
} Pos;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp;
    cin >> N >> M >> K;
    for (int y = 0; y < N; y++) {
        cin >> temp;
        for (int x = 0; x < M; x++) {
            BOARD[y][x] = temp[x] - '0';
        }
    }
}

int BFS(int y, int x) {
    queue<pair<Pos, bool>> q;
    Pos p;
    p = {y, x, 0, true};
    visited[y][x][0] = 1;
    q.push({p, false}); // 좌표, 기다렸는지 안 기다렸는지

    while (q.size()) {
        int cy = q.front().first.y;
        int cx = q.front().first.x;
        int wall = q.front().first.wallIsBroken;
        bool time = q.front().first.time;
        bool wating = q.front().second;
        q.pop();

        if (cy == N - 1 && cx == M - 1)
            return visited[cy][cx][wall];

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx][wall])
                continue;
            bool nextTime = true;
            if (time == true)
                nextTime = false;
            else
                nextTime = true;
            if (BOARD[ny][nx] == 0) {
                Pos nextP = {ny, nx, wall, nextTime};
                q.push({nextP, false});
                visited[ny][nx][wall] = visited[cy][cx][wall] + 1;
            } else if (BOARD[ny][nx] == 1 && time && wall < K) {
                if (visited[ny][nx][wall + 1])
                    continue;
                Pos nextP = {ny, nx, wall + 1, nextTime};
                q.push({nextP, false});
                if (wating)
                    visited[ny][nx][wall + 1] = visited[cy][cx][wall] + 2;
                else
                    visited[ny][nx][wall + 1] = visited[cy][cx][wall] + 1;
            } else if (BOARD[ny][nx] == 1 && !time && wall < K) {
                Pos nextP = {cy, cx, wall, nextTime};
                q.push({nextP, true});
            }
        }
    }
    return -1;
}

void solve() {
    cout << BFS(0, 0);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}