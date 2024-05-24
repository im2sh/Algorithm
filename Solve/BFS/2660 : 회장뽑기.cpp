#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int N, ret = 987654321;
vector<int> graph[51];
vector<pair<int, int>> candidate;
vector<int> answer;
bool visited[51];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
}

void bfs(int start) {
    queue<pair<int, int>> q;
    visited[start] = true;
    q.push({start, 0});
    int max_score = 0;
    while (q.size()) {
        int cur = q.front().first;
        int weight = q.front().second;
        q.pop();
        max_score = max(max_score, weight);
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (visited[next])
                continue;
            visited[next] = true;
            q.push({next, weight + 1});
        }
    }
    candidate.push_back({start + 1, max_score});
    ret = min(ret, max_score);
}

void solve() {
    for (int i = 0; i < N; i++) {
        fill(&visited[0], &visited[0] + 51, false);
        bfs(i);
    }
    for (int i = 0; i < candidate.size(); i++) {
        if (candidate[i].second == ret)
            answer.push_back(candidate[i].first);
    }
    sort(answer.begin(), answer.end());
    cout << ret << ' ' << answer.size() << '\n';
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}