#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int TC, N, minNum = INT_MAX, maxNum = INT_MIN;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        minNum = min(minNum, temp);
        maxNum = max(maxNum, temp);
    }
}

void solve() {
    cout << 2 * abs(maxNum - minNum);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}