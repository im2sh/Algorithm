#include <iostream>

using namespace std;

typedef long long ll;

ll N, R;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> R;
}

void solve() {
    cout << R * 2 + (N - 1);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}