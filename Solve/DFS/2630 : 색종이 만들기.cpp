#include <iostream>

using namespace std;
int N, white, blue;
int BOARD[130][130];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> BOARD[i][j];
        }
    }
}

void go(int x, int y, int k) {
    bool flag = false;
    int first = BOARD[x][y];
    for (int i = x; i < x + k; i++) {
        for (int j = y; j < y + k; j++) {
            if (BOARD[i][j] != first) {
                flag = true;
                break;
            }
        }
    }
    if (flag) {
        go(x, y, k / 2);
        go(x, y + k / 2, k / 2);
        go(x + k / 2, y, k / 2);
        go(x + k / 2, y + k / 2, k / 2);
    } else {
        if (first == 1)
            blue++;
        else
            white++;
    }
}

void solve() {
    go(0, 0, N);
    cout << white << '\n';
    cout << blue;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}