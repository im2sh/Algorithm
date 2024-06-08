#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ull;
ull TC, N, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void go() {
    ull low = 1;
    ull high = sqrt(N) * 2;
    ull mid = 0;
    ret = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (mid * (mid + 1) <= 2 * N) {
            ret = max(ret, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
}

void solve() {
    while (TC--) {
        cin >> N;
        go();
        cout << ret << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}