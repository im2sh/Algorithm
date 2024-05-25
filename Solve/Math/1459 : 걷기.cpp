#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll X, Y, W, S, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> X >> Y >> W >> S;
}

void solve() {
    if (X > Y)
        swap(X, Y);
    ret = min((X + Y) * W, X * S + (Y - X) * W);

    if ((Y - X) % 2 == 1)
        ret = min(ret, (Y - 1) * S + W);
    else
        ret = min(ret, Y * S);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}