#include <iostream>
#include <vector>

using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

typedef struct pos {
    int y, x;
} Pos;

int R, C, N;
string BOARD[3][204];
vector<Pos> bomb;
vector<Pos> secondBomb;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp;
    cin >> R >> C >> N;
    for (int y = 0; y < R; y++) {
        cin >> temp;
        BOARD[0][y] = temp;
        BOARD[1][y] = temp;
        BOARD[2][y] = temp;
        for (int x = 0; x < C; x++) {
            if (BOARD[0][y][x] == 'O')
                bomb.push_back({y, x});
            BOARD[1][y][x] = 'O';
            BOARD[2][y][x] = 'O';
        }
    }
}

void goBomb1() {
    for (int i = 0; i < bomb.size(); i++) {
        int cy = bomb[i].y;
        int cx = bomb[i].x;
        BOARD[1][cy][cx] = '.';
        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C)
                continue;

            BOARD[1][ny][nx] = '.';
        }
    }
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (BOARD[1][y][x] == 'O')
                secondBomb.push_back({y, x});
        }
    }
}

void goBomb2() {
    for (int i = 0; i < secondBomb.size(); i++) {
        int cy = secondBomb[i].y;
        int cx = secondBomb[i].x;
        BOARD[2][cy][cx] = '.';
        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C)
                continue;

            BOARD[2][ny][nx] = '.';
        }
    }
}

void solve() {
    if (N == 1) {
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                cout << BOARD[0][y][x];
            }
            cout << '\n';
        }
        return;
    }
    N = (N - 2) % 4;
    goBomb1();
    goBomb2();

    if (N % 2 == 0) {
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                cout << 'O';
            }
            cout << '\n';
        }
    } else if (N == 1) {
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                cout << BOARD[1][y][x];
            }
            cout << '\n';
        }
    } else {
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                cout << BOARD[2][y][x];
            }
            cout << '\n';
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}