#include <iostream>

using namespace std;
int N, K, A, B, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K >> A >> B;
}

void solve() {
    int temp = K;
    while (true) {
        ret++;
        if (ret % (N / A) == 0)
            temp += B;
        temp--;
        if (temp == 0)
            break;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
