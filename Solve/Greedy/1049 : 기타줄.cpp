#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int minPackage = 987654321, minOne = 987654321;
int r, d, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        minPackage = min(minPackage, a);
        minOne = min(minOne, b);
    }
}

void solve() {
    r = N / 6;
    d = N % 6;
    ret = (r * minPackage) + (d * minOne);
    ret = min(ret, ((r + 1) * minPackage));
    ret = min(ret, minOne * N);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}