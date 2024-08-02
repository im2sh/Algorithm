#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ret;
vector<pair<int, int>> v;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

void solve() {
    sort(v.begin(), v.end(), cmp);
    for (int i = 5; i < N; i++) {
        if (v[i].first == v[4].first)
            ret++;
        else
            break;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}