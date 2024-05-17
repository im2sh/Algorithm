#include <iostream>
#include <algorithm>

using namespace std;

string S;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> S;
}

bool check(string s) {
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != reversed_s[i])
            return false;
    }
    return true;
}

void solve() {
    if (check(S)) {
        cout << S.length();
        return;
    }
    int length = S.length();
    for (int i = 0; i < length; i++) {
        string temp = "";
        temp += S[i];
        S.insert(length, temp);
        if (check(S))
            break;
    }
    cout << S.length();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
