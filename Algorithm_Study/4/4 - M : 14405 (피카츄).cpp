#include <iostream>

using namespace std;

string s;
bool ok = true;

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
    int size = s.length();
    for (int i = 0; i < size; i++) {
        temp += s[i];
        if ((temp == "pi") || (temp == "ka") || (temp == "chu"))
            temp = "";
        if (temp.length() >= 3) {
            ok = false;
            break;
        }
    }
    if (temp.length())
        ok = false;
    if (ok)
        cout << "YES";
    else
        cout << "NO";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}