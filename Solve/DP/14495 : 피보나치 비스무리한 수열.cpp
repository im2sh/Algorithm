#include <iostream>

using namespace std;

typedef long long ll;

int N;
ll DP[117] = {0, 1, 1, 1};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    for (int i = 3; i <= N; i++)
        DP[i] = DP[i - 1] + DP[i - 3];
    cout << DP[N];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}