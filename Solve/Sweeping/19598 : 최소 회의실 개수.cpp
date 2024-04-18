#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
int N, ret = 0;
vector<pair<int, int>> room;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        room.push_back({s, e});
    }
    sort(room.begin(), room.end());
}

void solve() {
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(room[0].second);

    for (int i = 1; i < room.size(); i++) {
        if (pq.size() && pq.top() <= room[i].first) {
            pq.pop();
        }
        pq.push(room[i].second);
        ret = max(ret, (int) pq.size());
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}