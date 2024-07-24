#include <iostream>
#include <regex>
#include <string>

using namespace std;

int TC;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void solve() {
    regex re("(^[A-F]?A+F+C+[A-F]?$)");
    while (TC--) {
        string temp;
        cin >> temp;
        if (regex_match(temp, re)) {
            cout << "Infected!\n";
        } else {
            cout << "Good\n";
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}