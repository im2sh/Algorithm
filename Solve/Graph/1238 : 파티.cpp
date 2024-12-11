#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Edge {
    int end, weight;
};

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int N, M, X, ret;
vector<Edge> graph[1001];
int dist[1001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
}

int go(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i].end;
        int weight = graph[start][i].weight;
        pq.push({next, weight});
        dist[next] = weight;
    }

    while (pq.size()) {
        int cur = pq.top().first;
        int cur_weight = pq.top().second;
        pq.pop();

        if (cur == end) {
            return dist[end];
        }


        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].end;
            int next_weight = graph[cur][i].weight;

            if (dist[next] > cur_weight + next_weight) {
                pq.push({next, cur_weight + next_weight});
                dist[next] = cur_weight + next_weight;
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        if (i == X)
            continue;
        fill(&dist[0], &dist[0] + 1001, 987654321);
        int goFromHomeToX = go(i, X);
        fill(&dist[0], &dist[0] + 1001, 987654321);
        int goFromXToHome = go(X, i);
        ret = max(ret, goFromHomeToX + goFromXToHome);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}