#include <iostream>
#include <algorithm>

using namespace std;

int N, ret;
int arr[1001];
int DP[1001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        DP[i] = 1;
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i] && DP[i] < DP[j] + 1)
                DP[i] = DP[j] + 1;
        }
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