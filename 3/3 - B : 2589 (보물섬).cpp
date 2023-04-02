#include <iostream>
#include <queue>
#include <algorithm>

#define SIZE 54
using namespace std;
int N, M;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

char bomul[SIZE][SIZE];
int visited[SIZE][SIZE];
int result = -1;

int findMax() {
    int ret = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ret = max(ret, visited[i][j]);
        }
    }
    return ret;
}

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || bomul[ny][nx] == 'W' || visited[ny][nx])
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> bomul[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (bomul[i][j] == 'L') {
                bfs(i, j);
                result = max(result, findMax());
                fill(&visited[0][0], &visited[0][0] + SIZE * SIZE, 0);
            }
        }
    }

    cout << result - 1 << "\n";
    return 0;

}