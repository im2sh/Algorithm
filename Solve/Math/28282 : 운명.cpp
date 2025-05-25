#include <iostream>

using namespace std;

typedef long long ll;

ll X, K, ret;
ll L[10001], R[10001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> X >> K;
    for (int i = 0; i < X; i++) {
        int temp;
        cin >> temp;
        L[temp]++;
    }

    for (int i = 0; i < X; i++) {
        int temp;
        cin >> temp;
        R[temp]++;
    }
}

void solve() {
    ret = X * X;
    for (int i = 1; i <= K; i++) {
        ret -= L[i] * R[i];
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}