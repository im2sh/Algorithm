#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int N, M;
vector<pair<int, int>> graph[50001];
int visited[50001];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1].push_back({b - 1, c});
        graph[b - 1].push_back({a - 1, c});
    }
    fill(&visited[0], &visited[0] + 50001, 1e9);
}

void solve() {
    pq.push({0, 0});
    visited[0] = 0;
    while (pq.size()) {
        int now = pq.top().first;
        int weight = pq.top().second;
        pq.pop();

        if (now == N - 1) {
            cout << visited[N - 1];
            return;
        }

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            int next_weight = weight + graph[now][i].second;

            if (visited[next] > next_weight) {
                pq.push({next, next_weight});
                visited[next] = next_weight;
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