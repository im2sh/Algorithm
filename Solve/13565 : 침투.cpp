#include <iostream>
#include <queue>

using namespace std;
const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

int N, M;
int BOARD[1001][1001];
bool visited[1001][1001];
queue<pair<int, int>> q;


void Init() {
    cin >> M >> N;
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            scanf("%1d", &BOARD[y][x]);
        }
    }
}

void BFS(int y, int x) {
    visited[y][x] = true;
    q.push({y, x});

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= M || nx >= N)
                continue;
            if (BOARD[ny][nx] == 0 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ny, nx});
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
        printf("YES");
    else
        printf("NO");
}

int main(void) {
    Init();
    solve();
    return 0;
}