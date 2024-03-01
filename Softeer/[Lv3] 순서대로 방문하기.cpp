#include <iostream>
#include <vector>

using namespace std;
int N, M, ret = 0;
int BOARD[5][5];
vector<pair<int, int>> dest;
vector<pair<int, int>> path;
const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {1, -1, 0, 0};
int visited[5][5];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b;
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> BOARD[y][x];
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        dest.push_back({a - 1, b - 1});
        BOARD[a - 1][b - 1] = 2;
    }
}

void dfs(int y, int x) {
    if (y == dest[M - 1].first && x == dest[M - 1].second) {
        int idx = 0;
        bool flag = true;
        for (int i = 1; i < M; i++) {
            if (dest[i].first == path[idx].first && dest[i].second == path[idx].second) {
                idx++;
                continue;
            }
            flag = false;
        }
        if (flag)
            ret++;
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N || BOARD[ny][nx] == 1 || visited[ny][nx])
            continue;

        visited[ny][nx] = 1;
        if (BOARD[ny][nx] == 2)
            path.push_back({ny, nx});

        dfs(ny, nx);

        if (BOARD[ny][nx] == 2)
            path.pop_back();
        visited[ny][nx] = 0;
    }
}

void solve() {
    dfs(dest[0].first, dest[0].second);
    cout << ret;
}

int main(int argc, char **argv) {
    FastIO();
    Init();
    solve();
    return 0;
}