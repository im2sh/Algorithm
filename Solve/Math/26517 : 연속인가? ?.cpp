#include <iostream>

using namespace std;

typedef long long ll;

ll A, B, C, D, K;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> K >> A >> B >> C >> D;
}

void solve() {
    if (A * K + B == C * K + D)
        cout << "Yes " << A * K + B;
    else
        cout << "No";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}