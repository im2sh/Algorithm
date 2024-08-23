#include <iostream>
#include <queue>

using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int N;
int BOARD[51][51];
int visited[51][51];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int y = 0; y < N; y++) {
        string temp;
        cin >> temp;
        for (int x = 0; x < N; x++) {
            BOARD[y][x] = temp[x] - '0';
        }
    }
    fill(&visited[0][0], &visited[0][0] + 51 * 51, 987654321);
}

void solve() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 0;

    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;
            if (BOARD[ny][nx] == 1) {
                if (visited[cy][cx] < visited[ny][nx]) {
                    visited[ny][nx] = visited[cy][cx];
                    q.push({ny, nx});
                }
            } else {
                if (visited[ny][nx] > visited[cy][cx] + 1) {
                    visited[ny][nx] = visited[cy][cx] + 1;
                    q.push({ny, nx});
                }
            }
        }
    }
    cout << visited[N - 1][N - 1];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
