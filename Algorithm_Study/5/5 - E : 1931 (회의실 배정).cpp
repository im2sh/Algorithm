#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int ret = 1;
vector<pair<int, int>> room;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int x, y;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        room.push_back({y, x});
    }
}

void solve() {
    sort(room.begin(), room.end());
    int from = room[0].second;
    int to = room[0].first;
    for (int i = 1; i < N; i++) {
        if (room[i].second < to)
            continue;
        from = room[i].second;
        to = room[i].first;
        ret++;
    }
    cout << ret << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}