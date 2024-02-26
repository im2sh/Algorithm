#include <iostream>
#include <queue>

using namespace std;

int V, E, K;
vector<pair<int, int>> graph[20001];
int dist[20001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int u, v, w;
    cin >> V >> E;
    cin >> K;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    for (int i = 1; i <= V; i++) {
        dist[i] = 987654321;
    }
}

void solve() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, K});
    dist[K] = 0;
    while (pq.size()) {
        int cur_dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int next_dist = graph[cur][i].second;

            if (dist[next] > cur_dist + next_dist) {
                dist[next] = cur_dist + next_dist;
                pq.push({dist[next], next});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == 987654321)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}