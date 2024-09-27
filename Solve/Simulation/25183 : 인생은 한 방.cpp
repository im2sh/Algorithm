#include <iostream>
#include <algorithm>

using namespace std;

int N, cnt, ret;
string S;
char prevC = 'a';

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> S;
    S += 'a';
}

void solve() {
    for (int i = 0; i <= N; i++) {
        char cur = S[i];
        if (cur == prevC + 1 || cur == prevC - 1)
            cnt++;
        else {
            ret = max(ret, cnt);
            cnt = 1;
        }
        prevC = cur;
    }

    if (ret >= 5)
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