#include <iostream>
#include <queue>

using namespace std;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

typedef struct pos {
    int y;
    int x;
    int dir;
} Pos;

int N, M, K, ret;
int BOARD[21][21];
Pos P;
bool visited[21][21];
int dice[6] = {1, 2, 3, 4, 5, 6};


void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> K;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> BOARD[y][x];
        }
    }
    P.y = 0;
    P.x = 0;
    P.dir = 0;
}

void getDir() {
    if (dice[5] > BOARD[P.y][P.x]) {
        P.dir = (P.dir + 1) % 4;
    } else if (dice[5] < BOARD[P.y][P.x]) {
        P.dir = P.dir - 1;
        if (P.dir == -1)
            P.dir = 3;
    }
}

void move_Right() {
    int temp = dice[2];
    dice[2] = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[5];
    dice[5] = temp;
}

void move_Left() {
    int temp = dice[3];
    dice[3] = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[5];
    dice[5] = temp;
}

void move_Down() {
    int temp = dice[5];
    dice[5] = dice[4];
    dice[4] = dice[0];
    dice[0] = dice[1];
    dice[1] = temp;
}

void move_Up() {
    int temp = dice[1];
    dice[1] = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[5];
    dice[5] = temp;
}

void move() {
    P.y = P.y + dy[P.dir];
    P.x = P.x + dx[P.dir];

    if (P.y < 0 || P.y >= N || P.x < 0 || P.x >= M) {
        P.dir = (P.dir + 2) % 4;
        if (P.y < 0)
            P.y = 0;
        if (P.x < 0)
            P.x = 0;
        if (P.y >= N)
            P.y = N - 1;
        if (P.x >= M)
            P.x = M - 1;
        P.y = P.y + dy[P.dir];
        P.x = P.x + dx[P.dir];
    }

    if (P.dir == 0)
        move_Right();
    else if (P.dir == 1)
        move_Down();
    else if (P.dir == 2)
        move_Left();
    else
        move_Up();
}

void getScore() {
    fill(&visited[0][0], &visited[0][0] + 21 * 21, false);
    queue<pair<int, int>> q;
    int cnt = 1;
    q.push({P.y, P.x});
    visited[P.y][P.x] = true;

    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
                continue;
            if (BOARD[P.y][P.x] == BOARD[ny][nx]) {
                q.push({ny, nx});
                cnt++;
                visited[ny][nx] = true;
            }
        }
    }

    ret += (BOARD[P.y][P.x] * cnt);
}

void solve() {
    while (K--) {
        move();
        getScore();
        getDir();
    }
    cout << ret;
}

int main() {
    FastIO();
    Init();
    solve();
    return 0;
}