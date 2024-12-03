#include <iostream>
#include <queue>

using namespace std;

constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};

constexpr int INF = 987654321;

int X, Y, N;
int BOARD[1001][1001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> X >> Y >> N;
    X += 500, Y += 500;
    for (int i = 0; i < N; i++) {
        int tx, ty;
        cin >> tx >> ty;
        BOARD[tx + 500][ty + 500] = INF;
    }
    BOARD[500][500] = 1;
}

void solve() {
    queue<pair<int, int>> q;
    q.push({500, 500});

    while (q.size()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (nx < 0 || nx >= 1000 || ny < 0 || ny >= 1000 || BOARD[nx][ny])
                continue;
            if (nx == X && ny == Y) {
                cout << BOARD[cx][cy];
                return;
            }
            BOARD[nx][ny] = BOARD[cx][cy] + 1;
            q.push({nx, ny});
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}