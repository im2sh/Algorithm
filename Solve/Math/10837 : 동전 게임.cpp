#include <iostream>
#include <cmath>

using namespace std;
int K, C, N, M;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> K;
    cin >> C;
}

void solve() {
    for (int i = 0; i < C; i++) {
        cin >> N >> M;
        int diff = abs(N - M);
        int temp = K - max(N, M);

        if (N == M) {
            cout << "1\n";
        } else if (N > M) {
            if (diff - temp <= 2) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else {
            if (diff - temp <= 1) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}