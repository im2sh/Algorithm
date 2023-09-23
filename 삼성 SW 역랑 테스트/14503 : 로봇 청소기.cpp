#include <iostream>

using namespace std;

int N, M, ret;
int board[51][51];
pair<pair<int, int>, int> robot;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b, c;
    cin >> N >> M;
    cin >> a >> b >> c;
    robot.first = {a, b};
    robot.second = c;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> board[y][x];
        }
    }
}

void solve() {
    while (1) {
        int cy = robot.first.first;
        int cx = robot.first.second;

        bool flag = true;
        if (board[cy][cx] == 0) {
            board[cy][cx] = -1;
            ret++;
        }

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            if (board[ny][nx] == 0)
                flag = false;
        }

        if (flag) {
            int dir = (robot.second + 2) % 4;
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                return;
            if (board[ny][nx] != 1) {
                robot.first.first = ny;
                robot.first.second = nx;
                continue;
            }
            break;
        }

        int dir = (robot.second + 3) % 4;

        int ny = cy + dy[dir];
        int nx = cx + dx[dir];

        if (board[ny][nx] == 0) {
            robot.first.first = ny;
            robot.first.second = nx;
        }
        robot.second = dir;
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    cout << ret << "\n";
    return 0;
}