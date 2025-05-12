#include <iostream>
#include <cmath>

using namespace std;

int TC;
string S, ret;
char BOARD[10001][10001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    ret = "";
    cin >> S;
}

void solve() {
    while (TC--) {
        Input();
        int len = sqrt(S.length());

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                BOARD[i][j] = S[j + (len * i)];
            }
        }

        for (int i = len - 1; i >= 0; i--) {
            for (int j = 0; j < len; j++) {
                ret += BOARD[j][i];
            }
        }
        cout << ret << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}