#include <iostream>

using namespace std;

int N, ret;
string cmd;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> cmd;
}

void solve() {
    for (int i = 0; i < N - 1; i++) {
        if (cmd[i] == 'E' && cmd[i + 1] == 'W')
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
