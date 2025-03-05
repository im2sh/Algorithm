#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

typedef struct pos {
    int vertex;
    ll weight;
    int cnt;
    string path;
} Pos;

int N, M, S, E;
ll dist[1001];

vector<pair<int, ll>> graph[1001];

typedef struct cmp {
    bool operator()(Pos a, Pos b) {
        return a.weight > b.weight;
    }
};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    cin >> S >> E;
    fill(&dist[0], &dist[0] + 1001, LLONG_MAX);
}

void solve() {
    priority_queue<Pos, vector<Pos>, cmp> pq;
    dist[S] = 0;
    pq.push({S, 0, 1, to_string(S)});

    while (pq.size()) {
        int now = pq.top().vertex;
        ll weight = pq.top().weight;
        int cnt = pq.top().cnt;
        string path = pq.top().path;

        pq.pop();

        if (now == E) {
            cout << dist[E] << '\n';
            cout << cnt << '\n';
            for (int i = 0; i < path.length(); i++) {
                cout << path[i];
            }
            break;
        }

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            ll next_weight = graph[now][i].second;

            if (dist[next] > weight + next_weight) {
                pq.push({next, weight + next_weight, cnt + 1, path + " " + to_string(next)});
                dist[next] = weight + next_weight;
            }
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}