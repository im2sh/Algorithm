#include <iostream>

using namespace std;

typedef long long ll;

ll N, M, ret = 1;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
}

void solve() {
    if (N > M)
        cout << 0;
    else {
        for (ll i = 2; i <= N; i++)
            ret = (ret * i) % M;
        cout << ret;
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}