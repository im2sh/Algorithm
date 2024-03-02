#include <iostream>

using namespace std;

int N, L;
int start = -1;
int cnt;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> L;
}

void solve() {
    for (int i = L; i <= 100; i++) {
        int t = i * (i - 1) / 2;

        if ((N - t) % i == 0 && (N - t) / i >= 0) {
            start = (N - t) / i;
            cnt = i;
            break;
        }
    }

    if (start < 0) {
        cout << start;
        return;
    }
    for (int i = 0; i < cnt; i++) {
        cout << start + i << ' ';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}