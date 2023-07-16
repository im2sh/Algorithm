#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;

priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> temp;
int ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        temp.push_back({y, x});
    }
}


void solve() {
    sort(temp.begin(), temp.end());
    for (int i = 0; i < N; i++) {
        pq.push(temp[i].second);
        while (pq.size() > temp[i].first)
            pq.pop();
    }

    while (pq.size()) {
        ret += pq.top();
        pq.pop();
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    cout << ret << "\n";
    return 0;
}