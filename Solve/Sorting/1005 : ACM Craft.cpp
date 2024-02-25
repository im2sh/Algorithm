#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int TC, N, K;
int X, Y, W;
int weight[100001];
int visited[100001];
int indegree[100001];
vector<int> graph[100001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void initAll() {
    for (int i = 0; i < N; i++) {
        graph[i].clear();
        indegree[i] = 0;
        weight[i] = 0;
        visited[i] = 0;
    }
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> weight[i];
    }

    for (int i = 0; i < K; i++) {
        cin >> X >> Y;
        graph[X - 1].push_back(Y - 1);
        indegree[Y - 1]++;
    }

    cin >> W;
}

void BFS() {
    queue<int> q;
    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            visited[i] = weight[i];
        }
    }

    while (q.size()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < graph[x].size(); i++) {
            int next = graph[x][i];
            indegree[next]--;

            visited[next] = max(visited[next], visited[x] + weight[next]);

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }
}

void solve() {
    while (TC--) {
        initAll();
        BFS();
        cout << visited[W - 1] << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}