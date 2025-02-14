#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<double, int>> monitor;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int W, H;
        cin >> W >> H;
        monitor.push_back({sqrt((W * W) + H * H) / 77, i + 1});
    }
}

bool cmp(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

void solve() {
    sort(monitor.begin(), monitor.end(), cmp);
    for (auto &it: monitor) {
        cout << it.second << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}