#include <iostream>

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

    DP[1] = 1;
    DP[2] = 2;
}

void solve() {
    for (int i = 3; i <= N; i++) {
        DP[i] = (DP[i - 2] + DP[i - 1]) % 15746;
    }

    cout << DP[N] << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}