#include <iostream>
#include <algorithm>

using namespace std;

int N, ret;
int arr[1004];

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

    sort(arr, arr + N);
}

void solve() {
    for (int i = 0; i < N; i++) {
        int cnt = upper_bound(arr, arr + N, arr[i]) - lower_bound(arr, arr + N, arr[i]);
        ret = max(ret, cnt);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}