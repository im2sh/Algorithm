#include <iostream>

using namespace std;

typedef long long ll;

int Q;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> Q;
}

void solve() {
    while (Q--) {
        ll A, B;
        cin >> A >> B;
        
        if (B % A == 0 && A < B)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}