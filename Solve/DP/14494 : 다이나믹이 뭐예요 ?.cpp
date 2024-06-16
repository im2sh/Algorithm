#include <iostream>

#define MOD 1000000007
using namespace std;

int DP[1001][1001], N, M;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    fill(&DP[0][0], &DP[0][0] + 1001 * 1001, -1);
}

int go(int i, int j) {
    if (i < 1 || j < 1)
        return 0;
    if (i == 1 && j == 1)
        return 1;
    int &ret = DP[i][j];
    if (ret != -1)
        return ret;
    ret = 0;
    ret = ((go(i, j - 1) + go(i - 1, j)) % MOD + go(i - 1, j - 1)) % MOD;
    return ret;
}

void solve() {
    cout << go(N, M);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
