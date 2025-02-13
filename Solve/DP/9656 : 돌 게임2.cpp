#include <iostream>

using namespace std;

int N;
int DP[1004];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    DP[1] = 0;
    DP[2] = 1;
    DP[3] = 0;
}

void solve() {
    for (int i = 4; i <= N; i++) {
        if (DP[i - 1] == 0 || DP[i - 3] == 0)
            DP[i] = 1;
        else
            DP[i] = 0;
    }
    if (DP[N] == 1)
        cout << "SK";
    else
        cout << "CY";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}