#include <iostream>

using namespace std;
int N;
int arr[304];
int DP[304];

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
    DP[1] = arr[1];
    DP[2] = arr[1] + arr[2];
    DP[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
    for (int i = 4; i <= N; i++) {
        DP[i] = max(DP[i - 3] + arr[i - 1] + arr[i], DP[i - 2] + arr[i]);
    }

    cout << DP[N];
}

void solve() {

}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}