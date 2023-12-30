#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int ret = 1;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> room;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        room.push_back({a, b});
    }
    sort(room.begin(), room.end());
}

void solve() {
    for (int i = 0; i < room.size(); i++) {
        pq.push(room[i].second);

        if (pq.top() <= room[i].first)
            pq.pop();
    }
    cout << pq.size();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}