#include <iostream>

using namespace std;

int N, M;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    scanf("%d:%d", &N, &M);
}

int gcd(int a, int b) {
    if (!b)
        return a;
    return gcd(b, a % b);
}

void solve() {
    cout << N / gcd(N, M) << ":" << M / gcd(N, M);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}