#include <iostream>
#include <algorithm>

using namespace std;

int N, cnt, ret;
int arr[100004];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    for (int i = 0; i < 2 * N; i++) {
        int temp;
        cin >> temp;
        arr[temp - 1]++;
        cnt++;
        if (arr[temp - 1] == 2) {
            cnt -= 2;
        }
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
