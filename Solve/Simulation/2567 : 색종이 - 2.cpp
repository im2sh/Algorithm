#include <iostream>

using namespace std;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};

int board[101][101];
int N, R, C, ret = 0;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    for (int i = 0; i < N; i++) {
        cin >> R >> C;
        for (int y = R; y < R + 10; y++) {
            for (int x = C; x < C + 10; x++) {
                board[y][x] = 1;
            }
        }
    }

    for (int y = 1; y < 101; y++) {
        for (int x = 1; x < 101; x++) {
            if (board[y][x] == 1) {
                for (int dir = 0; dir < 4; dir++) {
                    if (board[y + dy[dir]][x + dx[dir]] == 0)
                        ret++;
                }
            }
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