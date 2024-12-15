#include <iostream>
#include <algorithm>

using namespace std;

int N, ret;
int triangle[504][504];
int DP[504][504];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }
    DP[1][1] = triangle[1][1];
    DP[2][1] = triangle[1][1] + triangle[2][1];
    DP[2][2] = triangle[1][1] + triangle[2][2];
}

void solve() {
    for (int i = 3; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) {
                DP[i][j] = DP[i - 1][j] + triangle[i][j];
            } else if (j == i) {
                DP[i][j] = DP[i - 1][j - 1] + triangle[i][j];
            } else {
                DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + triangle[i][j];
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        ret = max(ret, DP[N][i]);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}