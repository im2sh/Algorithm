#include <iostream>
#include <vector>

using namespace std;

typedef struct shark {
    int y, x, s, d, z;
} Shark;

typedef struct board {
    vector<Shark> fish;
} BOARD;

int R, C, M, ret;
BOARD B[104][104];
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b, c, d, e;
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c >> d >> e;
        Shark temp;
        temp.y = a - 1;
        temp.x = b - 1;
        if ((d - 1) <= 1)
            temp.s = c % ((R - 1) * 2);
        else
            temp.s = c % ((C - 1) * 2);
        temp.d = d - 1;
        temp.z = e;
        B[a - 1][b - 1].fish.push_back(temp);
    }
}

void findAndCatch(int c) {
    for (int y = 0; y < R; y++) {
        if (B[y][c].fish.size()) {
            ret += B[y][c].fish[0].z;
            B[y][c].fish.clear();
            break;
        }
    }
}


void display() {
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (B[y][x].fish.size()) {
                cout << B[y][x].fish[0].z << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
}

void SharkMove() {
    vector<Shark> ts;
    int ny = 0;
    int nx = 0;
    Shark temp;
    BOARD temp_board[104][104];
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (B[y][x].fish.size())
                ts.push_back(B[y][x].fish[0]);
        }
    }
    for (int i = 0; i < ts.size(); i++) {
        int cy = ts[i].y;
        int cx = ts[i].x;
        int cs = ts[i].s;
        int cd = ts[i].d;
        int cz = ts[i].z;

        ny = cy;
        nx = cx;
        for (int j = 0; j < cs; j++) {
            ny = ny + dy[cd];
            nx = nx + dx[cd];

            if (cd <= 1) {
                if (ny == -1) {
                    cd = 1;
                    ny = 1;
                } else if (ny == R) {
                    cd = 0;
                    ny = R - 2;
                }
            } else {
                if (nx == -1) {
                    cd = 2;
                    nx = 1;
                } else if (nx == C) {
                    cd = 3;
                    nx = C - 2;
                }
            }
        }
        temp = {ny, nx, cs, cd, cz};
        if (!temp_board[ny][nx].fish.size()) {
            temp_board[ny][nx].fish.push_back(temp);
        } else {
            if (temp_board[ny][nx].fish[0].z > temp.z)
                continue;
            else {
                temp_board[ny][nx].fish.pop_back();
                temp_board[ny][nx].fish.push_back(temp);
            }
        }
    }
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            B[y][x] = temp_board[y][x];
        }
    }
}

void solve() {
    for (int i = 0; i <= C; i++) {
        findAndCatch(i);
        SharkMove();
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
