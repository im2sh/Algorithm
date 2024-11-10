#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int TC, N, K, ret = 1;
vector<int> arr;
vector<pair<int, int>> result;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    arr.clear();
    result.clear();
    ret = 1;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    Input();
    int low = 0;
    int high = arr.size() - 1;

    while (low < high) {
        int sum = arr[low] + arr[high];
        result.push_back({sum, abs(K - sum)});
        if (sum < K) {
            low++;
        } else {
            high--;
        }
    }
    sort(result.begin(), result.end(), cmp);

    for (int i = 1; i < result.size(); i++) {
        if (result[i].second != result[i - 1].second)
            break;
        ret++;
    }
    cout << ret << '\n';
}

int main(void) {
    FastIO();
    Init();
    while (TC--)
        solve();
    return 0;
}