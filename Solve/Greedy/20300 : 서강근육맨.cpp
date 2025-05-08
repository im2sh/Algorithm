#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
ll T[10001];
ll ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    sort(T, T + N);
}

void solve() {
    if (N % 2 == 1) {
        ret = T[N - 1];
        N--;

        for (int i = 0; i < N / 2; i++) {
            ll temp = T[i] + T[(N - 1) - i];

            if (temp > ret)
                ret = temp;
        }
    } else {
        for (int i = 0; i < N / 2; i++) {
            ll temp = T[i] + T[(N - 1) - i];
            if (temp > ret)
                ret = temp;
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