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
    fill(&DP[0], &DP[0] + 1001, 1);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                if (DP[i] < DP[j] + 1) {
                    DP[i] = DP[j] + 1;
                }
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