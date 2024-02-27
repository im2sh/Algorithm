#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;


int N, M;
vector<pair<ll, ll>> graph[100001];
ll cantgo[100001];
ll dist[100001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b, c;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> cantgo[i];
        dist[i] = 2e16;
    }
    cantgo[N - 1] = 0;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
}

void solve() {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (pq.size()) {
        ll cur = pq.top().second;
        ll cur_weight = pq.top().first;
        pq.pop();

        if (cur_weight > dist[cur]) {
            continue;
        }

        for (int i = 0; i < graph[cur].size(); i++) {
            ll next = graph[cur][i].first;
            ll next_weight = graph[cur][i].second;

            if (cantgo[next] == 1)
                continue;

            if (dist[next] > dist[cur] + next_weight) {
                dist[next] = dist[cur] + next_weight;
                pq.push({dist[next], next});
            }
        }
    }

    if (dist[N - 1] == 2e16)
        cout << "-1";
    else
        cout << dist[N - 1];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}