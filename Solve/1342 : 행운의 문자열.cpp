#include <iostream>
#include <algorithm>

using namespace std;

string s;
int ret = 0;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> s;
    sort(s.begin(), s.end());
}

bool check(string &s) {
    int slen = s.length();
    for (int i = 0; i < slen - 1; i++) {
        if (s[i] == s[i + 1])
            return false;
    }
    return true;
}

void solve() {
    do {
        if (check(s))
            ret++;
    } while (next_permutation(s.begin(), s.end()));
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}


