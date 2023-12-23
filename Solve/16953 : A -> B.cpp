#include <iostream>
#include <algorithm>

using namespace std;
int ret = 987654321;
long long A, B;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> A >> B;
}

void go(long long a, int depth) {
    if (a > B)
        return;

    if (a == B) {
        ret = min(ret, depth);
    }
    go(a * 2, depth + 1);
    go(a * 10 + 1, depth + 1);

}

void solve() {
    go(A, 1);

    if (ret == 987654321)
        cout << -1;
    else
        cout << ret;

}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}