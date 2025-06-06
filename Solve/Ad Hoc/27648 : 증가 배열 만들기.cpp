#include <iostream>

using namespace std;

int N, M, K;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> K;
}

void solve() {
    if (1 * N + M - 1 > K) {
        cout << "NO";
    } else {
        int cnt = 1;
        cout << "YES\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << cnt << " ";
                cnt++;
            }
            cnt = i + 2;
            cout << "\n";
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}