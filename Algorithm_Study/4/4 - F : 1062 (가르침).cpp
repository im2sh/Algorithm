#include <iostream>
#include <string>

using namespace std;

int N, K;
string dic[51];
int alpha[26];
int ret = 0;
bool ok = true;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> dic[i];
    }

    alpha['a' - 'a'] = 1;
    alpha['n' - 'a'] = 1;
    alpha['t' - 'a'] = 1;
    alpha['i' - 'a'] = 1;
    alpha['c' - 'a'] = 1;

}

int go() {
    int cnt = 0;
    for (string s: dic) {
        ok = true;
        for (int i = 4; i < s.length() - 4; i++) {
            if (!alpha[s[i] - 'a']) {
                ok = false;
                break;
            }
        }
        if (ok)
            cnt++;
    }
    return cnt;
}

void solve(int idx, int cnt) {
    if (cnt == K - 5) {
        ret = max(ret, go());
        return;
    }
    for (int i = idx; i < 26; i++) {
        if (!alpha[i]) {
            alpha[i] = 1;
            solve(i + 1, cnt + 1);
            alpha[i] = 0;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve(0, 0);
    cout << ret << "\n";
    return 0;
}
