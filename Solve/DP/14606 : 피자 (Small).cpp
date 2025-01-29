#include <iostream>

using namespace std;

int N;
int DP[11];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    DP[1] = 0;
    DP[2] = 1;
}

void solve() {
    for (int i = 3; i <= N; i++) {
        int temp = i / 2;
        DP[i] = (temp * (i - temp)) + DP[temp] + DP[i - temp];
    }
    cout << DP[N];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}