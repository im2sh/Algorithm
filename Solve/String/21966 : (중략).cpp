#include <iostream>

using namespace std;

int N;
string S;
bool checked = true;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> S;
}

void solve() {
    if (N <= 25) {
        cout << S;
        return;
    }
    for (int i = 12; i < N - 12; i++) {
        if (S[i] == '.')
            checked = false;
    }
    if (checked)
        cout << S.substr(0, 11) << "..." << S.substr(N - 11, 11);
    else
        cout << S.substr(0, 9) << "......" << S.substr(N - 10, 10);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}