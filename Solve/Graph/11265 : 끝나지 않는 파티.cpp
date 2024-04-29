#include <iostream>

using namespace std;
int N, M;
int graph[501][501];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }
}

void makeGraph() {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

void solve() {
    makeGraph();
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (graph[a - 1][b - 1] <= c) {
            cout << "Enjoy other party\n";
        } else {
            cout << "Stay here\n";
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}