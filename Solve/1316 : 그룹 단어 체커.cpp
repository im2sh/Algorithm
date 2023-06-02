#include <iostream>

using namespace std;

int N;
string a;
int alpha[26];
bool ok;
int ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    char past = ' ';
    while (N--) {
        fill(&alpha[0], &alpha[0] + 26, 0);
        ok = true;
        cin >> a;
        for (int i = 0; i < a.length(); i++) {
            if (alpha[a[i] - 'a'])
                ok = false;
            if (i != 0 && a[i] != past)
                alpha[past - 'a'] = 1;
            past = a[i];
        }
        if (ok)
            ret++;
    }

    cout << ret << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
