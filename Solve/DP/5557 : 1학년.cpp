#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

int N;
int arr[101];
ll DP[101][21];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    memset(DP, 0, sizeof(DP));
}

ll go(int idx, int sum) {
    if (idx == N - 1)
        return (sum == arr[N - 1]) ? 1 : 0;

    if (DP[idx][sum] != 0)
        return DP[idx][sum];

    ll &ret = DP[idx][sum];
    ret = 0;

    if (sum + arr[idx] <= 20)
        ret += go(idx + 1, sum + arr[idx]);

    if (sum - arr[idx] >= 0)
        ret += go(idx + 1, sum - arr[idx]);

    return ret;
}

void solve() {
    cout << go(1, arr[0]);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}