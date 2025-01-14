#include <iostream>
#include <algorithm>

using namespace std;

int N;
int card[1001];
int DP[1001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> card[i];
        DP[i] = card[i];
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i / 2; j++) {
            DP[i] = max(DP[i], DP[j] + DP[i - j]);
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