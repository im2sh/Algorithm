#include <iostream>
#include <map>

typedef long long ll;

using namespace std;

ll N, P, Q;
map<ll, ll> M;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> P >> Q;
}

ll go(ll cur) {
    if (M[cur] != 0)
        return M[cur];
    M[cur] = go(cur / P) + go(cur / Q);
    return M[cur];
}

void solve() {
    M[0] = 1;
    cout << go(N);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

