#include <iostream>
#include <algorithm>

using namespace std;

int H, Y;
int DP[11];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> H >> Y;
    DP[0] = H;
}

void solve() {
    for (int i = 1; i <= Y; i++) {
        DP[i] = (int) (DP[i - 1] * 1.05);
        if (i >= 3) {
            DP[i] = max(DP[i], (int) (DP[i - 3] * 1.2));
        }
        if (i >= 5) {
            DP[i] = max((int) DP[i], (int) (DP[i - 5] * 1.35));
        }
    }
    cout << DP[Y];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}