#include <iostream>

using namespace std;

typedef long long ll;

ll N, K, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
}

void solve() {
    for (int i = 1; i <= N; i++) {
        int temp = i;

        while (temp) {
            temp /= 10;
            ret *= 10;
        }
        ret += i;
        ret %= K;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}