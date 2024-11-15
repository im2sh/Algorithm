#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int INF = 2400001;

typedef struct Node {
    int v, w;
};

struct cmp {
    bool operator()(Node a, Node b) {
        return a.w > b.w;
    }
};

int N, E, v1, v2, ret = INF;
vector<pair<int, int>> graph[801];
priority_queue<Node, vector<Node>, cmp> pq;
int dist[801];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> v1 >> v2;
    v1--, v2--;
}

void go(int start) {
    fill(&dist[0], &dist[0] + 801, INF);
    while (pq.size()) {
        pq.pop();
    }
    pq.push({start, 0});
    dist[start] = 0;
    while (pq.size()) {
        Node cur = pq.top();
        pq.pop();

        for (int i = 0; i < graph[cur.v].size(); i++) {
            int next = graph[cur.v][i].first;
            int weight = graph[cur.v][i].second;

            if (dist[next] > cur.w + weight) {
                dist[next] = cur.w + weight;
                pq.push({next, cur.w + weight});
            }
        }
    }
}

void solve() {
    go(0);
    int start_to_v1 = dist[v1];
    int start_to_v2 = dist[v2];

    go(v1);
    int v1_to_v2 = dist[v2];
    int v1_to_end = dist[N - 1];

    go(v2);
    int v2_to_end = dist[N - 1];

    ret = min(start_to_v1 + v1_to_v2 + v2_to_end, start_to_v2 + v1_to_v2 + v1_to_end);

    if (ret >= INF)
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