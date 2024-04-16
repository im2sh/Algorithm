#include <iostream>


using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int N, M, ret;
int BOARD[1001][1001];
int visited[1001][1001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++) {
            if (temp[j] == 'U')
                BOARD[i][j] = 0;
            else if (temp[j] == 'D')
                BOARD[i][j] = 1;
            else if (temp[j] == 'L')
                BOARD[i][j] = 2;
            else
                BOARD[i][j] = 3;
        }
    }
}

void dfs(int y, int x) {
    visited[y][x] = 1;
    int dir = BOARD[y][x];
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if (visited[ny][nx] == 1)
        ret++;
    else if (visited[ny][nx] == 0)
        dfs(ny, nx);
    visited[y][x] = 2;
}

void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (!visited[y][x]) {
                dfs(y, x);
            }
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}