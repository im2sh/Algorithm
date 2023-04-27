#include <iostream>

#define MAX_VER 1004

using namespace std;

int N, M;
int graph[MAX_VER][MAX_VER];
int visited[MAX_VER];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    int y, x;
    for (int i = 0; i < M; i++) {
        cin >> y >> x;
        graph[y - 1][x - 1] = 1;
        graph[x - 1][y - 1] = 1;
    }
}

void dfs(int start) {
    visited[start] = 1;
    for (int i = 0; i < N; i++) {
        if (graph[start][i] && !visited[i]) {
            visited[i] = 1;
            dfs(i);
        }
    }
}

void display() {
    for (int i = 0; i < N; i++) {
        cout << visited[i] << " ";
    }
}

void solve() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}