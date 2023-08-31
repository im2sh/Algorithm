#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int ret = 987654321;
int BOARD[8][8];
int CCTV_SIZE;
pair<pair<int, int>, int> CCTV[8];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
const int dirIdx[5] = {4, 2, 4, 4, 1};

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
            if (BOARD[y][x] != 0 && BOARD[y][x] != 6) {
                CCTV[CCTV_SIZE++] = {{y, x}, BOARD[y][x] - 1};
            }
        }
    }
}

int calcu() {
    int sum = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (BOARD[y][x] == 0)
                sum++;
        }
    }
    return sum;
}

void move(pair<int, int> CC, int dir) {
    dir = dir % 4;
    int cy = CC.first;
    int cx = CC.second;

    switch (dir) {
        case 0:
            for (int y = cy - 1; y >= 0; y--) {
                if (BOARD[y][cx] == 6)
                    break;
                BOARD[y][cx] = -1;
            }
            break;

        case 1:
            for (int x = cx + 1; x < M; x++) {
                if (BOARD[cy][x] == 6)
                    break;
                BOARD[cy][x] = -1;
            }
            break;
        case 2:
            for (int y = cy + 1; y < N; y++) {
                if (BOARD[y][cx] == 6)
                    break;
                BOARD[y][cx] = -1;
            }
            break;
        case 3:
            for (int x = cx - 1; x >= 0; x--) {
                if (BOARD[cy][x] == 6)
                    break;
                BOARD[cy][x] = -1;
            }
            break;
    }
}

void go(int depth) {
    if (depth == CCTV_SIZE) {
        ret = min(ret, calcu());
        return;
    }

    int backup[8][8];
    int num = CCTV[depth].second;
    for (int dir = 0; dir < dirIdx[num]; dir++) {
        memcpy(backup, BOARD, sizeof(backup));
        switch (num) {
            case 0:
                move(CCTV[depth].first, dir);
                break;
            case 1:
                move(CCTV[depth].first, dir);
                move(CCTV[depth].first, dir + 2);
                break;
            case 2:
                move(CCTV[depth].first, dir);
                move(CCTV[depth].first, dir + 1);
                break;
            case 3:
                move(CCTV[depth].first, dir);
                move(CCTV[depth].first, dir + 1);
                move(CCTV[depth].first, dir + 3);
                break;
            case 4:
                move(CCTV[depth].first, dir);
                move(CCTV[depth].first, dir + 1);
                move(CCTV[depth].first, dir + 2);
                move(CCTV[depth].first, dir + 3);
                break;
        }
        go(depth + 1);
        memcpy(BOARD, backup, sizeof(BOARD));
    }
}

int main(void) {
    FastIO();
    Init();
    go(0);
    cout << ret << "\n";
    return 0;
}