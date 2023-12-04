#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<int> lion;
int ret = 987654321;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> temp;
        if (temp == 1)
            lion.push_back(i);
    }
}

void solve() {
    if (lion.size() < K) {
        cout << -1 << '\n';
        return;
    }

    for (int i = 0; i <= lion.size() - K; i++) {
        ret = min(ret, lion[i + K - 1] - lion[i] + 1);
    }

    cout << ret << '\n';
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}