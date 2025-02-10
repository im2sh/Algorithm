#include <iostream>

using namespace std;

int N, minNum;
int arr[200004];
int DP[200004];

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
    DP[0] = 0;
    minNum = arr[0];
}

void solve() {
    for (int i = 1; i < N; i++) {
        if (arr[i] < minNum)
            minNum = arr[i];
        DP[i] = arr[i] - minNum > DP[i - 1] ? arr[i] - minNum : DP[i - 1];
    }
    cout << DP[N - 1];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}