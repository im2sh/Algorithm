#include <iostream>
#include <regex>
#include <string>

using namespace std;

int TC;
string S;
regex number("[a-z]*l[a-z]l[a-z]*");

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    cin >> S;
}

void solve() {
    while (TC--) {
        Input();
        if (S.find("lol") != string::npos) {
            cout << "0\n";
        } else if (S.find("lo") != string::npos || S.find("ol") != string::npos || S.find("ll") != string::npos ||
                   regex_match(S, number)) {
            cout << "1\n";
        } else if (S.find("l") != string::npos || S.find("o") != string::npos) {
            cout << "2\n";
        } else {
            cout << "3\n";
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}