#include <iostream>

using namespace std;

int N, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j++) {
            int k = N - i - j;
            if (j > k)
                break;
            if (i + j > k)
                ret++;
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