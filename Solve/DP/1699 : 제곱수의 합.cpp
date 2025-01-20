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
    for (int i = 0; i <= N; i++) {
        DP[i] = i;
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j * j <= i; j++) {
            DP[i] = min(DP[i], DP[i - j * j] + 1);
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