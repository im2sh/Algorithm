#include <iostream>

using namespace std;

typedef long long ll;

int N;
int query;
ll val = 0;
ll sum = 0;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    int x = 0;
    while (N--) {
        cin >> query;

        if (query == 1) {
            cin >> x;
            sum += x;
            val ^= x;
        } else if (query == 2) {
            cin >> x;
            sum -= x;
            val ^= x;
        } else if (query == 3) {
            cout << sum << '\n';
        } else if (query == 4) {
            cout << val << '\n';
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}