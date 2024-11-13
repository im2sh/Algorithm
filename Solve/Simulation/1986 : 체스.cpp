#include <iostream>

using namespace std;

constexpr int qdy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
constexpr int qdx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

constexpr int kdy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
constexpr int kdx[8] = {1, 2, 2, 1, -1, -2, -2, -1};


int N, M, ret;
int qCnt, kCnt, pCnt;
int BOARD[1004][1004]; // 0 = 빈칸, 1 = 퀸, 2 = 나이트, 3 = 폰

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    cin >> qCnt;
    for (int i = 0; i < qCnt; i++) {
        int a, b;
        cin >> a >> b;
        BOARD[a - 1][b - 1] = 1;
    }
    cin >> kCnt;
    for (int i = 0; i < kCnt; i++) {
        int a, b;
        cin >> a >> b;
        BOARD[a - 1][b - 1] = 2;
    }
    cin >> pCnt;
    for (int i = 0; i < pCnt; i++) {
        int a, b;
        cin >> a >> b;
        BOARD[a - 1][b - 1] = 3;
    }
}

void qMove(int y, int x) {
    for (int dir = 0; dir < 8; dir++) {
        int cy = y;
        int cx = x;
        while (true) {
            int ny = cy + qdy[dir];
            int nx = cx + qdx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                break;
            if (BOARD[ny][nx] == 1 || BOARD[ny][nx] == 2 || BOARD[ny][nx] == 3)
                break;
            BOARD[ny][nx] = 4;
            cy = ny;
            cx = nx;
        }
    }
}

void kMove(int y, int x) {
    for (int dir = 0; dir < 8; dir++) {
        int ny = y + kdy[dir];
        int nx = x + kdx[dir];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        if (BOARD[ny][nx] == 1 || BOARD[ny][nx] == 2 || BOARD[ny][nx] == 3)
            continue;
        BOARD[ny][nx] = 4;
    }
}

void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (BOARD[y][x] == 1)
                qMove(y, x);
            else if (BOARD[y][x] == 2)
                kMove(y, x);
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (BOARD[y][x] == 0)
                ret++;
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