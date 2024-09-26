#include <iostream>

using namespace std;

int TC, N;
int DP[13];

/**
 * DP[0] = 0;
 * DP[1] = 1;
 * DP[2] = 1, 1
 * DP[3] = 1,1,1
 *         1,2
 *         2,1
 *         3
 *DP[4] = 1, 1, 1, 1
 *      = 1, 1, 2
 *      = 1, 2, 1
 *      = 2, 1, 1
 *      = 2, 2
 *      = 1, 3
 *      = 3, 1
 *DP[5] = 1, 1, 1, 1, 1
 *      = 1, 1, 1, 2
 *      = 1, 1, 2, 1
 *      = 1, 2, 1, 1
 *      = 2, 1, 1, 1
 *      = 2, 2, 1
 *      = 2, 1, 2
 *      = 1, 2, 2
 *      = 1, 1, 3
 *      = 1, 3, 1
 *      = 3, 1, 1
 */

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    for (int i = 4; i < 12; i++) {
        DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
    }

}

void Input() {
    cin >> N;
}

void solve() {
    for (int i = 0; i < TC; i++) {
        Input();
        cout << DP[N] << '\n';
    }

}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}