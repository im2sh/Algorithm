#include <iostream>

using namespace std;
typedef long long ll;
int N;
ll DP[91];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    DP[0] = 1;
    DP[1] = 1;
}

void solve() {
    for (int i = 2; i <= N; i++) {
        DP[i] = DP[i - 1] + DP[i - 2];
    }
    cout << DP[N - 1];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}