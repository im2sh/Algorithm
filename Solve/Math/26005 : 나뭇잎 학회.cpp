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
    if (N == 1) {
        cout << 0;
    } else {
        if (N % 2 == 0)
            cout << (N * N) / 2;
        else
            cout << ((N * N) / 2) + 1;
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}