#include <iostream>

using namespace std;
int N, ret;
int BOARD[1004][1004];
int DP[1004][1004];
int milk[1004][1004];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> BOARD[y][x];
        }
    }
    milk[0][1] = 2;
    milk[1][0] = 2;
    for (int i = 2; i <= N; i++) {
        milk[0][i] = -1;
    }
    for (int i = 2; i <= N; i++) {
        milk[i][0] = -1;
    }
}

void solve() {
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            bool canDrinkLeft = false;
            bool canDrinkUp = false;
            if (BOARD[y][x] == ((milk[y][x - 1] + 1) % 3))
                canDrinkLeft = true;
            if (BOARD[y][x] == ((milk[y - 1][x] + 1) % 3))
                canDrinkUp = true;
            int left = DP[y][x - 1];
            int up = DP[y - 1][x];

            if (canDrinkLeft)
                left += 1;
            if (canDrinkUp)
                up += 1;

            if (left > up) {
                DP[y][x] = DP[y][x - 1];
                if (canDrinkLeft) {
                    DP[y][x] += 1;
                    milk[y][x] = BOARD[y][x];
                } else {
                    milk[y][x] = milk[y][x - 1];
                }
            } else {
                DP[y][x] = DP[y - 1][x];
                if (canDrinkUp) {
                    DP[y][x] += 1;
                    milk[y][x] = BOARD[y][x];
                } else {
                    milk[y][x] = milk[y - 1][x];
                }
            }
        }
    }

    cout << DP[N][N];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}