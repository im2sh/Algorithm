#include <iostream>

using namespace std;

string s;
int ret = 10;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> s;
}

void solve() {
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] == ')' && s[i + 1] == '(')
            || (s[i] == '(' && s[i + 1] == ')')
               && i + 1 < s.size()) {
            ret += 10;
        } else if ((s[i] == ')' && s[i + 1] == ')')
                   || (s[i] == '(' && s[i + 1] == '(')
                      && i + 1 < s.size()) {
            ret += 5;
        }
    }
    cout << ret << '\n';
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}