#include <iostream>

using namespace std;

int TC, N, M;
int ret = 1;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void solve() {
    while (TC--) {
        int temp = 1;
        ret = 1;
        cin >> N >> M;

        for (int i = M; i > M - N; --i) {
            ret = ret * i;
            ret = ret / temp++;
        }
        cout << ret << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}