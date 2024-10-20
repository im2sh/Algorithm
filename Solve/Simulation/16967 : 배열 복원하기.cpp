#include <iostream>

using namespace std;

int H, W, Y, X;
int BOARD[604][604];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> H >> W >> Y >> X;
    for (int y = 0; y < H + Y; y++) {
        for (int x = 0; x < W + X; x++) {
            cin >> BOARD[y][x];
        }
    }
}

void solve() {
    for (int y = Y; y < H; y++) {
        for (int x = X; x < W; x++) {
            BOARD[y][x] -= BOARD[y - Y][x - X];
        }
    }
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            cout << BOARD[y][x] << " ";
        }
        cout << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}