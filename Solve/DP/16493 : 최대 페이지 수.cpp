#include <iostream>
#include <algorithm>

using namespace std;

int N, M, ret;
int day[21];
int page[21];
int DP[21][201];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> day[i] >> page[i];
    }
}

void solve() {
    for (int i = 1; i <= M; i++) {
        for (int j = N; j >= 0; j--) {
            if (j - day[i] >= 0) {
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - day[i]] + page[i]);
            } else {
                DP[i][j] = DP[i - 1][j];
            }
            ret = max(ret, DP[i][j]);
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