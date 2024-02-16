/*
        D[i][j] = 1~j 사이의 수들의 합으로 i를 만드는 방법의 수
		1. j를 포함하지 않고 i를 만드는 경우
		    D[i][j] = D[i][j-1];
		2. j를 포함해서 i를 만드는 경우
		    if(i>=j)
		        D[i][j] = (D[i][j] + D[i-j][j-1]) % mod ;
		    D[i-j][j-1] : i-j를 1 ~ j-1 사이의 수들로 만드는 방법의 수
 */

#include <iostream>

using namespace std;

int TC, N;
int DP[2001][2001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    for (int i = 0; i < 2001; i++) {
        DP[0][i] = 1;
    }
}

void solve() {
    for (int i = 1; i < 2001; i++) {
        for (int j = 1; j < 2001; j++) {
            DP[i][j] = DP[i][j - 1];
            if (i >= j) {
                DP[i][j] += (DP[i - j][j - 1]);
                DP[i][j] %= 100999;
            }
        }
    }

    cin >> TC;

    while (TC--) {
        cin >> N;
        cout << DP[N][N] << '\n';
    }

}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}