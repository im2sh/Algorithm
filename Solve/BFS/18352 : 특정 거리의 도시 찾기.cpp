#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, K, X;
vector<int> ret;
vector<int> graph[300001];
int visited[300001];
queue<int> q;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> K >> X;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    visited[X] = 1;
    q.push(X);
}

void bfs() {
    while (q.size()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];

            if (!visited[next]) {
                visited[next] = visited[cur] + 1;
                q.push(next);
            }
        }
    }
}

void solve() {
    bfs();
    for (int i = 1; i <= N; i++) {
        if (visited[i] == (K + 1))
            ret.push_back(i);
    }
    if (!ret.size()) {
        cout << -1;
        return;
    }
    sort(ret.begin(), ret.end());
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}