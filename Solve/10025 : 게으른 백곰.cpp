#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

ll N, K, G, X;
ll ret;
ll ice[1000002];
ll d[1000002];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> G >> X;
        ice[X] = G;
    }
    d[0] = ice[0];
}

void solve() {
    for (int i = 1; i <= 1000000; i++) {
        d[i] = d[i - 1] + ice[i];
    }
    if (K <= 1000000) {
        for (int i = 0; i <= 1000000; i++) {
            if (i + K <= 1000000 && i - K >= 1)
                ret = max(ret, d[i + K] - d[i - K - 1]);
        }
        cout << ret << '\n';
    } else
        cout << d[1000000] << '\n';
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

