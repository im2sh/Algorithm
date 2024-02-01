#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string str, ret = "z";

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> str;
}

void solve() {
    for (int i = 0; i < str.length() - 2; i++) {
        for (int j = i + 1; j < str.length() - 1; j++) {
            string temp = "";
            for (int k = i; k >= 0; k--)
                temp += str[k];
            for (int k = j; k > i; k--)
                temp += str[k];
            for (int k = str.length() - 1; k > j; k--)
                temp += str[k];
            if (ret > temp)
                ret = temp;
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