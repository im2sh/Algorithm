#include <iostream>

using namespace std;

int N, H, W;
string BOARD[11];
string ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> H >> W;
    for (int i = 0; i < H; i++) {
        cin >> BOARD[i];
    }
}

void solve() {
    for (int i = 0; i < N * W; i += W) {
        string temp = "?";
        for (int j = 0; j < H; j++) {
            for (int k = i; k < i + W; k++) {
                if (BOARD[j][k] != '?') {
                    temp = BOARD[j][k];
                }
            }
        }
        ret += temp;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}