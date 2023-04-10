#include <iostream>
#include <algorithm>
#include <vector>

#define SIZE 101

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

using namespace std;
vector<pair<int, int>> cheeze;
int N, M;
int arr[SIZE][SIZE];
int visited[SIZE][SIZE];
int cnt;
int trycnt;

void dfs(int y, int x) {
    visited[y][x] = 1;
    if (arr[y][x]) {
        cheeze.push_back({y, x});
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        else if (visited[ny][nx])
            continue;
        dfs(ny, nx);
    }
}

bool checkArr() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 1)
                return false;
        }
    }
    return true;
}

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    while (1) {
        fill(&visited[0][0], &visited[0][0] + SIZE * SIZE, 0);
        cheeze.clear();
        trycnt++;
        dfs(0, 0);
        cnt = 0;
        for (auto &it: cheeze) {
            arr[it.first][it.second] = 0;
            cnt++;
        }

        if (checkArr()) {
            break;
        }
    }
    cout << trycnt << "\n" << cnt << "\n";
    return 0;
}
