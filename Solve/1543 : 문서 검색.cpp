#include <iostream>
#include <string>

using namespace std;

string target;
string findstr;
int ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    getline(cin, target);
    getline(cin, findstr);
}

void solve() {
    for (int i = 0; i < target.length(); i++) {
        if (target.length() < findstr.length())
            break;
        string temp = target.substr(i, findstr.length());
        if (findstr == temp) {
            ret++;
            i += findstr.length() - 1;
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}