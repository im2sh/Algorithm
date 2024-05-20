#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, M;
vector<pair<int, int>> graph[204];
int dist[204][204];
int pre[204];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a - 1].push_back({b - 1, w});
        graph[b - 1].push_back({a - 1, w});
    }
}

void go(int start) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    while (q.size()) {
        int cur = q.front().first;
        int weight = q.front().second;
        q.pop();
        if (dist[start][cur] < weight)
            continue;
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int next_weight = graph[cur][i].second;
            if (next == start)
                continue;
            if (dist[start][next] > weight + next_weight) {
                dist[start][next] = weight + next_weight;
                q.push({next, weight + next_weight});
                pre[next] = cur;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (i == start) {
            cout << "- ";
        } else if (pre[i] == start) {
            cout << i + 1 << ' ';
        } else {
            int cur = i;
            while (true) {
                if (pre[cur] == start) {
                    cout << cur + 1 << ' ';
                    break;
                } else {
                    cur = pre[cur];
                }
            }
        }
    }
    cout << '\n';
}

void solve() {
    fill(&dist[0][0], &dist[0][0] + 204 * 204, 987654321);

    for (int i = 0; i < N; i++) {
        go(i);
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}