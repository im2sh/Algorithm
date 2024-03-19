#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

typedef struct pos {
    int y;
    int x;
} Pos;

typedef struct block {
    vector<Pos> P;
    vector<Pos> rainbow;
    Pos standard;
} Block;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int N, M, ret;
int BOARD[21][21];
int visited[21][21];
vector<Block> B;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> BOARD[y][x];
        }
    }
}

bool check() {
    for (int i = 0; i < B.size(); i++) {
        int cnt = 0;
        cnt = B[i].P.size() + B[i].rainbow.size();
        if (cnt >= 2)
            return false;
    }
    return true;
}

bool standardCmp(Pos a, Pos b) {
    if (a.y != b.y)
        return a.y < b.y;
    return a.x < b.x;
}

void bfs(int y, int x) {
    vector<Pos> P;
    vector<Pos> rainbow;
    Pos standard;
    queue<Pos> q;
    P.push_back({y, x});
    q.push({y, x});
    visited[y][x] = 1;

    while (q.size()) {
        int cy = q.front().y;
        int cx = q.front().x;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || BOARD[ny][nx] == -1 || BOARD[ny][nx] == 10)
                continue;
            if (BOARD[ny][nx] == 0)
                rainbow.push_back({ny, nx});
            else if (BOARD[ny][nx] == BOARD[y][x])
                P.push_back({ny, nx});
            else
                continue;
            q.push({ny, nx});
            visited[ny][nx] = 1;
        }
    }

    sort(P.begin(), P.end(), standardCmp);
    standard = P[0];
    for (int i = 0; i < rainbow.size(); i++) {
        visited[rainbow[i].y][rainbow[i].x] = 0;
    }

    B.push_back({P, rainbow, standard});
}

bool selectBlockCmp(Block a, Block b) {
    if (a.P.size() + a.rainbow.size() != b.P.size() + b.rainbow.size())
        return a.P.size() + a.rainbow.size() > b.P.size() + b.rainbow.size();
    else {
        if (a.rainbow.size() != b.rainbow.size()) {
            return a.rainbow.size() > b.rainbow.size();
        } else {
            if (a.standard.y != b.standard.y)
                return a.standard.y > b.standard.y;
            else
                return a.standard.x > b.standard.x;
        }
    }
}

void findBlockGroup() {
    B.clear();
    fill(&visited[0][0], &visited[0][0] + 21 * 21, 0);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (BOARD[y][x] > 0 && !visited[y][x] && BOARD[y][x] != 10)
                bfs(y, x);
        }
    }

    sort(B.begin(), B.end(), selectBlockCmp);
}

void deleteGroup() {
    int cnt = 0;
    for (int i = 0; i < B[0].P.size(); i++) {
        BOARD[B[0].P[i].y][B[0].P[i].x] = 10;
        cnt++;
    }
    for (int i = 0; i < B[0].rainbow.size(); i++) {
        BOARD[B[0].rainbow[i].y][B[0].rainbow[i].x] = 10;
        cnt++;
    }
    ret += pow(cnt, 2);
}

void goDown() {
    for (int x = 0; x < N; x++) {
        int blank = 0;
        for (int y = N - 1; y >= 0; y--) {
            if (BOARD[y][x] == -1) {
                blank = 0;
            } else if (BOARD[y][x] == 10) {
                blank++;
            } else {
                if (blank == 0)
                    continue;
                BOARD[y + blank][x] = BOARD[y][x];
                BOARD[y][x] = 10;
            }
        }
    }
}

void rotateClock() {
    int COPY_BOARD[21][21];
    memcpy(COPY_BOARD, BOARD, sizeof(BOARD));
    int sy = N - 1;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            BOARD[y][x] = COPY_BOARD[x][sy];
        }
        sy--;
    }
}

void display() {
    cout << B[0].standard.y << ' ' << B[0].standard.x << '\n';
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << BOARD[y][x] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void solve() {
    while (true) {
        findBlockGroup();
        if (check())
            break;
        deleteGroup();
        goDown();
        rotateClock();
        goDown();
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}