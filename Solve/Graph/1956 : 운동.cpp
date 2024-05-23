#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int V, E, ret = 987654321;
vector<pair<int, int>> graph[401];
priority_queue<pair<int, int>> pq;
int dist[401];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1].push_back({b - 1, c});
    }
}

int go(int vertex) {
    pq.push({0, vertex});
    dist[vertex] = 0;
    bool flag = false;
    while (pq.size()) {
        int cur = pq.top().second;
        int weight = -pq.top().first;
        pq.pop();
        if (flag && cur == vertex)
            return weight;
        flag = true;
        if (dist[cur] < weight)
            continue;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int w = graph[cur][i].second + weight;

            if (next == vertex || dist[next] > w) {
                pq.push({-w, next});
                dist[next] = w;
            }
        }
    }
    return 987654321;
}

void solve() {
    for (int i = 0; i < V; i++) {
        fill(&dist[0], &dist[0] + 401, 987654321);
        ret = min(ret, go(i));
    }
    if (ret == 987654321)
        cout << -1;
    else
        cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
