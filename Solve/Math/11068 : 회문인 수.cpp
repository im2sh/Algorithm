#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int TC, N;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    cin >> N;
}

bool go() {
    for (int i = 2; i <= 64; i++) {
        int num = N;
        string S;
        while (num) {
            S.push_back(num % i);
            num /= i;
        }

        string reverseS = S;

        reverse(reverseS.begin(), reverseS.end());

        if (S == reverseS) {
            return true;
        }
    }

    return false;
}


void solve() {
    while (TC--) {
        Input();
        cout << go() << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}