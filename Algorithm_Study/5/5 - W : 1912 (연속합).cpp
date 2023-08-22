#include <iostream>
#include <algorithm>

using namespace std;

int N, ret = -987654321;
int arr[100001];

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
}

void solve() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        ret = max(ret, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    cout << ret << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}