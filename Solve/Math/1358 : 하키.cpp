#include <iostream>

using namespace std;

int W, H, X, Y, P, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> W >> H >> X >> Y >> P;
}

int calc(int x, int y, int a, int b) {
    return ((x - a) * (x - a)) + ((b - y) * (b - y));
}

void solve() {
    for (int t = 0; t < P; ++t) {
        int x, y, r = (H / 2) * (H / 2);
        cin >> x >> y;

        if (X <= x && x <= X + W && Y <= y && y <= Y + H)
            ret++;
        else if (calc(X, Y + (H / 2), x, y) <= r)
            ret++;
        else if (calc(X + W, Y + (H / 2), x, y) <= r)
            ret++;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}