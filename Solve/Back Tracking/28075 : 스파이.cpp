#include <iostream>

using namespace std;

int N, M, ret;
int BOARD[2][3];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> BOARD[i][j];
        }
    }
}

void go(int depth, int sum, int prev) {
    if (depth == N) {
        if (sum >= M)
            ret++;
        return;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            int next = sum;
            if (j == prev)
                next += BOARD[i][j] / 2;
            else
                next += BOARD[i][j];
            go(depth + 1, next, j);
        }
    }
}

void solve() {
    go(0, 0, -1);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}