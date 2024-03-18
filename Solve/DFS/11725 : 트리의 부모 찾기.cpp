#include <iostream>
#include <vector>

using namespace std;

int N;
int ret[100001];
bool visited[100001];
vector<int> graph[100001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void dfs(int cur) {
    visited[cur] = true;
    
    for (int i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i];
        if (!visited[next]) {
            ret[next] = cur;
            dfs(next);
        }
    }
}

void solve() {
    dfs(1);

    for (int i = 2; i <= N; i++)
        cout << ret[i] << '\n';
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}