#include <iostream>

using namespace std;

typedef long long ll;

int TC;
ll ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

ll gcd(ll x, ll y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

ll lcm(ll x, ll y, ll GCD) {
    return x * y / GCD;
}

void solve() {
    while (TC--) {
        ll A, B;
        cin >> A >> B;
        ret = lcm(A, B, gcd(A, B));
        cout << ret << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}