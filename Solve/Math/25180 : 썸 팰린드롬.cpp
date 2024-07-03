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
    ret = (N - 1) / 9 + 1;
    if (ret % 2 == 0 && N % 2 == 1) {
        ret += 1;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
