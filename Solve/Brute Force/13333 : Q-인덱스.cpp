#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ret;
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
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[j] >= i && i <= N - j && N - i <= j + 1) {
                ret = i;
            }
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}