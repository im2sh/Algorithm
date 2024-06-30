#include <iostream>

using namespace std;
typedef long long ll;

int N;
ll DP[10000001];

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
        DP[i] = (DP[i - 1] + DP[i - 2]) % 10;
    }
    cout << DP[N];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}