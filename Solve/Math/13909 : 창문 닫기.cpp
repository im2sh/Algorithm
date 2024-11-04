#include <iostream>

using namespace std;

int N, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    for (int i = 1; i * i <= N; i++)
        ret++;
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}