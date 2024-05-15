#include <iostream>

using namespace std;
int N, A, B, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> A >> B;
    A--;
    B--;
}

void solve() {
    while (true) {
        if (N == 0)
            break;
        if (A == B) {
            cout << ret;
            return;
        }
        A /= 2;
        B /= 2;
        ret++;
    }
    cout << -1;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}