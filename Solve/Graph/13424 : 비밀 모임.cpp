#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int TC, N, M, K;
vector<pair<int, int>> graph[101];
vector<int> friends;
vector<pair<int, int>> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    for (int i = 0; i < 101; i++) {
        graph[i].clear();
    }
    friends.clear();
    ret.clear();

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a - 1].push_back({b - 1, w});
        graph[b - 1].push_back({a - 1, w});
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        int temp;
        cin >> temp;
        friends.push_back(temp - 1);
    }
}

void go(int vertex) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, vertex});
    int dist[101];
    fill(&dist[0], &dist[0] + 101, 987654321);
    dist[vertex] = 0;
    while (pq.size()) {
        int cur_weight = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int next_weight = graph[cur][i].second;
            
            if (dist[next] > cur_weight + next_weight) {
                dist[next] = cur_weight + next_weight;
                pq.push({-(cur_weight + next_weight), next});
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < friends.size(); i++) {
        sum += dist[friends[i]];
    }
    ret.push_back({vertex, sum});
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

void solve() {
    for (int i = 0; i < TC; i++) {
        Input();
        for (int v = 0; v < N; v++) {
            go(v);
        }
        sort(ret.begin(), ret.end(), cmp);
        cout << ret[0].first + 1 << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}