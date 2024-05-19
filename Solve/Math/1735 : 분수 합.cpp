#include <iostream>

using namespace std;

int A, B, C, D;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> A >> B;
    cin >> C >> D;
}

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve() {
    int e, f;
    e = (A * D + B * C);
    f = B * D;
    int g = gcd(e, f);
    cout << e / g << " " << f / g;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
