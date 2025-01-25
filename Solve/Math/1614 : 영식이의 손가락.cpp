#include <iostream>

typedef long long ll;

using namespace std;

ll F, N, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> F >> N;
}

void solve() {
    if (F == 1)
        ret = N * 8;
    else if (F == 5)
        ret = N * 8 + 4;
    else if (F == 3)
        ret = N * 4 + 2;
    else if (F == 2) {
        if (N % 2 == 0)
            ret = N * 4 + 1;
        else
            ret = N * 4 + 3;
    } else {
        if (N % 2 == 0)
            ret = N * 4 + 3;
        else
            ret = N * 4 + 1;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}