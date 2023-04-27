//
// Created by 이석환 on 2023/04/28.
//
#include <iostream>

using namespace std;

int N;
string s;
string hacker = "hackerrank";
bool flag;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    while (N--) {
        cin >> s;
        flag = false;
        int h = 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == hacker[h]) {
                cnt++;
                h++;
            }
        }

        if (cnt == 10)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}