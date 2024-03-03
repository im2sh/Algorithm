#include <iostream>

using namespace std;
int N;
int DP[30];

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
    for (int i = 1; i < N; ++i) {
        DP[i + 1] = DP[i] * 2;
        if (i + 1 - 3 >= 1 && (i - 2) % 2 == 1)
            DP[i + 1] -= DP[i - 3];
        if (i + 1 - 4 >= 1 && (i - 3) % 2 == 0)
            DP[i + 1] -= DP[i - 4];
    }
    cout << DP[N];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}