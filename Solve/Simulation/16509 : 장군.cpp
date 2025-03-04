#include <iostream>
#include <queue>

using namespace std;

constexpr int dy[8][3] = {{-1, -1, -1},
                          {-1, -1, -1},
                          {0,  -1, -1},
                          {0,  1,  1},
                          {1,  1,  1},
                          {1,  1,  1},
                          {0,  1,  1},
                          {0,  -1, -1}};

constexpr int dx[8][3] = {{0,  -1, -1},
                          {0,  1,  1},
                          {1,  1,  1},
                          {1,  1,  1},
                          {0,  1,  1},
                          {0,  -1, -1},
                          {-1, -1, -1},
                          {-1, -1, -1}};

int R1, C1, R2, C2;
int BOARD[10][10];
int visited[10][10];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> R1 >> C1;
    cin >> R2 >> C2;
}

void solve() {
    queue<pair<int, int>> q;
    q.push({R1, C1});
    visited[R1][C1] = 1;

    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        if (cy == R2 && cx == C2) {
            cout << visited[cy][cx] - 1;
            return;
        }

        for (int dir = 0; dir < 8; dir++) {
            int ty = cy;
            int tx = cx;
            bool flag = false;
            for (int i = 0; i < 3; i++) {
                int ny = ty + dy[dir][i];
                int nx = tx + dx[dir][i];

                if (ny < 0 || ny > 9 || nx < 0 || nx > 8) {
                    flag = true;
                    break;
                }

                if (ny == R2 && nx == C2 && i != 2) {
                    flag = true;
                    break;
                }
                ty = ny;
                tx = nx;
            }
            if (!flag) {
                q.push({ty, tx});
                visited[ty][tx] = visited[cy][cx] + 1;
            }
        }
    }
    cout << "-1";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}