#include <iostream>

using namespace std;

int TC, A, B;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void solve() {
    while (TC--) {
        cin >> A >> B;
        cout << "yes\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}