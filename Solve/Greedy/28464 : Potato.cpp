#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, aCnt, bCnt;
vector<int> arr;

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
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), greater<>());
}

void solve() {
    for (int i = (N + 1) / 2; i < N; i++) {
        aCnt += arr[i];
    }
    for (int i = 0; i < (N + 1) / 2; i++) {
        bCnt += arr[i];
    }
    cout << aCnt << " " << bCnt;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}