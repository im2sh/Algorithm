#include <iostream>

#define MOD 16769023

using namespace std;

int N, ret = 2;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    for (int i = 2; i <= N; i++) {
        if (i % 2 == 1)
            ret = (ret * 2) % MOD;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}