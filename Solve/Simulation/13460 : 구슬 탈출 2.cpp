#include <iostream>
#include <queue>

using namespace std;

typedef struct ball {
    int ry, rx, by, bx, cnt;
} Ball;

typedef struct moving {
    int y, x, cnt;
} Moving;

const int dy[4] = {0, 1, -1, 0};
const int dx[4] = {1, 0, 0, -1};

int R, C;
string BOARD[11];
Ball BALL;
pair<int, int> dest;
int visited[11][11][11][11];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp;
    cin >> R >> C;
    for (int y = 0; y < R; y++) {
        cin >> temp;
        BOARD[y] = temp;
        for (int x = 0; x < C; x++) {
            if (BOARD[y][x] == 'R') {
                BALL.ry = y;
                BALL.rx = x;
            } else if (BOARD[y][x] == 'B') {
                BALL.by = y;
                BALL.bx = x;
            } else if (BOARD[y][x] == 'O')
                dest = {y, x};
        }
    }
    BALL.cnt = 0;
}


Moving moveBall(int y, int x, int dir) {
    int cnt = 0;

    while (1) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (BOARD[ny][nx] == '#') {
            break;
        }
        if (BOARD[ny][nx] == 'O')
            return {ny, nx, cnt + 1};
        y = ny;
        x = nx;
        cnt++;
    }
    return {y, x, cnt};
}

Moving moveBack(Moving ball, int dir) {
    if (dir == 0)
        ball.x -= 1;
    else if (dir == 1)
        ball.y -= 1;
    else if (dir == 2)
        ball.y += 1;
    else
        ball.x += 1;
    return ball;
}

void solve() {
    queue<Ball> q;
    q.push(BALL);
    visited[BALL.ry][BALL.rx][BALL.by][BALL.bx] = 1;

    while (q.size()) {
        Ball cur = q.front();
        q.pop();
        if (cur.cnt > 9) {
            cout << "-1";
            return;
        }
        Moving redMoving;
        Moving blueMoving;
        for (int dir = 0; dir < 4; dir++) {
            redMoving = moveBall(cur.ry, cur.rx, dir);
            blueMoving = moveBall(cur.by, cur.bx, dir);
            if (blueMoving.y == dest.first && blueMoving.x == dest.second) {
                continue;
            }
            if (redMoving.y == blueMoving.y && redMoving.x == blueMoving.x) {
                if (redMoving.cnt > blueMoving.cnt) {
                    redMoving = moveBack(redMoving, dir);
                } else {
                    blueMoving = moveBack(blueMoving, dir);
                }
            }
            if (visited[redMoving.y][redMoving.x][blueMoving.y][blueMoving.x])
                continue;
            if (redMoving.y == dest.first && redMoving.x == dest.second) {
                cout << cur.cnt + 1;
                return;
            }
            visited[redMoving.y][redMoving.x][blueMoving.y][blueMoving.x] = 1;
            Ball next = {redMoving.y, redMoving.x, blueMoving.y, blueMoving.x, cur.cnt + 1};
            q.push(next);
        }
    }
    cout << "-1";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}