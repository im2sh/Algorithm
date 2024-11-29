#include <iostream>

typedef long long ll;

using namespace std;

ll N, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    ll temp = 1;
    while (N) {
        if (N & 1)
            ret += temp;
        temp *= 3;
        N = N >> 1;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}