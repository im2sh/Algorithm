#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int N;
ll ret = 1;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

bool isPrime(ll x) {
    if (x < 2)
        return false;

    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

long long gcd(ll A, ll B) {
    while (B > 0) {
        ll C = A % B;
        A = B;
        B = C;
    }
    return A;
}

ll lcm(ll A, ll B) {
    return A * B / gcd(A, B);
}

void solve() {
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (isPrime(x))
            ret = lcm(ret, x);
    }
    if (ret == 1)
        cout << -1;
    else
        cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}