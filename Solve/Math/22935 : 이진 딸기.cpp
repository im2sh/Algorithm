#include <iostream>

using namespace std;

typedef long long ll;

ll TC, N;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    cin >> N;
    N--;
    N %= 28;
    N++;

    if (16 <= N)
        N = 30 - N;
}

void solve() {
    while (TC--) {
        Input();

        for (ll i = 8; i >= 1; i /= 2) {
            if (N >= i) {
                cout << "딸기";
                N -= i;
            } else {
                cout << "V";
            }
        }
        cout << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}