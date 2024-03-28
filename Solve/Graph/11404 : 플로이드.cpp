#include <iostream>
#include <vector>

using namespace std;

int N, M;
int graph[101][101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b, w;
    fill(&graph[0][0], &graph[0][0] + 101 * 101, 987654321);
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> w;
        if (graph[a][b] < w)
            continue;
        graph[a][b] = w;
    }
}


void go() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

void solve() {
    go();
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            if (y == x)
                cout << '0' << ' ';
            else if (graph[y][x] == 987654321)
                cout << '0' << ' ';
            else
                cout << graph[y][x] << ' ';
        }
        cout << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}