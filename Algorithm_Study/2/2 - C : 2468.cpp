#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N 101

int arr[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
vector<int> height;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int nx, ny, N, limit;

void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
            continue;
        if (arr[ny][nx] <= limit)
            continue;
        if (!visited[ny][nx] && arr[ny][nx])
            dfs(ny, nx);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt = 0;
    int max_n = 0;
    int max_cnt = 0;

    fill(&arr[0][0], &arr[0][0] + MAX_N * MAX_N, 0);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
            if (max_n < arr[i][j])
                max_n = arr[i][j];
        }
    }

    for (int k = 0; k < max_n; k++) {
        fill(&visited[0][0], &visited[0][0] + MAX_N * MAX_N, 0);
        cnt = 0;
        limit = k;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[j][i] && arr[j][i] > limit) {
                    dfs(j, i);
                    cnt++;
                }

            }
        }
        height.push_back(cnt);
    }
    if (cnt != 0)
        max_cnt = *max_element(height.begin(), height.end());
    cout << max_cnt << "\n";
    return 0;
}