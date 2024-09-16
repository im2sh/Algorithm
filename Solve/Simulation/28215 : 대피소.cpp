#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int ret = 1e9;
int x[51], y[51];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
}

int go(int i, int j, int k) {
    int temp = 0;
    for (int h = 0; h < N; h++) {
        temp = max(temp, min(min(abs(x[i] - x[h]) + abs(y[i] - y[h]), abs(x[j] - x[h]) + abs(y[j] - y[h])),
                             abs(x[k] - x[h]) + abs(y[k] - y[h])));
    }
    return temp;
}

void solve() {
    if (K == 1) {
        for (int i = 0; i < N; i++) {
            ret = min(ret, go(i, i, i));
        }
    } else if (K == 2) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ret = min(ret, go(i, j, j));
            }
        }
    } else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    ret = min(ret, go(i, j, k));
                }
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