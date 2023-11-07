#include <iostream>
#include <queue>

using namespace std;

int N, M;
bool flag = false;
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
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            scanf("%1d", &BOARD[y][x]);
        }
    }
}

bool BFS(int y, int x) {
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

            if (ny < 0 || ny >= M || nx < 0 || nx >= N)
                continue;
            if (BOARD[ny][nx] == 1 || visited[ny][nx])
                continue;
            visited[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
    for (int i = 0; i < N; i++) {
        if (visited[M - 1][i])
            return true;
    }
    return false;
}

void solve() {
    for (int i = 0; i < N; i++) {
        if (BOARD[0][i] == 0 && !visited[0][i]) {
            if (BFS(0, i)) {
                flag = true;
            }
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
