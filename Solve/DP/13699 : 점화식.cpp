#include <iostream>

using namespace std;
typedef long long ll;

int N;
ll DP[36];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    DP[0] = 1;
}

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= i; k++) {
            DP[i] += DP[k - 1] * DP[i - k];
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