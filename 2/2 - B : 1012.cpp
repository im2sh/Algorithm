#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 51

int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int ny, nx, N, M, K;

void dfs(int x, int y) {
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        if (!visited[nx][ny] && arr[nx][ny])
            dfs(nx, ny);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt = 0;
    int T;
    cin >> T;
    int x, y;
    while (T--) {
        cnt = 0;
        fill(&arr[0][0], &arr[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

        cin >> M >> N >> K;
        for (int i = 0; i < K; i++) {
            cin >> x >> y;
            arr[x][y] = 1;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[j][i] && !visited[j][i]) {
                    dfs(j, i);
                    cnt++;
                } else
                    continue;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}