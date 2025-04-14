#include <iostream>

using namespace std;

int N;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    if (N < 3)
        cout << 4;
    for (int i = 2; i < N; i++) {
        if (N <= i * i) {
            cout << (i - 1) * 4;
            break;
        } else if (N <= i * (i + 1)) {
            cout << (i - 1) * 4 + 2;
            break;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}