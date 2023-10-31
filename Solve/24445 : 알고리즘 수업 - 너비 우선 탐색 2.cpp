#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N, M, R;
vector<int> adj[100001];
int visited[100001];
int ret = 1;

void FastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool cmp(int a, int b) {
    return a > b;
}

void Init() {
    cin >> N >> M >> R;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end(), cmp);
    }
}

void solve() {
    queue<int> q;
    q.push(R);
    visited[R] = ret++;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto now: adj[cur]) {
            if (visited[now] != 0)
                continue;
            visited[now] = ret++;
            q.push(now);
        }

    }

    for (int i = 1; i <= N; i++) {
        cout << visited[i] << '\n';
    }
}

int main() {
    FastIO();
    Init();
    solve();
    return 0;
}
