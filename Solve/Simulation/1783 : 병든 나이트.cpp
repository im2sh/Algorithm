#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
}

void solve() {
    if (N == 1)
        cout << N;
    else if (N == 2)
        cout << min(4, (M + 1) / 2);
    else if (M < 7)
        cout << min(4, M);
    else
        cout << M - 7 + 5;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}