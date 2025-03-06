#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, W;
vector<int> seq;
int DP[1001][31][3];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> T >> W;
    for (int i = 0; i < T; i++) {
        int temp;
        cin >> temp;
        seq.push_back(temp);
    }
}

int go(int now, int idx, int cnt) {
    if (cnt < 0 || idx > T)
        return 0;

    if (DP[idx][cnt][now])
        return DP[idx][cnt][now];

    if (now == 1) {
        DP[idx][cnt][now] = max(go(now, idx + 1, cnt), go(2, idx + 1, cnt - 1));
    } else {
        DP[idx][cnt][now] = max(go(1, idx + 1, cnt - 1), go(now, idx + 1, cnt));
    }

    if (now == seq[idx])
        DP[idx][cnt][now]++;
    return max(DP[idx][cnt][1], DP[idx][cnt][2]);
}

void solve() {
    cout << max(go(1, 0, W), go(2, 0, W - 1));
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}