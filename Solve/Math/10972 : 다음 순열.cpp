#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
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
}

void solve() {
    if (next_permutation(arr.begin(), arr.end())) {
        for (int i = 0; i < N; i++) {
            cout << arr[i] << ' ';
        }
    } else {
        cout << "-1";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}