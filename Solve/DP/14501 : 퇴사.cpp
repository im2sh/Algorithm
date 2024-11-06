#include <iostream>
#include <algorithm>

using namespace std;

int N, ret;
pair<int, int> company[16];
int DP[21];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        company[i] = {a, b};
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        DP[i + 1] = max(DP[i + 1], DP[i]);
        if (company[i].first + i > N)
            continue;
        DP[i + company[i].first] = max(DP[company[i].first + i], company[i].second + DP[i]);
    }

    for (int i = 0; i <= N; i++) {
        ret = max(ret, DP[i]);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}