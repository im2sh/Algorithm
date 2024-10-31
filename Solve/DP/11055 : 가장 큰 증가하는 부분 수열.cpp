#include <iostream>
#include <algorithm>

using namespace std;

int N, ret;
int arr[1001];
int DP[1001];
int result[1001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 0; i < N; i++)
        result[i] = arr[i];
    fill(&DP[0], &DP[0] + 1001, 1);
}

void solve() {
    result[0] = arr[0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                if (DP[j] >= DP[i]) {
                    DP[i] = DP[j] + 1;
                    result[i] = max(result[i], arr[i] + result[j]);
                }
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        ret = max(ret, result[i]);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}