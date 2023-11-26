#include <iostream>

using namespace std;

int D, K;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> D >> K;
}

void go(int day, int A, int B) {
    if (A < 1 || A > B)
        return;
    if (day == D) {
        cout << A << '\n' << B;
        exit(0);
    }

    go(day + 1, B - A, A);
}

void solve() {
    for (int i = K / 2 + 1; i < K; i++) {
        go(2, i, K);
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}