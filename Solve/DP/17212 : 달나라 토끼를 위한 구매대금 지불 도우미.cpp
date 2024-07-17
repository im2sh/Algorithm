#include <iostream>
#include <algorithm>

using namespace std;

int N;
int DP[100004];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    DP[1] = 1, DP[2] = 1, DP[3] = 2, DP[4] = 2, DP[5] = 1, DP[6] = 2, DP[7] = 1;
}

void solve() {
    for (int i = 8; i <= N; i++) {
        DP[i] = min(DP[i - 1], min(DP[i - 2], min(DP[i - 5], DP[i - 7]))) + 1;
    }
    cout << DP[N];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}