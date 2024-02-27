#include <iostream>
#include <queue>

using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int N, ret;
int BOARD[126][126];
int visited[126][126];


void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    fill(&visited[0][0], &visited[0][0] + 126 * 126, 987654321);
    fill(&BOARD[0][0], &BOARD[0][0] + 126 * 126, 0);
    ret = 0;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> BOARD[y][x];
        }
    }
}

void display() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << visited[y][x] << ' ';
        }
        cout << '\n';
    }
}

void BFS() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = BOARD[0][0];
    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;
            if (visited[ny][nx] > visited[cy][cx] + BOARD[ny][nx]) {
                q.push({ny, nx});
                visited[ny][nx] = visited[cy][cx] + BOARD[ny][nx];
            }
        }
    }
}

void solve() {
    int idx = 1;
    while (true) {
        cin >> N;
        if (N == 0)
            break;
        Init();
        BFS();
        cout << "Problem " << idx++ << ": " << visited[N - 1][N - 1] << '\n';
    }
}

int main(void) {
    FastIO();
    solve();
    return 0;
}