#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

ll N;
map<ll, ll> M;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    M[1] = 0;
    M[2] = 1;
}

ll go(ll n) {
    if (n == 1 || M[n])
        return M[n];

    if (n % 2 == 1)
        M[n] = go(n / 2) + go(n / 2 + 1) + (n / 2) * (n / 2 + 1);
    else
        M[n] = go(n / 2) + go(n / 2) + (n / 2) * (n / 2);

    return M[n];
}

void solve() {
    go(N);
    cout << M[N];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}