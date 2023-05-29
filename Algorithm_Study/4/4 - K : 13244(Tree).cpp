#include <iostream>

using namespace std;

int T, N, M, cnt;

int graph[1004][1004];
int visited[1004];
bool ok;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> T;
}

void dfs(int idx) {
    visited[idx] = 1;

    for (int i = 1; i <= N; i++) {
        if (!visited[i] && graph[idx][i])
            dfs(i);
    }
}

void solve() {
    int x, y;
    while (T--) {
        cin >> N;
        cin >> M;
        cnt = 0;
        ok = true;
        fill(&graph[0][0], &graph[0][0] + 1001 * 1001, 0);
        fill(&visited[0], &visited[0] + 1001, 0);

        for (int i = 0; i < M; i++) {
            cin >> x >> y;
            if (graph[x][y] == 0) {
                graph[x][y] = 1;
                graph[y][x] = 1;
            }
        }

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                cnt++;
                dfs(i);
            }
        }

        if (cnt > 1)
            ok = false;

        if (ok && (N - M == 1))
            cout << "tree" << "\n";
        else
            cout << "graph" << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
