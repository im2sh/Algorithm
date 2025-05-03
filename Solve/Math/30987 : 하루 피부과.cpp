#include <iostream>

using namespace std;
int X1, X2, A, B, C, D, E;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> X1 >> X2;
    cin >> A >> B >> C >> D >> E;
}

int go(int X) {
    return A * (X * X * X) / 3 + (B - D) * (X * X) / 2 + (C - E) * X;
}

void solve() {
    cout << (go(X2) - go(X1));
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
