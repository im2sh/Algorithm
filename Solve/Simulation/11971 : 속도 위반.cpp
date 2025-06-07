#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, ret;
int speed[101];
int mine[101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;

    int idx = 0;
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;

        for (int j = idx; j < idx + A; j++) {
            speed[j] = B;
        }
        idx += A;
    }

    idx = 0;
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        for (int j = idx; j < idx + A; j++) {
            mine[j] = B;
        }
        idx += A;
    }
}

void solve() {
    for (int i = 0; i < 100; i++) {
        ret = max(ret, mine[i] - speed[i]);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}