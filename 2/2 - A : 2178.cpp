#include <iostream>
#include <queue>

using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

const int V = 101;

int N, M;
int a[V][V];
int visited[V][V];

void search_g(int y, int x) {
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || a[ny][nx] == 0)
                continue;
            if (visited[ny][nx])
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}


int main(void) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    search_g(0, 0);
    cout << visited[N - 1][M - 1] << "\n";
    return 0;
}


