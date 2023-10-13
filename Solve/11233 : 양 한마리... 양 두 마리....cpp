#include <iostream>
#include <queue>

using namespace std;

int T, H, W;
int BOARD[101][101];
int visited[101][101];
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dx[dir];
            int nx = cx + dy[dir];

            if (ny < 0 || ny >= H || nx < 0 || nx >= W || visited[ny][nx] || BOARD[ny][nx] == 0)
                continue;

            q.push({ny, nx});
            visited[ny][nx] = 1;


        }
    }
}

void Init() {
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            BOARD[y][x] = 0;
            visited[y][x] = 0;
        }
    }
}

int main() {
    cin >> T;

    while (T--) {
        int ret = 0;
        cin >> H >> W;
        Init();
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                char temp;
                cin >> temp;
                if (temp == '.') {
                    BOARD[y][x] = 0;
                } else {
                    BOARD[y][x] = 1;
                }
            }
        }

        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                if (BOARD[y][x] && !visited[y][x]) {
                    bfs(y, x);
                    ret++;
                }
            }
        }

        cout << ret << "\n";
    }
    return 0;
}