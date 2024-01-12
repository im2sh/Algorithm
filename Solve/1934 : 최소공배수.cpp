#include <iostream>

using namespace std;

int T;
int A, B;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> T;
}

int divide(int x, int y) {
    if (x % y == 0)
        return y;
    else
        return divide(y, x % y);
}

void solve() {
    for (int i = 0; i < T; i++) {
        cin >> A >> B;
        if (A >= B) {
            cout << A * B / divide(A, B) << "\n";
        } else
            cout << A * B / divide(B, A) << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

