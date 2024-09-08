#include <iostream>

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
    DP[0] = 1;
    DP[1] = 3;
}

void solve() {
    for (int i = 2; i <= N; i++) {
        DP[i] = (DP[i - 1] * 2 + DP[i - 2]) % 9901;
    }
    cout << DP[N];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}