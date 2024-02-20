#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int visited[32004];
vector<int> graph[32004];
vector<int> ret;
queue<int> q;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        visited[b]++;
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        if (!visited[i])
            q.push(i);
    }

    while (q.size()) {
        int x = q.front();
        q.pop();
        ret.push_back(x);

        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            visited[y]--;
            if (!visited[y]) {
                q.push(y);
            }
        }
    }

    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << ' ';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}