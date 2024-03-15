#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, M, R, ret;
int item[101];
int visited[101];
vector<pair<int, int>> graph[101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b, c;

    cin >> N >> M >> R;
    for (int i = 0; i < N; i++) {
        cin >> item[i];
    }
    for (int i = 0; i < R; i++) {
        cin >> a >> b >> c;
        graph[a - 1].push_back({b - 1, c});
        graph[b - 1].push_back({a - 1, c});
    }
}

void go(int cur) {
    queue<pair<int, int>> q; // {갈곳, 가중치}
    q.push({cur, 0});
    visited[cur] = 1;

    while (q.size()) {
        cur = q.front().first;
        int curWeight = q.front().second;
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nextWeight = graph[cur][i].second;

            if (curWeight + nextWeight > M)
                continue;
            q.push({next, curWeight + nextWeight});
            visited[next] = 1;
        }
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        int sum = 0;
        fill(&visited[0], &visited[0] + 101, 0);
        go(i);
        for (int j = 0; j < N; j++) {
            if (visited[j]) {
                sum += item[j];
            }
        }
        ret = max(ret, sum);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}