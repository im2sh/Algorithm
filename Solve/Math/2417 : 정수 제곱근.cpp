#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
ll N, Q;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    Q = sqrt(N);
}

void solve() {
    if ((Q * Q) < N)
        Q++;

    cout << Q;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}