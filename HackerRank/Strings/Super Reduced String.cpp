#include <iostream>
#include <string>

using namespace std;

string s;
string result = "";

void FastIO() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void Init() {
    cin >> s;
}

string solve() {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == s[i + 1]) {
            s[i] = '0';
            s[i + 1] = '0';
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0')
            result = result + s[i];
    }
    if (result == "")
        return "Empty String";
    return result;
}

int main(void) {
    FastIO();
    Init();
    cout << solve();
    return 0;
}
