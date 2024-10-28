#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ret;
vector<pair<int, int>> works;

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
        works.push_back({a, b});
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

void solve() {
    sort(works.begin(), works.end(), cmp);
    int idx = 0;
    for (int days = 0; idx < N; days++) {
        while (works[idx].first < days) {
            if (idx >= N)
                break;
            ret += works[idx].second;
            if (ret >= days) {
                cout << "-1";
                return;
            }
            idx++;
        }
        if (days % 7 == 0 || days % 7 == 6)
            continue;
        works[idx].second--;
        if (works[idx].second == 0)
            idx++;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}