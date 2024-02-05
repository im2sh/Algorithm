#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> room;
priority_queue<int, vector<int>, greater<int>> pq;
int ret = 1;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void Init() {
    int a, b, c;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        room.push_back({b, c});
    }
    sort(room.begin(), room.end());
}

void solve() {
    pq.push(room[0].second);
    for (int i = 1; i < N; i++) {
        if (room[i].first < pq.top())
            ret++;
        else
            pq.pop();
        pq.push(room[i].second);
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}