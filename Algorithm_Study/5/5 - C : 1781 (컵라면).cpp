#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int ret;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> ramen;

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
        ramen.push_back({x, y});
    }
}

void solve() {
    sort(ramen.begin(), ramen.end());
    for (int i = 0; i < N; i++) {
        pq.push(ramen[i].second);
        ret += ramen[i].second;
        if (pq.size() > ramen[i].first) {
            ret -= pq.top();
            pq.pop();
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    cout << ret << "\n";
    return 0;
}