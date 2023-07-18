#include <iostream>
#include <string>

using namespace std;

string s;
string bomb;
string ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> s;
    cin >> bomb;
}

void solve() {
    for (char a: s) {
        ret += a;
        if (ret.size() >= bomb.size() && ret.substr(ret.length() - bomb.length(), bomb.length()) == bomb)
            ret.erase(ret.length() - bomb.length(), bomb.length());
    }
    if (ret.length())
        cout << ret << "\n";
    else
        cout << "FRULA" << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}