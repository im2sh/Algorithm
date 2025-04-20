#include <iostream>

using namespace std;

int TC, ret;
string S, P;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    cin >> S >> P;
    ret = 0;
    ret = S.length();
}

void solve() {
    while (TC--) {
        Input();
        int idx = 0;
        while (idx < S.length() - P.length() + 1) {
            if (S[idx] == P[0]) {
                bool flag = true;
                for (int i = 0; i < P.length(); i++) {
                    if (S[idx + i] != P[i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    idx += P.length();
                    ret -= (P.length() - 1);
                    continue;
                }
            }
            idx++;
        }
        cout << ret << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}