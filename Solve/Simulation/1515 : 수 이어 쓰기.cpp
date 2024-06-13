#include <iostream>

using namespace std;
string str;
int ret, cnt;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> str;
}

void solve() {
    while (ret++ < 30000) {
        string temp = to_string(ret);
        for (int i = 0; i < temp.length(); i++) {
            if (str[cnt] == temp[i]) {
                cnt++;
            }
            if (cnt == str.length()) {
                cout << ret;
                return;
            }
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}