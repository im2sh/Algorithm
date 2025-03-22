#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ret = 1;
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
    sort(arr.begin(), arr.end());
}

void solve() {
    for (int i = 0; i < N; i++) {
        int sum = 1;
        for (int j = i + 1; j < i + 5; j++) {
            if (arr[j] - arr[i] < 5 && arr[j] - arr[i] > 0)
                sum++;
        }
        ret = max(ret, sum);
    }
    if (ret >= 5)
        cout << 0;
    else
        cout << 5 - ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}