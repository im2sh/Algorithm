#include <iostream>
#include <queue>

using namespace std;

int N, M;
int BOARD[1001][1001];
int visited[1001][1001];
const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &BOARD[i][j]);
        }
    }
}

void BFS(int y, int x) {
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push(make_pair(y, x));

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || nx < 0 || ny >= M || nx >= N)
                continue;
            if (BOARD[ny][nx] == 0 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }

    }
}

void solve() {
    for (int j = 0; j < N; j++) {
        if (BOARD[0][j] == 0 && !visited[0][j]) {
            BFS(0, j);
        }
    }

    bool flag = false;
    for (int j = 0; j < N; j++) {
        if (visited[M - 1][j]) {
            flag = true;
        }
    }

    if (flag == true)
        cout << "YES";
    else
        cout << "NO";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
