#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1004];
int DP[1004];

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
        int maxNum = arr[i];
        int minNum = arr[i];
        for (int j = i - 1; j > 0; j--) {
            maxNum = max(maxNum, arr[j]);
            minNum = min(minNum, arr[j]);

            DP[i] = max(DP[i], maxNum - minNum + DP[j - 1]);
        }
    }

    cout << DP[N];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}