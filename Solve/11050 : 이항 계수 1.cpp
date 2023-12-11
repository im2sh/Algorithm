#include <iostream>

using namespace std;
int N, K;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
}

int go(int depth) {
    if (depth <= 1)
        return 1;
    else
        return depth * go(depth - 1);
}

void solve() {
    cout << go(N) / (go(K) * go(N - K));
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}