#include <iostream>
#include <cmath>

using namespace std;
int N, R, C;
int ret = 0;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> R >> C;
}

void go(int x, int y, int size) {
    if (C == x && R == y) {
        cout << ret;
        return;
    } else if (C < x + size && R < y + size && C >= x && R >= y) {
        go(x, y, size / 2);
        go(x + size / 2, y, size / 2);
        go(x, y + size / 2, size / 2);
        go(x + size / 2, y + size / 2, size / 2);
    } else {
        ret += size * size;
    }
}

void solve() {
    go(0, 0, pow(2, N));
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

