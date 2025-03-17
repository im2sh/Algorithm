#include <iostream>
#include <algorithm>

using namespace std;

int N, S, E, ret;
int DP[1001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S >> E;
        for (int j = S; j <= E; j++) {
            DP[j]++;
        }
    }
}

void solve() {
    int H = 0;
    int W = 0;
    for (int i = 0; i <= 365; i++) {
        if (DP[i] == 0) {
            ret += H * W;
            H = 0;
            W = 0;
        } else {
            W++;
            H = max(H, DP[i]);
        }
    }
    ret += H * W;
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}