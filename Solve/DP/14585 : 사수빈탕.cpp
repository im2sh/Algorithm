#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, M;
int BOARD[304][304];
ll ret;
ll DP[304][304];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int y, x;
        cin >> y >> x;
        BOARD[y + 1][x + 1] = M - y - x;
    }
}

void solve() {
    for (int y = 1; y <= 301; y++) {
        for (int x = 1; x <= 301; x++) {
            DP[y][x] = max(DP[y - 1][x], DP[y][x - 1]) + BOARD[y][x];
            ret = max(ret, DP[y][x]);
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}