#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, T;
vector<pair<int, int>> v;
int DP[101][10001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        int time = v[i - 1].first;
        int val = v[i - 1].second;

        for (int j = 0; j <= T; j++) {
            if (j < time)
                DP[i][j] = DP[i - 1][j];
            else
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - time] + val);
        }
    }
    cout << DP[N][T];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}