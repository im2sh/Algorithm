#include <iostream>

using namespace std;
string s;
string sos = "";
int cnt;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> s;
}

void solve() {
    int size = s.size();
    int n = size / 3;
    for (int i = 0; i < n; i++) {
        sos += "SOS";
    }
    for (int i = 0; i < size; i++) {
        if (s[i] != sos[i])
            cnt++;
    }
    cout << cnt << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}