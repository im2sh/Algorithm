#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int TC, N, M, ret = -1;
bool visited[504];
vector<int> graph[504];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    ret = -1;
    for (int i = 0; i < 504; i++) {
        graph[i].clear();
    }
    fill(&visited[0], &visited[0] + 504, false);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void go() {
    queue<pair<int, int>> q;
    q.push({1, 0});

    if (graph[1].empty()) {
        ret = 0;
        return;
    }

    while (q.size()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            int next_cnt = cnt + 1;

            if (visited[next] || next_cnt > 2)
                continue;
            ret++;
            visited[next] = true;
            q.push({next, next_cnt});
        }
    }
}

void solve() {
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        Init();
        go();

        cout << '#' << i << ' ' << ret << '\n';
    }
}

int main(void) {
    FastIO();
    solve();
    return 0;
}