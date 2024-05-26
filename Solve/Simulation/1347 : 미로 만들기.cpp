#include <iostream>

using namespace std;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, -1, 0, 1};
int N;
string command;
bool BOARD[101][101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> command;
}

void solve() {
    int dir = 0;
    int cx = 50, cy = 50;
    int sy = cy, sx = cx, ey = cy, ex = cx;
    BOARD[cy][cx] = true;
    for (int j = 0; j < N; j++) {
        if (command[j] == 'L')
            dir = (dir + 3) % 4;
        else if (command[j] == 'R')
            dir = (dir + 1) % 4;
        else if (command[j] == 'F') {
            cy += dy[dir];
            cx += dx[dir];
            BOARD[cy][cx] = true;

            if (cy < sy)
                sy = cy;
            if (cx < sx)
                sx = cx;
            if (cy > ey)
                ey = cy;
            if (cx > ex)
                ex = cx;
        }
    }

    for (int i = sy; i <= ey; i++) {
        for (int j = sx; j <= ex; j++) {
            if (BOARD[i][j])
                cout << '.';
            else
                cout << '#';
        }
        cout << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}