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
    int temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
}

void solve() {
    int size = arr.size();
    if (size % 2 == 1)
        cout << arr[size / 2];
    else
        cout << arr[size / 2 - 1];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}