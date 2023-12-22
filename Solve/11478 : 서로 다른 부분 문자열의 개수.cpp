#include <iostream>
#include <set>

using namespace std;
string s;
set<string> sen;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> s;
}

void solve() {
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            temp += s[j];
            sen.insert(temp);
        }
        temp = "";
    }

    cout << sen.size();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

