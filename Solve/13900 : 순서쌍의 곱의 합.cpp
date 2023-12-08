#include <iostream>

using namespace std;

typedef long long ll;

int N;
ll arr[100001];
ll ret;
ll psum[100001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
}

void solve() {
    psum[0] = arr[0];

    for (int i = 1; i < N; ++i) {
        psum[i] = psum[i - 1] + arr[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        ret += arr[i] * (psum[N - 1] - psum[i]);
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}