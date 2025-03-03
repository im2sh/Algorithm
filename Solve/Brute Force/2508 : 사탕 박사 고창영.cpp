#include <iostream>

using namespace std;

int TC;
int R, C, ret;
string BOARD[401];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    ret = 0;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> BOARD[i];
    }
}

void go() {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c + 2 < C; c++) {
            if (BOARD[r][c] == '>' && BOARD[r][c + 1] == 'o' && BOARD[r][c + 2] == '<')
                ret++;
        }
    }

    for (int c = 0; c < C; c++) {
        for (int r = 0; r + 2 < R; r++) {
            if (BOARD[r][c] == 'v' && BOARD[r + 1][c] == 'o' && BOARD[r + 2][c] == '^')
                ret++;
        }
    }
    cout << ret << '\n';
}

void solve() {
    while (TC--) {
        Input();
        go();
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}