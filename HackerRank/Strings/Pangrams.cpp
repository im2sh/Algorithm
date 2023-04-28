//
// Created by 이석환 on 2023/04/28.
//
#include <iostream>
#include <map>

using namespace std;
string s;
map<char, int> findalpha;
bool flag = true;
string transfer_sen = "";

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    getline(cin, s);
}

void solve() {
    char temp;
    for (int i = 0; i < s.size(); i++) {
        if (97 <= s[i] && s[i] <= 122)
            temp = s[i] - 32;
        else if (s[i] == ' ')
            continue;
        else
            temp = s[i];
        transfer_sen += temp;
    }

    for (int i = 0; i < transfer_sen.size(); i++) {
        findalpha[transfer_sen[i]]++;
    }

    if (findalpha.size() != 26)
        flag = false;

    if (flag)
        cout << "pangram";
    else
        cout << "not pangram";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}