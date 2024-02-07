#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, ret;
vector<pair<int, int>> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

void Init() {
    int x, y;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        arr.push_back({x, y});
    }
    sort(arr.begin(), arr.end(), cmp);
}

void solve() {
    int start = arr[0].first;
    int end = arr[0].second;
    for (int i = 1; i < N; i++) {
        if (end >= arr[i].first) {
            if (end >= arr[i].second)
                continue;
            end = arr[i].second;
        } else {
            ret += abs(end - start);
            start = arr[i].first;
            end = arr[i].second;
        }
    }
    ret += end - start;
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}