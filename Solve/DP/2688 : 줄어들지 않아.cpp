#include <iostream>

using namespace std;

typedef long long ll;

int TC, N;
ll ret;
ll DP[65][10];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;

    for (int i = 0; i <= 9; i++) {
        DP[1][i] = 1;
    }

    for (int i = 2; i <= 64; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = j; k <= 9; k++) {
                DP[i][j] += DP[i - 1][k];
            }
        }
    }
}

void Input() {
    ret = 0;
    cin >> N;
}

void solve() {
    while (TC--) {
        Input();
        for (int i = 0; i <= 9; i++) {
            ret += DP[N][i];
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