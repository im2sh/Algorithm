#include <iostream>
#include <cmath>

using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};
int N, M;
int B, W, sum;
char BOARD[101][101];
bool visited[101][101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> M >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> BOARD[y][x];
        }
    }
}

void dfs(int y, int x, char c) {
    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
            continue;
        if (BOARD[ny][nx] == c) {
            sum++;
            visited[ny][nx] = true;
            dfs(ny, nx, c);
        }
    }
}

void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (!visited[y][x]) {
                sum = 1;
                visited[y][x] = true;
                dfs(y, x, BOARD[y][x]);
                if (BOARD[y][x] == 'W') {
                    W += pow(sum, 2);
                } else {
                    B += pow(sum, 2);
                }
            }
        }
    }
    cout << W << ' ' << B;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}