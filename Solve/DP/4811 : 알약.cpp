#include <iostream>

using namespace std;

typedef long long ll;

int N;
ll DP[31][31];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

ll go(int W, int H) {
    if (W < 0 || H < 0)
        return 0;

    if (W == 0 && H == 0)
        return 1;

    ll &ret = DP[W][H];
    if (ret)
        return ret;

    ret = go(W - 1, H + 1) + go(W, H - 1);
    return ret;
}

void solve() {
    while (true) {
        Init();
        if (N == 0)
            break;
        cout << go(N, 0) << '\n';
    }
}

int main(void) {
    FastIO();
    solve();
    return 0;
}