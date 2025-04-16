#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int P, N, ret;
vector<int> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> P >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
}

void solve() {
    for (int i = 0; i < N; i++) {
        if (P >= 200)
            break;
        P += arr[i];
        ret++;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}