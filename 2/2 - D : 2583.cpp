#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 101
using namespace std;

int arr[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};

int M, N, K, nx, ny;
int x1, x2, y1, y2;
int cnt = 0;


void dfs(int y, int x) {
    cnt++;
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];

        if (ny < 0 || ny >= M || nx < 0 || nx >= N || arr[ny][nx])
            continue;
        if (!visited[ny][nx] && !arr[ny][nx])
            dfs(ny, nx);
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> space;
    cin >> M >> N >> K;
    fill(&arr[0][0], &arr[0][0] + MAX_N * MAX_N, 0);
    fill(&visited[0][0], &visited[0][0] + MAX_N * MAX_N, 0);
    for (int i = 0; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                arr[y][x] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cnt = 0;
            if (!arr[j][i] && !visited[j][i]) {
                dfs(j, i);
            }
            if (cnt != 0)
                space.push_back(cnt);
        }
    }
    sort(space.begin(), space.end());
    cout << space.size() << "\n";
    for (int i = 0; i < space.size(); i++) {
        cout << space[i] << " ";
    }
    return 0;
}