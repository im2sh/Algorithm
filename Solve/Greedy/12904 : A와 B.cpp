#include <iostream>
#include <algorithm>

using namespace std;

string S, T;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> S;
    cin >> T;
}

void solve() {
    int length = T.length();

    for (int i = length - 1; i >= 0; i--) {
        if (S == T) {
            cout << "1";
            return;
        }
        if (T[i] == 'A') {
            T.pop_back();
        } else {
            if (T[i] == 'B') {
                T.pop_back();
                reverse(T.begin(), T.end());
            } else {
                cout << "0";
                return;
            }
        }
    }
    cout << "0";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}