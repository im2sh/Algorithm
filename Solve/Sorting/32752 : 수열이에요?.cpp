#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L, R;
vector<int> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> L >> R;
    L--;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin() + L, arr.begin() + R);
}

void solve() {
    for (int i = 0; i < N - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            cout << "0";
            return;
        }
    }

    cout << "1";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}