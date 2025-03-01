#include <iostream>

using namespace std;

int N, M, ret = 1;
int book[100001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> book[i];
    }
}

void solve() {
    if (N == 0) {
        cout << 0;
        return;
    }

    int sum = 0;
    for (int i = N - 1; i >= 0; i--) {
        sum += book[i];
        if (sum > M) {
            ret++;
            sum = book[i];
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