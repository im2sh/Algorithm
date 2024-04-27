#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M;
vector<int> graph[200004];
int visited[200004];
queue<int> q;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int cnt = 1;
    int temp;
    cin >> N;
    while (true) {
        if (cnt == N + 1)
            break;
        cin >> temp;
        if (temp == 0) {
            cnt++;
            continue;
        }

        graph[cnt].push_back(temp);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        q.push(temp);
        visited[temp] = 1;
    }
}

void solve() {
    int time = 1;
    queue<int> rumors;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        int rumor = 0;
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            rumor = 0;
            if (visited[next])
                continue;
            for (int j = 0; j < graph[next].size(); j++) {
                if (visited[graph[next][j]]) {
                    rumor++;
                }
            }
            if (rumor >= ((graph[next].size() + 1) / 2)) {
                rumors.push(next);
            }
        }
        if (q.empty()) {
            time++;
            while (rumors.size()) {
                int c = rumors.front();
                rumors.pop();
                visited[c] = time;
                q.push(c);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << visited[i] - 1 << ' ';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}