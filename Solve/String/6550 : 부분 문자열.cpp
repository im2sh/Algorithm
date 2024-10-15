#include <iostream>

using namespace std;

string S, T;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {

}

void solve() {
    while (cin >> S >> T) {
        int idx = 0;
        for (int i = 0; i < T.length(); i++) {
            if (S[idx] == T[i]) {
                idx++;
            }
        }
        if (idx == S.length())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}