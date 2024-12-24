#include <iostream>

using namespace std;

int cnt, ret;
string S;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> S;
}

void solve() {
    for (int i = 1; i < S.length() - 1; i++) {
        if (S[i] == ')' && S[i + 1] == ')')
            ret += cnt;
        if (S[i] == '(' && S[i - 1] == '(')
            cnt++;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}