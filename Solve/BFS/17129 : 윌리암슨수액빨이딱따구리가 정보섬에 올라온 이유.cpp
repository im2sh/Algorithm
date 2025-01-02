#include <iostream>
#include <queue>

using namespace std;

constexpr int dy[4] = {-1, 1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};

int N, M;
int BOARD[3001][3001];
queue<pair<pair<int, int>, int>> q;
bool visited[3001][3001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        string temp;
        cin >> temp;
        for (int x = 0; x < M; x++) {
            BOARD[y][x] = temp[x] - '0';
            if (BOARD[y][x] == 2) {
                q.push({{y, x}, 0});
                visited[y][x] = true;
            }
        }
    }
}

void solve() {
    while (q.size()) {
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        if (BOARD[cy][cx] == 3 || BOARD[cy][cx] == 4 || BOARD[cy][cx] == 5) {
            cout << "TAK\n";
            cout << depth;
            return;
        }

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || BOARD[ny][nx] == 1)
                continue;

            q.push({{ny, nx}, depth + 1});
            visited[ny][nx] = true;
        }
    }
    cout << "NIE";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}