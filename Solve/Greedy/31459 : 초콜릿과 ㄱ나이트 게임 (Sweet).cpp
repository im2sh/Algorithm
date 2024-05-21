#include <iostream>

using namespace std;
int TC, Y, X, y, x, ret;
bool BOARD[51][51];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void solve() {
    while (TC--) {
        cin >> X >> Y >> x >> y;
        ret = 0;
        int right = X;
        int bottom = Y;
        bool flag = true;

        while (right >= 0 && bottom >= 0) {
            for (int i = 0; i < right; ++i) {
                for (int j = 0; j < bottom; ++j) {
                    BOARD[i][j] = flag;
                }
            }
            flag = !flag;
            right -= x;
            bottom -= y;
        }

        for (int i = 0; i < X; ++i) {
            for (int j = 0; j < Y; ++j) {
                if (BOARD[i][j]) {
                    ret++;
                }
            }
        }
        cout << ret << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}