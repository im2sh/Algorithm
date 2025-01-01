#include <iostream>

using namespace std;

int H, W, ret;
string BOARD[101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> H >> W;
    for (int y = 0; y < H; y++) {
        cin >> BOARD[y];
    }
}

void solve() {
    for (int y = 0; y < H; y++) {
        int temp = 0;
        for (int x = 0; x < W; x++) {
            if (BOARD[y][x] != '.') {
                temp++;
                ret++;
            }
            if (temp % 2 == 1 && BOARD[y][x] == '.') {
                ret += 2;
            }
        }
    }
    cout << ret / 2;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}