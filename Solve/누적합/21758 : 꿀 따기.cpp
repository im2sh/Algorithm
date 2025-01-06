#include <iostream>
#include <algorithm>

using namespace std;

int N, ret;
int arr[100004];
int prefix[100004];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        prefix[i] += prefix[i - 1] + arr[i];
    }
    prefix[0] = prefix[1];
}

void solve() {
    for (int i = 2; i < N; i++) {
        int bee = (prefix[i] - prefix[1]) + (prefix[N - 1] - prefix[i - 1]);
        ret = max(ret, bee);
    }

    for (int i = 2; i < N; i++) {
        int bee = (prefix[N] - prefix[1] - arr[i]) + (prefix[N] - prefix[i]);
        ret = max(ret, bee);
    }

    for (int i = 2; i < N; i++) {
        int bee = (prefix[N - 1] - arr[i]) + prefix[i - 1];
        ret = max(ret, bee);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}