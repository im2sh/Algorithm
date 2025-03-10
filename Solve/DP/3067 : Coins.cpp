#include <iostream>

using namespace std;

int TC, N, M;
int DP[10001];
int coin[21];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    for (int i = 0; i < 10001; i++) {
        DP[i] = 0;
    }
    DP[0] = 1;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> coin[i];
    }
    cin >> M;
}

void solve() {
    while (TC--) {
        Input();
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j < 10001; j++) {
                if (j - coin[i] >= 0)
                    DP[j] += DP[j - coin[i]];
            }
        }
        cout << DP[M] << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}