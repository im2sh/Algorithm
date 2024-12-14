#include <iostream>
#include <algorithm>

using namespace std;

int N;
int juice[10004];
int DP[10004];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> juice[i];
    }
    DP[1] = juice[1];
    DP[2] = juice[1] + juice[2];
}

void solve() {
    for (int i = 3; i <= N; i++) {
        DP[i] = max(DP[i - 3] + juice[i - 1] + juice[i], max(DP[i - 2] + juice[i], DP[i - 1]));
    }

    cout << DP[N];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}