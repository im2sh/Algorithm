#include <iostream>

using namespace std;

typedef long long ll;

int TC;
ll N, X, Y, V1, V2;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    V1 = 0;
    cin >> N >> X >> Y;
    for (int i = 1; i < N; i++) {
        ll temp;
        cin >> temp;
        V1 = max(V1, temp);
    }
    cin >> V2;
}

void go() {
    if (V1 < V2) {
        cout << "0\n";
    } else {
        for (ll i = V2 + 1; i <= Y; i++) {
            ll t1 = X - V1;
            ll t2 = X - i;
            if (t1 * V2 > t2 * V1) {
                cout << i << '\n';
                return;
            }
        }
        cout << -1 << '\n';
    }
}

void solve() {
    while (TC--) {
        Input();
        go();
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}