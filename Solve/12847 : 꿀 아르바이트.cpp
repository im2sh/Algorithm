#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
long long ret = 0;
int arr[100001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

void solve() {
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        if (i > M) {
            sum -= arr[i - M];
        }
        sum += arr[i];
        ret = max(ret, sum);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}