#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, K;
vector<pair<ll, ll>> jew;
vector<int> bag;
priority_queue<ll, vector<ll>, less<ll>> pq;
ll ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int x, y;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        jew.push_back({x, y});
    }
    for (int i = 0; i < K; i++) {
        cin >> x;
        bag.push_back(x);
    }
}

void solve() {
    sort(jew.begin(), jew.end());
    sort(bag.begin(), bag.end());
    int j = 0;
    for (int i = 0; i < K; i++) {
        while (j < N && bag[i] >= jew[j].first) {
            pq.push(jew[j].second);
            j++;
        }
        if (pq.size()) {
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}