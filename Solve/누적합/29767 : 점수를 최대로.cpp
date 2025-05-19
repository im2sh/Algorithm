#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, K;
ll ret;
ll arr[300001];


void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    cin >> arr[0];

    for (int i = 1; i < N; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    sort(arr, arr + N, greater<ll>());
}

void solve() {
    for (int i = 0; i < K; i++) {
        ret += arr[i];
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}