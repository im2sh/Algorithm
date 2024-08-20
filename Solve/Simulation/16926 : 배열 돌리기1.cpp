#include <iostream>

using namespace std;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};

int N, M, R;
int BOARD[301][301];
int COPY_BOARD[301][301];
bool visited[301][301];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> R;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> BOARD[y][x];
        }
    }
}

void display() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cout << COPY_BOARD[y][x] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void go(int y, int x) {
    int dir = 0;
    while (true) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) {
            dir = (dir + 1) % 4;
            ny = y + dy[dir];
            nx = x + dx[dir];
        }
        if (visited[ny][nx])
            break;
        COPY_BOARD[ny][nx] = BOARD[y][x];
        y = ny;
        x = nx;
        visited[ny][nx] = true;
    }
}

void solve() {
    for (int r = 0; r < R; r++) {
        fill(&visited[0][0], &visited[0][0] + 301 * 301, 0);
        fill(&COPY_BOARD[0][0], &COPY_BOARD[0][0] + 301 * 301, 0);
        for (int i = 0; i < N; i++) {
            if (visited[i][i] || !BOARD[i][i])
                break;
            go(i, i);
        }
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                BOARD[y][x] = COPY_BOARD[y][x];
            }
        }
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cout << BOARD[y][x] << ' ';
        }
        cout << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}