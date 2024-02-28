#include <iostream>
#include <algorithm>

using namespace std;
int N;
int DP[1000001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    DP[2] = 1;
    DP[3] = 1;
    for (int i = 4; i <= N; i++) {
        if (i % 2 == 0 && i % 3 == 0) {
            DP[i] = min(DP[i / 2] + 1, min(DP[i / 3] + 1, DP[i - 1] + 1));
        } else if (i % 2 == 0) {
            DP[i] = min(DP[i / 2] + 1, DP[i - 1] + 1);
        } else if (i % 3 == 0) {
            DP[i] = min(DP[i / 3] + 1, DP[i - 1] + 1);
        } else {
            DP[i] = DP[i - 1] + 1;
        }
    }

    cout << DP[N];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}