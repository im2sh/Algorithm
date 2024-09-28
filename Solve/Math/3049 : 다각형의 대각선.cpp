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
    cout << N * (N - 1) * (N - 2) * (N - 3) / 24;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}