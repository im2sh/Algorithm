#include <iostream>

using namespace std;

int N, ret;
int p[21];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 1; i < N + 1; i++) {
        cin >> p[i];
    }
}

int go(int l, int r) {
    int x = 1;
    for (int i = l; i < r + 1; i++) {
        x *= p[i];
    }
    return x;
}

void solve() {
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                int temp = go(1, i) + go(i + 1, j) + go(j + 1, k) + go(k + 1, N);
                ret = (ret > temp) ? ret : temp;
            }
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}