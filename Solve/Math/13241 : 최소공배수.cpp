#include <iostream>

using namespace std;

typedef long long ll;

ll A, B, gcd;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> A >> B;
}

int GCD(int a, int b) {
    if (b == 0)
        return a;

    return GCD(b, a % b);
}

void solve() {
    cout << A * B / GCD(A, B);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}