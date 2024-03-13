#include <iostream>
#include <vector>

using namespace std;

int TC, N, ret;
vector<vector<int>> graph;
bool visited[1001];


void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void dfs(int x) {
    if (visited[x] == true)
        return;
    visited[x] = true;

    for (int i = 0; i < graph[x].size(); i++) {
        dfs(graph[x][i]);
    }

}

void solve() {
    while (TC--) {
        cin >> N;
        graph.clear();
        graph.resize(N + 1);
        fill(&visited[0], &visited[0] + 1001, false);

        int num;
        for (int j = 1; j < N + 1; j++) {
            cin >> num;
            graph[j].push_back(num);
        }

        ret = 0;
        for (int j = 1; j < N + 1; j++) {
            if (visited[j] == 1)
                continue;
            dfs(j);
            ret++;
        }

        cout << ret << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}