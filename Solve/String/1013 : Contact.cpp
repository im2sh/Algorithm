#include <iostream>
#include <regex>
#include <string>

using namespace std;

int TC;
string S;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void solve() {
    while (TC--) {
        cin >> S;

        regex pattern("(100+1+|01)+");
        cout << (regex_match(S, pattern) ? "YES\n" : "NO\n");
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}