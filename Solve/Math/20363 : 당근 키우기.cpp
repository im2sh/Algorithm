#include <iostream>
#include <algorithm>

using namespace std;

int X, Y;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> X >> Y;
}

void solve() {
    cout << max(X, Y) + min(X, Y) + min(X, Y) / 10;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}