#include <iostream>
#include <cmath>

typedef long long ll;
using namespace std;

ll x, y;
ll ret = -1;
ll original;


void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> x >> y;
    original = (y * 100) / x;
}

bool go(ll mid) {
    double change = ((y + mid) * 100) / (x + mid);

    if (original != change)
        return true;
    return false;
}

void solve() {
    ll low = 1;
    ll high = 1e9;

    while (low <= high) {
        ll mid = (low + high) / 2;
        if (go(mid)) {
            high = mid - 1;
            ret = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}