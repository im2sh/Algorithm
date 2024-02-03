#include <iostream>
#include <queue>

using namespace std;

int N, M;
int BOARD[1001][1001];
int visited[1001][1001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b, c;
    cin >> N >> M;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> c;
        BOARD[a - 1][b - 1] = c;
        BOARD[b - 1][a - 1] = c;
    }
}

void display() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << visited[y][x] << " ";
        }
        cout << '\n';
    }
}

int bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, 0});

    while (q.size()) {
        int start = q.front().first;
        int dist = q.front().second;

        if (start == b) {
            return dist;
        }
        q.pop();

        for (int i = 0; i < N; i++) {
            if (BOARD[start][i] && !visited[start][i]) {
                visited[start][i] += BOARD[start][i] + dist;
                q.push({i, visited[start][i]});
            }
        }
    }
}

void solve() {
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        fill(&visited[0][0], &visited[0][0] + 1001 * 1001, 0);
        cout << bfs(a - 1, b - 1) << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}