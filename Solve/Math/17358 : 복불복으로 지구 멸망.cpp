#include <iostream>

typedef long long ll;

constexpr ll MOD = 1e9 + 7;

using namespace std;

ll N, ret = 1;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    while (N) {
        ret *= N - 1;
        ret %= MOD;

        N -= 2;
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}