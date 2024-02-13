#include <iostream>
#include <queue>

using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int ret;
int visited[25];
int BOARD[5][5];
int check_visited[5][5]; // 7명에 대한 체크
int bfs_visited[5][5]; // bfs를 위한 체크


void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp;
    for (int i = 0; i < 5; i++) {
        cin >> temp;
        for (int j = 0; j < 5; j++) {
            if (temp[j] == 'Y') {
                BOARD[i][j] = 1;
            } else {
                BOARD[i][j] = 2;
            }
        }
    }
}

bool isDasom() {
    int cnt = 0;
    for (int i = 0; i < 25; i++) {
        if (visited[i]) {
            int y = i / 5;
            int x = i % 5;
            if (BOARD[y][x] == 2)
                cnt++;
        }
    }
    if (cnt >= 4)
        return true;
    return false;
}

bool checkNear() {
    queue<pair<int, int>> q;

    fill(&check_visited[0][0], &check_visited[0][0] + 5 * 5, 0);
    fill(&bfs_visited[0][0], &bfs_visited[0][0] + 5 * 5, 0);

    int cnt = 1;
    int temp = 0;
    for (int i = 0; i < 25; i++) {
        if (visited[i]) {
            int y = i / 5;
            int x = i % 5;

            check_visited[y][x] = 1;

            if (temp == 0) {
                bfs_visited[y][x] = 1;
                q.push({y, x});
                temp++;
            }
        }
    }

    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        if (cnt == 7) {
            return true;
        }

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5 || !check_visited[ny][nx] || bfs_visited[ny][nx])
                continue;
            bfs_visited[ny][nx] = 1;
            q.push({ny, nx});
            cnt++;
        }
    }

    return false;
}

void dfs(int idx, int depth) {
    if (depth == 7) {
        if (isDasom()) {
            if (checkNear()) {
                ret++;
            }
        }
        return;
    }

    for (int i = idx; i < 25; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(i, depth + 1);
            visited[i] = 0;
        }
    }
}

void solve() {
    dfs(0, 0);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}