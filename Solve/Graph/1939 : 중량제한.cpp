#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
int N, M, ret = -1;
vector<pair<int, int>> graph[10001];
pair<int, int> dest;
int visited[10001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b, c;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }


    cin >> a >> b;
    dest = {a, b};
}

bool bfs(int target) {
    queue<int> q;
    q.push(dest.first);
    visited[dest.first] = 1;

    while (q.size()) {
        int cur = q.front();
        q.pop();
        if (cur == dest.second)
            break;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int weight = graph[cur][i].second;
            if (visited[next])
                continue;
            if (weight < target)
                continue;
            q.push(next);
            visited[next] = 1;
        }
    }
    if (visited[dest.second])
        return true;
    return false;
}

void solve() {
    int low = 0;
    int high = 1000000001;
    while (low <= high) {
        fill(&visited[0], &visited[0] + 10001, 0);
        int mid = (low + high) / 2;
        if (bfs(mid)) {
            ret = max(ret, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
