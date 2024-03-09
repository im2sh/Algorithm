#include <iostream>
#include <queue>

using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
int N, M, ret = 0;
string BOARD[601];
bool visited[601][601];
pair<int, int> start;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        BOARD[i] = temp;
        for (int j = 0; j < M; j++) {
            if (BOARD[i][j] == 'I')
                start = {i, j};
        }
    }
}

void bfs() {
    queue<pair<int, int>> q;
    q.push({start.first, start.second});
    visited[start.first][start.second] = true;

    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        if (BOARD[cy][cx] == 'P')
            ret++;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || BOARD[ny][nx] == 'X')
                continue;
            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }

}

void solve() {
    bfs();

    if (ret == 0)
        cout << "TT";
    else
        cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}