#include <iostream>
#include <algorithm>

using namespace std;

int N, ret;
string S;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> S;
    N = S.length();
}

void solve() {
    for (int i = 1; i < N; i++) {
        int L = i - 1;
        int R = i;
        int sumL = 0;
        int sumR = 0;

        while (L > -1 && R < N) {
            sumL += S[L] - '0';
            sumR += S[R] - '0';
            if (sumL == sumR)
                ret = max(ret, R - L + 1);
            L--, R++;
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}