#include <iostream>

using namespace std;
int N, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    int l = 1;
    int r = 1;
    int sum = 0;
    while (l <= r && r <= N) {
        if (sum < N)
            sum += r++;
        else {
            if (sum == N)
                ret++;
            sum -= l++;
        }
    }
    cout << ret + 1;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}