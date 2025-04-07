#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int A, B, N, ret = INT_MAX;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> A >> B >> N;
}

void solve() {
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        ret = min(ret, abs(temp - B) + 1);
    }
    cout << min(ret, abs(A - B));
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}