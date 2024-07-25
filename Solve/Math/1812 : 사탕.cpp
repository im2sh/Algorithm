#include <iostream>

using namespace std;
int N, ret;
int candy[1001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> candy[i];
        ret += candy[i];
    }
    ret /= 2;
}

void solve() {
    for (int i = 0; i < N; i++) {
        int temp = 0;
        for (int j = 0; j < N; j += 2)
            temp += candy[(i + j) % N];
        cout << temp - ret << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
