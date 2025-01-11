#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int TC, N, ret;
vector<int> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    ret = 0;
    arr.clear();
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
}

void solve() {
    while (TC--) {
        Input();
        ret = max(ret, arr[1] - arr[0]);
        ret = max(ret, arr[N - 1] - arr[N - 2]);

        for (int i = 0; i < N - 2; i++) {
            ret = max(ret, arr[i + 2] - arr[i]);
        }
        cout << ret << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}