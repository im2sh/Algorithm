#include <iostream>
#include <algorithm>

using namespace std;

string S;
string ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> S;
    ret = S;
}

void solve() {
    for (int i = 0; i < S.length() - 2; i++) {
        for (int j = i + 1; j < S.length() - 1; j++) {
            string temp = S;

            reverse(temp.begin(), temp.begin() + i + 1);
            reverse(temp.begin() + i + 1, temp.begin() + j + 1);
            reverse(temp.begin() + j + 1, temp.end());

            ret = min(temp, ret);
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