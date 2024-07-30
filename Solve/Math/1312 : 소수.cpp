#include <iostream>

using namespace std;

int A, B, N, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> A >> B >> N;
}

void solve() {
    if (A % B == 0) {
        cout << 0;
        return;
    }
    if (A > B)
        A %= B;
    for (int i = 0; i < N; i++) {
        A *= 10;
        ret = (int) (A / B);
        A %= B;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}