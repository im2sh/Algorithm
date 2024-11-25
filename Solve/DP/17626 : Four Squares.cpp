#include <iostream>
#include <algorithm>

using namespace std;

int N;
int DP[50001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    fill(&DP[0], &DP[0] + 50001, 5);
    for (int i = 1; i * i <= N; i++) {
        DP[i * i] = 1;
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j * j <= i; j++) {
            DP[i] = min(DP[i], DP[j * j] + DP[i - (j * j)]);
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