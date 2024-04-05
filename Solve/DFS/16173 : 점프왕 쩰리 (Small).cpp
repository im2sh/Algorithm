#include <iostream>

using namespace std;
int N;
int BOARD[3][3];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> BOARD[y][x];
        }
    }
}

int go(int y, int x) {
    if (y == N - 1 && x == N - 1)
        return 1;
    if (y < 0 || y >= N || x < 0 || x >= N)
        return 0;
    int ret = 0;
    if (y + BOARD[y][x] > y)
        ret = max(ret, go(y + BOARD[y][x], x));
    if (x + BOARD[y][x] > x)
        ret = max(ret, go(y, x + BOARD[y][x]));
    return ret;
}

void solve() {
    if (go(0, 0))
        cout << "HaruHaru";
    else cout << "Hing";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
