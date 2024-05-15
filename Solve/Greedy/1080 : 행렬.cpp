#include <iostream>

using namespace std;

int N, M, ret;
int BOARD[51][51];
int result[51][51];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp;
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        cin >> temp;
        for (int x = 0; x < M; x++) {
            BOARD[y][x] = temp[x] - '0';
        }
    }

    for (int y = 0; y < N; y++) {
        cin >> temp;
        for (int x = 0; x < M; x++) {
            result[y][x] = temp[x] - '0';
        }
    }
}

void flip(int y, int x) {
    for (int cy = y; cy < y + 3; cy++) {
        for (int cx = x; cx < x + 3; cx++) {
            BOARD[cy][cx] ^= 1;
        }
    }
}

void solve() {
    for (int y = 0; y < N - 2; y++) {
        for (int x = 0; x < M - 2; x++) {
            if (BOARD[y][x] == result[y][x]) {
                continue;
            } else {
                flip(y, x);
                ret++;
            }
        }
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (BOARD[y][x] != result[y][x]) {
                cout << "-1";
                return;
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