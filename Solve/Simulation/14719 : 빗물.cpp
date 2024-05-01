#include <iostream>
#include <algorithm>

using namespace std;
int H, W, ret;
int block[504];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> H >> W;
    for (int i = 0; i < W; i++) {
        cin >> block[i];
    }
}

void solve() {
    for (int i = 1; i < W - 1; i++) {
        int maxLB = 0;
        int maxRB = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (block[i] <= block[j])
                maxLB = max(maxLB, block[j]);
        }
        for (int j = i + 1; j < W; j++) {
            if (block[i] <= block[j])
                maxRB = max(maxRB, block[j]);
        }
        if (maxLB == 0 || maxRB == 0)
            continue;
        int minB = min(maxLB, maxRB);
        ret += minB - block[i];
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}