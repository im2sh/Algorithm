#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int N, M, T, ret;
pair<int, int> sword;
int sword_visited;
bool isExistsSword = false;
bool canGetSword = false;
int BOARD[101][101];
int visited[101][101];
queue<pair<int, int>> q;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> T;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> BOARD[y][x];
            if (BOARD[y][x] == 2)
                sword = {y, x};
        }
    }
}

void BFS(int y, int x) {
    q.push({y, x});
    if (isExistsSword == true)
        visited[y][x] = sword_visited;
    else
        visited[y][x] = 1;

    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
                continue;
            if (isExistsSword == false) {
                if (BOARD[ny][nx] == 1)
                    continue;
                if (BOARD[ny][nx] == 2) {
                    canGetSword = true;
                    sword_visited = visited[cy][cx] + 1;
                }
                q.push({ny, nx});
                visited[ny][nx] = visited[cy][cx] + 1;
            } else {
                q.push({ny, nx});
                visited[ny][nx] = visited[cy][cx] + 1;
            }
        }
    }
}


void solve() {
    BFS(0, 0);
    ret = visited[N - 1][M - 1] - 1;
    if (ret == -1)
        ret = 987654321;
    if (canGetSword) {
        isExistsSword = true;
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        BFS(sword.first, sword.second);
    }

    ret = min(ret, visited[N - 1][M - 1] - 1);
    if (ret <= T && ret != -1) {
        cout << ret;
    } else
        cout << "Fail";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}