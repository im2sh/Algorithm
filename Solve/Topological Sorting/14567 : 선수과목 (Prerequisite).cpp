#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> graph[1001];
int degree[1001];
int result[1001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        degree[b]++;
    }
}

void solve() {
    queue<pair<int, int>> q;
    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) {
            q.push({i, 1});
            result[i] = 1;
        }
    }

    while (q.size()) {
        int now = q.front().first;
        int depth = q.front().second;
        q.pop();

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            degree[next]--;
            if (degree[next] == 0) {
                q.push({next, depth + 1});
                result[next] = depth + 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << result[i] << ' ';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}