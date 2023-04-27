#include <iostream>
#include <string>

using namespace std;

string s;
int cnt;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void Init() {
    cin >> s;
}

int solve() {
    for (int i = 0; i < s.size(); i++) {
        if (65 <= s[i] && s[i] <= 91)
            cnt++;
    }
    return cnt + 1;
}

int main(void) {
    FastIO();
    Init();
    cout << solve();
    return 0;
}
