#include <iostream>
#include <algorithm>

using namespace std;

int N, ret;
int arr[1004];
int DP[1004];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        DP[i] = arr[i];
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] < arr[j]) {
                DP[i] = max(DP[i], DP[j] + arr[i]);
            }
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