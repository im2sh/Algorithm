#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, paper_num, area_cnt, ret = 0;
vector<pair<int, int>> paper;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    cin >> paper_num;
    cin >> area_cnt;

    for (int i = 0; i < area_cnt; i++) {
        int x, y;
        cin >> y >> x;
        paper.push_back({y, x});
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

bool check(int mid) {
    int cnt = 1;
    int x = paper[0].second;
    for (int i = 1; i < area_cnt; i++) {
        if (x + mid <= paper[i].second) {
            x = paper[i].second;
            cnt++;
        }
    }
    if (cnt <= paper_num)
        return true;
    return false;
}

void solve() {
    int low = 0;
    int high = 1000000;
    for (int i = 0; i < area_cnt; i++) {
        if (low < paper[i].first)
            low = paper[i].first;
    }
    sort(paper.begin(), paper.end(), cmp);

    while (low <= high) {
        int mid = (low + high) / 2;

        if (check(mid)) {
            ret = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
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
