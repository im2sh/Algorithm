#include <iostream>

using namespace std;

int X, M;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> X >> M;
}

void solve() {
    cout << X * (M + 1);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}