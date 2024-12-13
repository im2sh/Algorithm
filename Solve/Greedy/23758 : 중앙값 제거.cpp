#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int N, ret;
vector<int> arr;
vector<int> temp_arr;

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
        temp_arr.emplace_back(temp);
    }
    sort(temp_arr.begin(), temp_arr.end());
    for (int i = 0; i < (N + 1) / 2; i++) {
        arr.push_back(temp_arr[i]);
    }
}

void solve() {
    for (int i = 0; i < arr.size(); i++) {
        ret += log2(arr[i]);
    }
    cout << ret + 1;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}